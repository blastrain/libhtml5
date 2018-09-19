#include "video_track.h"
#include "video_track_list.h"
#include "event.h"
#include "event_handler.h"

USING_NAMESPACE_HTML5;

HTML5_BIND_CLASS(VideoTrackList);

VideoTrackList::VideoTrackList(emscripten::val v) :
    EventTarget(v)
{

}

VideoTrackList::~VideoTrackList()
{

}

VideoTrackList *VideoTrackList::create(emscripten::val v)
{
    VideoTrackList *trackList = new VideoTrackList(v);
    trackList->autorelease();
    return trackList;
}

VideoTrack *VideoTrackList::getter(unsigned long index)
{
    return VideoTrack::create(HTML5_CALLv(this->v, getter, index));
}

VideoTrack *VideoTrackList::getTrackById(std::string id)
{
    return VideoTrack::create(HTML5_CALLv(this->v, getTrackById, id));
}

HTML5_PROPERTY_IMPL(VideoTrackList, unsigned long, length);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(VideoTrackList, EventHandler *, onaddtrack);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(VideoTrackList, EventHandler *, onchange);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(VideoTrackList, EventHandler *, onremovetrack);
HTML5_PROPERTY_IMPL(VideoTrackList, long, selectedIndex);
