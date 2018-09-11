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
    auto list = new TextTrackCueList(v);
    list->autorelease();
    return list;
}

TextTrackCue *TextTrackCueList::getCueById(std::string id)
{
    return TextTrackCue::create(HTML5_CALLv(this->v, getCueById, id));
}

TextTrackCue *TextTrackCueList::getter(unsigned long index)
{
    return TextTrackCue::create(HTML5_CALLv(this->v, getter, index));
}

unsigned long TextTrackCueList::getLength() const
{
    return HTML5_PROPERTY_GET(length, unsigned long);
}

void TextTrackCueList::setLength(unsigned long value)
{
    this->_length = value;
    this->v.set("length", value);
}
