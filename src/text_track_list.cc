#include "text_track.h"
#include "text_track_list.h"
#include "event.h"
#include "event_handler.h"

HTML5_BIND_CLASS(TextTrackList);

TextTrackList::TextTrackList(emscripten::val v) :
    EventTarget(v)
{

}

TextTrackList::~TextTrackList()
{

}

TextTrackList *TextTrackList::create(emscripten::val v)
{
    TextTrackList *trackList = new TextTrackList(v);
    trackList->autorelease();
    return trackList;
}

TextTrack *TextTrackList::getter(unsigned long index)
{
    return TextTrack::create(HTML5_CALLv(this->v, getter, index));
}

TextTrack *TextTrackList::getTrackById(std::string id)
{
    return TextTrack::create(HTML5_CALLv(this->v, getTrackById, id));
}

HTML5_PROPERTY_IMPL(TextTrackList, unsigned long, length);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(TextTrackList, EventHandler *, onaddtrack);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(TextTrackList, EventHandler *, onchange);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(TextTrackList, EventHandler *, onremovetrack);
