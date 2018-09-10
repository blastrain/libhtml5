#include "audio_track.h"
#include "audio_track_list.h"
#include "event.h"
#include "event_handler.h"
#include <emscripten/emscripten.h>

AudioTrackList::AudioTrackList(emscripten::val v) :
    EventTarget(v)
{

}

AudioTrackList::~AudioTrackList()
{

}

AudioTrackList *AudioTrackList::create(emscripten::val v)
{
    return new AudioTrackList(v);
}

emscripten::val AudioTrackList::getValue() const
{
    return this->v;
}

AudioTrack *AudioTrackList::getter(unsigned long index)
{
    return AudioTrack::create(this->v.call<emscripten::val>("getter", index));
}

AudioTrack *AudioTrackList::getTrackById(std::string id)
{
    return AudioTrack::create(this->v.call<emscripten::val>("getTrackById", id));
}

unsigned long AudioTrackList::getLength() const
{
    return this->v["length"].as<unsigned long>();
}

void AudioTrackList::setLength(unsigned long value)
{
    this->_length = value;
    this->v.set("length", value);
}

EventHandler *AudioTrackList::getOnAddTrack() const
{
    return this->_onaddtrack;
}

void AudioTrackList::setOnAddTrack(EventHandler *value)
{
    this->_onaddtrack = value;
    EM_ASM_({
        const track = Module.toAudioTrackList($0);
        track._value.onaddtrack = function(e) { track.onAddTrackCallback(e); };
    }, this);
}

void AudioTrackList::onAddTrackCallback(emscripten::val e)
{
    if (!this->_onaddtrack) return;

    (*this->_onaddtrack)(Event::create(e));
}

EventHandler *AudioTrackList::getOnChange() const
{
    return this->_onchange;
}

void AudioTrackList::setOnChange(EventHandler *value)
{
    this->_onchange = value;
    EM_ASM_({
        const track = Module.toAudioTrackList($0);
        track._value.onchange = function(e) { track.onChangeCallback(e); };
    }, this);
}

void AudioTrackList::onChangeCallback(emscripten::val e)
{
    if (!this->_onchange) return;

    (*this->_onchange)(Event::create(e));
}

EventHandler *AudioTrackList::getOnRemoveTrack() const
{
    return this->_onremovetrack;
}

void AudioTrackList::setOnRemoveTrack(EventHandler *value)
{
    this->_onremovetrack = value;
    EM_ASM_({
        const track = Module.toAudioTrackList($0);
        track._value.onremovetrack = function(e) { track.onRemoveTrackCallback(e); };
    }, this);
}

void AudioTrackList::onRemoveTrackCallback(emscripten::val e)
{
    if (!this->_onremovetrack) return;

    (*this->_onremovetrack)(Event::create(e));
}
