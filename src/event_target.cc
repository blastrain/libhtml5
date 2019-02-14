#include "event.h"
#include "event_target.h"
#include <iostream>

USING_NAMESPACE_HTML5;

HTML5_BIND_CLASS(EventTarget);
HTML5_BIND_METHOD(EventTarget, addEventHandlerCallback);
HTML5_BIND_METHOD(EventTarget, addEventListenerCallback);

EventTarget::EventTarget(emscripten::val v) :
    Object(v)
{

}

EventTarget::~EventTarget()
{

}

EventTarget *EventTarget::create(emscripten::val v)
{
    EventTarget *et = new EventTarget(v);
    et->autorelease();
    return et;
}

bool EventTarget::dispatchEvent(Event *event)
{
    return HTML5_CALLb(this->v, dispatchEvent, event->v);
}

void EventTarget::addEventListener(std::string type, EventHandler *handler, bool capture)
{
    if (!handler) return;

    this->handlers[type].push_back(handler);
    EM_ASM_({
        var eventTarget = Module['toEventTarget']($0);
        var type = Module['toString']($1);
        var capture = $2;
        eventTarget['_value']['addEventListener'](type, function(e) { eventTarget['addEventHandlerCallback'](e); }, capture);
    }, this, type.c_str(), capture);
}

void EventTarget::addEventListener(std::string type, EventListener *listener, bool capture)
{
    if (!listener) return;

    this->listeners[type].push_back(listener);
    EM_ASM_({
        var eventTarget = Module['toEventTarget']($0);
        var type = Module['toString']($1);
        var capture = $2;
        eventTarget['_value']['addEventListener'](type, function(e) { eventTarget['addEventListenerCallback'](e); }, capture);
    }, this, type.c_str(), capture);
}

void EventTarget::addEventHandlerCallback(emscripten::val v)
{
#if ENABLE_EMSCRIPTEN
    std::string type = v["type"].as<std::string>();
    Event *event = Event::create(v);
    for (EventHandler *callback : this->handlers[type]) {
        (*callback)(event);
    }
#endif
}

void EventTarget::addEventListenerCallback(emscripten::val v)
{
#if ENABLE_EMSCRIPTEN
    std::string type = v["type"].as<std::string>();
    Event *event = Event::create(v);
    for (EventListener *listener : this->listeners[type]) {
        listener->handleEvent(event);
    }
#endif
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
