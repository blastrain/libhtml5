#pragma once

#include <functional>
#include <string>
#include <emscripten/val.h>
#include <map>
#include <vector>

#include "object.h"
#include "event_handler.h"
#include "event_listener.h"

class Event;

class EventTarget : public Object {
public:
    emscripten::val v;

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
    emscripten::val getValue() const { return this->v; };

private:
    std::map<std::string, std::vector<EventHandler *>> handlers;
    std::map<std::string, std::vector<EventListener *>> listeners;
};
