#pragma once

#include "html5.h"

#include <functional>
#include <map>
#include <vector>

#include "event_handler.h"
#include "event_listener.h"

NAMESPACE_HTML5_BEGIN;

class Event;

class EventTarget : public Object {
public:

    EventTarget(emscripten::val v);
    virtual ~EventTarget();
    static EventTarget *create(emscripten::val v);
    void addEventListener(std::string type, EventHandler *handler, bool capture = false);
    void addEventListener(std::string type, EventListener *listener, bool capture = false);
    bool dispatchEvent(Event *event);
    void removeEventListener(std::string type, EventHandler *handler, bool capture = false);
    void removeEventListener(std::string type, EventListener *listener, bool capture = false);
    void addEventListenerCallback(emscripten::val v);
    void addEventHandlerCallback(emscripten::val v);

private:
    std::map<std::string, std::vector<EventHandler *>> handlers;
    std::map<std::string, std::vector<EventListener *>> listeners;
};

NAMESPACE_HTML5_END;
