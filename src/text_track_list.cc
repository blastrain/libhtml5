#include "text_track.h"
#include "text_track_list.h"
#include "event.h"
#include "event_handler.h"
#include <emscripten/emscripten.h>

TextTrackList::TextTrackList(emscripten::val v) :
    EventTarget(v)
{

}

TextTrackList::~TextTrackList()
{

}

TextTrackList *TextTrackList::create(emscripten::val v)
{
    return new TextTrackList(v);
}

emscripten::val TextTrackList::getValue() const
{
    return this->v;
}

TextTrack *TextTrackList::getter(unsigned long index)
{
    return TextTrack::create(this->v.call<emscripten::val>("getter", index));
}

TextTrack *TextTrackList::getTrackById(std::string id)
{
    return TextTrack::create(this->v.call<emscripten::val>("getTrackById", id));
}

unsigned long TextTrackList::getLength() const
{
    return this->v["length"].as<unsigned long>();
}

void TextTrackList::setLength(unsigned long value)
{
    this->_length = value;
    this->v.set("length", value);
}

EventHandler *TextTrackList::getOnAddTrack() const
{
    return this->_onaddtrack;
}

void TextTrackList::setOnAddTrack(EventHandler *value)
{
    this->_onaddtrack = value;
    EM_ASM_({
        const track = Module.toTextTrack($0);
        track._value.onaddtrack = function(e) { track.onAddTrackCallback(e); };
    }, this);
}

void TextTrackList::onAddTrackCallback(emscripten::val e)
{
    if (!this->_onaddtrack) return;

    (*this->_onaddtrack)(Event::create(e));
}

EventHandler *TextTrackList::getOnChange() const
{
    return this->_onchange;
}

void TextTrackList::setOnChange(EventHandler *value)
{
    this->_onchange = value;
    EM_ASM_({
        const track = Module.toTextTrack($0);
        track._value.onchange = function(e) { track.onChangeCallback(e); };
    }, this);
}

void TextTrackList::onChangeCallback(emscripten::val e)
{
    if (!this->_onchange) return;

    (*this->_onchange)(Event::create(e));
}

EventHandler *TextTrackList::getOnRemoveTrack() const
{
    return this->_onremovetrack;
}

void TextTrackList::setOnRemoveTrack(EventHandler *value)
{
    this->_onremovetrack = value;
    EM_ASM_({
        const track = Module.toTextTrack($0);
        track._value.onremovetrack = function(e) { track.onRemoveTrackCallback(e); };
    }, this);
}

void TextTrackList::onRemoveTrackCallback(emscripten::val e)
{
    if (!this->_onremovetrack) return;

    (*this->_onremovetrack)(Event::create(e));
}
