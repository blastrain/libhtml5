#include "text_track_cue.h"
#include "text_track_cue_list.h"

USING_NAMESPACE_HTML5;

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

HTML5_PROPERTY_IMPL(TextTrackCueList, unsigned long, length);
