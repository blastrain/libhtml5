#include "event.h"
#include "event_target.h"
#include <iostream>
#include <emscripten/emscripten.h>

EventTarget::EventTarget(emscripten::val v) : v(v)
{

}

EventTarget::~EventTarget()
{

}

EventTarget *EventTarget::create(emscripten::val v)
{
    return new EventTarget(v);
}

bool EventTarget::dispatchEvent(Event *event)
{
    return this->v.call<bool>("dispatchEvent", event->v);
}

void EventTarget::addEventListener(std::string type, EventHandler *handler, bool capture)
{
    if (!handler) return;

    this->handlers[type].push_back(handler);
    EM_ASM_({
        const eventTarget = Module.toEventTarget($0);
        const type = Module.toString($1);
        const capture = $2;
        eventTarget._value.addEventListener(type, function(e) { eventTarget.addEventHandlerCallback(e); }, capture);
    }, this, type.c_str(), capture);
}

void EventTarget::addEventListener(std::string type, EventListener *listener, bool capture)
{
    if (!listener) return;

    this->listeners[type].push_back(listener);
    EM_ASM_({
        const eventTarget = Module.toEventTarget($0);
        const type = Module.toString($1);
        const capture = $2;
        eventTarget._value.addEventListener(type, function(e) { eventTarget.addEventListenerCallback(e); }, capture);
    }, this, type.c_str(), capture);
}

void EventTarget::addEventHandlerCallback(emscripten::val v)
{
    std::string type = v["type"].as<std::string>();
    Event *event = Event::create(v);
    for (EventHandler *callback : this->handlers[type]) {
        (*callback)(event);
    }
}

void EventTarget::addEventListenerCallback(emscripten::val v)
{
    std::string type = v["type"].as<std::string>();
    Event *event = Event::create(v);
    for (EventListener *listener : this->listeners[type]) {
        listener->handleEvent(event);
    }
}

void EventTarget::removeEventListener(std::string type, EventHandler *handler, bool capture)
{
    std::vector<EventHandler *> removedCallbacks;
    for (EventHandler *cb : this->handlers[type]) {
        if (cb != handler) {
            removedCallbacks.push_back(cb);
        }
    }
    this->handlers[type] = removedCallbacks;
}

void EventTarget::removeEventListener(std::string type, EventListener *listener, bool capture)
{
    std::vector<EventListener *> removedCallbacks;
    for (EventListener *cb : this->listeners[type]) {
        if (cb != listener) {
            removedCallbacks.push_back(cb);
        }
    }
    this->listeners[type] = removedCallbacks;
}
