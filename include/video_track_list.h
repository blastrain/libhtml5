#pragma once

#include "event_target.h"

class VideoTrack;

class VideoTrackList : public EventTarget {
public:

    HTML5_PROPERTY(VideoTrackList, unsigned long, length);
    HTML5_EVENT_HANDLER_PROPERTY(VideoTrackList, EventHandler *, onaddtrack);
    HTML5_EVENT_HANDLER_PROPERTY(VideoTrackList, EventHandler *, onchange);
    HTML5_EVENT_HANDLER_PROPERTY(VideoTrackList, EventHandler *, onremovetrack);
    HTML5_PROPERTY(VideoTrackList, long, selectedIndex);

    VideoTrackList(emscripten::val v);
    virtual ~VideoTrackList();
    static VideoTrackList *create(emscripten::val v);
    VideoTrack *getter(unsigned long index);
    VideoTrack *getTrackById(std::string id);
};
