#include "text_track_cue.h"
#include "text_track_cue_list.h"

TextTrackCueList::TextTrackCueList(emscripten::val v) : v(v)
{

}

TextTrackCueList::~TextTrackCueList()
{

}

TextTrackCueList *TextTrackCueList::create(emscripten::val v)
{
    return new TextTrackCueList(v);
}

TextTrackCue *TextTrackCueList::getCueById(std::string id)
{
    return TextTrackCue::create(this->v.call<emscripten::val>("getCueById", id));
}

TextTrackCue *TextTrackCueList::getter(unsigned long index)
{
    return TextTrackCue::create(this->v.call<emscripten::val>("getter", index));
}

unsigned long TextTrackCueList::getLength() const
{
    return this->v["length"].as<unsigned long>();
}

void TextTrackCueList::setLength(unsigned long value)
{
    this->_length = value;
    this->v.set("length", value);
}
