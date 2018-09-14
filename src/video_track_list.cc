#include "video_track.h"
#include "video_track_list.h"
#include "event.h"
#include "event_handler.h"

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

emscripten::val VideoTrackList::getValue() const
{
    return this->v;
}

VideoTrack *VideoTrackList::getter(unsigned long index)
{
    return VideoTrack::create(HTML5_CALLv(this->v, getter, index));
}

VideoTrack *VideoTrackList::getTrackById(std::string id)
{
    return VideoTrack::create(HTML5_CALLv(this->v, getTrackById, id));
}

unsigned long VideoTrackList::getLength() const
{
    return HTML5_PROPERTY_GET(length, unsigned long);
}

void VideoTrackList::setLength(unsigned long value)
{
    this->_length = value;
    this->v.set("length", value);
}

EventHandler *VideoTrackList::getOnAddTrack() const
{
    return this->_onaddtrack;
}

void VideoTrackList::setOnAddTrack(EventHandler *value)
{
    this->_onaddtrack = value;
    EM_ASM_({
        const track = Module.toVideoTrackList($0);
        track._value.onaddtrack = function(e) { track.onAddTrackCallback(e); };
    }, this);
}

void VideoTrackList::onAddTrackCallback(emscripten::val e)
{
    if (!this->_onaddtrack) return;

    (*this->_onaddtrack)(Event::create(e));
}

EventHandler *VideoTrackList::getOnChange() const
{
    return this->_onchange;
}

void VideoTrackList::setOnChange(EventHandler *value)
{
    this->_onchange = value;
    EM_ASM_({
        const track = Module.toVideoTrackList($0);
        track._value.onchange = function(e) { track.onChangeCallback(e); };
    }, this);
}

void VideoTrackList::onChangeCallback(emscripten::val e)
{
    if (!this->_onchange) return;

    (*this->_onchange)(Event::create(e));
}

EventHandler *VideoTrackList::getOnRemoveTrack() const
{
    return this->_onremovetrack;
}

void VideoTrackList::setOnRemoveTrack(EventHandler *value)
{
    this->_onremovetrack = value;
    EM_ASM_({
        const track = Module.toVideoTrackList($0);
        track._value.onremovetrack = function(e) { track.onRemoveTrackCallback(e); };
    }, this);
}

void VideoTrackList::onRemoveTrackCallback(emscripten::val e)
{
    if (!this->_onremovetrack) return;

    (*this->_onremovetrack)(Event::create(e));
}

long VideoTrackList::getSelectedIndex() const
{
    return HTML5_PROPERTY_GET(selectedIndex, long);
}

void VideoTrackList::setSelectedIndex(long value)
{
    this->_selectedIndex = value;
    this->v.set("selectedIndex", value);
}