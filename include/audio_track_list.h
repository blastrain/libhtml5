#pragma once

#include "event_target.h"
#include "event_handler.h"

class AudioTrack;

class AudioTrackList : public EventTarget {
public:

    HTML5_PROPERTY(AudioTrackList, unsigned long, length);
    HTML5_EVENT_HANDLER_PROPERTY(AudioTrackList, EventHandler *, onaddtrack);
    HTML5_EVENT_HANDLER_PROPERTY(AudioTrackList, EventHandler *, onchange);
    HTML5_EVENT_HANDLER_PROPERTY(AudioTrackList, EventHandler *, onremovetrack);

    AudioTrackList(emscripten::val v);
    virtual ~AudioTrackList();
    static AudioTrackList *create(emscripten::val v);
    AudioTrack *getter(unsigned long index);
    AudioTrack *getTrackById(std::string id);
};
