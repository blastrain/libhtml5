#pragma once

#include "event_target.h"
#include "event_handler.h"
#include <string>

class TextTrack;

class TextTrackCue : public EventTarget {
public:

    HTML5_PROPERTY(TextTrackCue, double, endTime);
    HTML5_PROPERTY(TextTrackCue, std::string, id);
    HTML5_EVENT_HANDLER_PROPERTY(TextTrackCue, EventHandler *, onenter);
    HTML5_EVENT_HANDLER_PROPERTY(TextTrackCue, EventHandler *, onexit);
    HTML5_PROPERTY(TextTrackCue, bool, pauseOnExit);
    HTML5_PROPERTY(TextTrackCue, double, startTime);
    HTML5_PROPERTY_OBJECT(TextTrackCue, TextTrack, track);

    TextTrackCue(emscripten::val v);
    virtual ~TextTrackCue();
    static TextTrackCue *create(emscripten::val v);
};
