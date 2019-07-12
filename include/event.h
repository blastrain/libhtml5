#pragma once

#include "html5.h"
#include <time.h>

NAMESPACE_HTML5_BEGIN;

class EventTarget;

class Event : public Object {
public:
    enum {
        NONE            = 0,
        CAPTURING_PHASE = 1,
        AT_TARGET       = 2,
        BUBBLING_PHASE  = 3,
    };

    HTML5_PROPERTY(Event, bool, bubbles);
    HTML5_PROPERTY(Event, bool, cancelable);
    HTML5_PROPERTY_OBJECT(Event, EventTarget, currentTarget);
    HTML5_PROPERTY(Event, bool, defaultPrevented);
    HTML5_PROPERTY(Event, unsigned short, eventPhase);
    HTML5_PROPERTY(Event, bool, isTrusted);
    HTML5_PROPERTY_OBJECT(Event, EventTarget, target);
    HTML5_PROPERTY(Event, std::string, type);
    HTML5_PROPERTY(Event, time_t, timeStamp);

    Event(emscripten::val v);
    virtual ~Event();
    static Event *create(std::string type);
    static Event *create(emscripten::val v);
    void initEvent(std::string type, bool bubbles, bool cancelable);
    void preventDefault();
    void stopImmediatePropagation();
    void stopPropagation();
};

NAMESPACE_HTML5_END;
