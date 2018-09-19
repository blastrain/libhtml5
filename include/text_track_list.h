#pragma once

#include "event_target.h"
#include "event_handler.h"

class TextTrack;

class TextTrackList : public EventTarget {
public:

    HTML5_PROPERTY(TextTrackList, unsigned long, length);
    HTML5_EVENT_HANDLER_PROPERTY(TextTrackList, EventHandler *, onaddtrack);
    HTML5_EVENT_HANDLER_PROPERTY(TextTrackList, EventHandler *, onchange);
    HTML5_EVENT_HANDLER_PROPERTY(TextTrackList, EventHandler *, onremovetrack);

    TextTrackList(emscripten::val v);
    virtual ~TextTrackList();
    static TextTrackList *create(emscripten::val v);
    TextTrack *getter(unsigned long index);
    TextTrack *getTrackById(std::string id);
};
