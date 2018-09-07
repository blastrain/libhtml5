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

void EventTarget::addEventListener(std::string type, std::function<void(Event*)> *callback, bool capture)
{
    this->listeners[type].push_back(callback);
    EM_ASM_({
        const eventTarget = Module.toEventTarget($0);
        const type = Module.toString($1);
        const capture = $2;
        eventTarget._value.addEventListener(type, function(e) { eventTarget.addEventListenerCallback(e); }, capture);
    }, this, type.c_str(), capture);
}

void EventTarget::addEventListenerCallback(emscripten::val v)
{
    std::string type = v["type"].as<std::string>();
    Event *event = Event::create(v);
    for (std::function<void(Event*)> *callback : this->listeners[type]) {
        (*callback)(event);
    }
}

void EventTarget::removeEventListener(std::string type, std::function<void(Event*)> *callback, bool capture)
{
    std::vector<std::function<void(Event*)> *> removedCallbacks;
    for (std::function<void(Event*)> *cb : this->listeners[type]) {
        if (cb != callback) {
            removedCallbacks.push_back(cb);
        }
    }
    this->listeners[type] = removedCallbacks;
}
