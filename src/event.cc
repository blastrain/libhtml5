#include "event_target.h"
#include "event.h"

Event::Event(emscripten::val v) :
    v(v)
{

}

Event::~Event()
{

}

Event *Event::create(std::string type)
{
    emscripten::val _Event = emscripten::val::global("Event");
    emscripten::val v = _Event.new_(emscripten::val(type));
    Event *event = new Event(v);
    event->autorelease();
    return event;
}

Event *Event::create(emscripten::val v)
{
    Event *event = new Event(v);
    event->autorelease();
    return event;
}

void Event::initEvent(std::string type, bool bubbles, bool cancelable)
{
    this->v.call<void>("initEvent",
                       emscripten::val(type),
                       emscripten::val(bubbles),
                       emscripten::val(cancelable));
}

void Event::preventDefault()
{
    this->v.call<void>("preventDefault");
}

void Event::stopImmediatePropagation()
{
    this->v.call<void>("stopImmediatePropagation");
}

void Event::stopPropagation()
{
    this->v.call<void>("stopPropagation");
}

void Event::setBubbles(bool value)
{
    this->_bubbles = value;
    this->v.set("bubbles", value);
}

bool Event::getBubbles()
{
    return this->v["bubbles"].as<bool>();
}

void Event::setCancelable(bool value)
{
    this->_cancelable = value;
    this->v.set("cancelable", value);
}

bool Event::getCancelable()
{
    return this->v["cancelable"].as<bool>();
}

void Event::setCurrentTarget(EventTarget *value)
{
    this->_currentTarget = value;
    this->v.set("currentTarget", value->v);
}

EventTarget *Event::getCurrentTarget()
{
    return EventTarget::create(this->v["currentTarget"]);
}

void Event::setDefaultPrevented(bool value)
{
    this->_defaultPrevented = value;
    this->v.set("defaultPrevented", value);
}

bool Event::getDefaultPrevented()
{
    return this->v["defaultPrevented"].as<bool>();
}

void Event::setEventPhase(unsigned short value)
{
    this->_eventPhase = value;
    this->v.set("eventPhase", value);
}

unsigned short Event::getEventPhase()
{
    return this->v["eventPhase"].as<unsigned short>();
}

void Event::setIsTrusted(bool value)
{
    this->_isTrusted = value;
    this->v.set("isTrusted", value);
}

bool Event::getIsTrusted()
{
    return this->v["isTrusted"].as<bool>();
}

void Event::setTarget(EventTarget *value)
{
    this->_target = value;
    this->v.set("target", value->v);
}

EventTarget *Event::getTarget()
{
    return EventTarget::create(this->v["target"]);
}

void Event::setType(std::string value)
{
    this->_type = value;
    this->v.set("type", value);
}

std::string Event::getType()
{
    return this->v["type"].as<std::string>();
}

void Event::setTimeStamp(time_t value)
{
    this->_timeStamp = value;
    this->v.set("timeStamp", value);
}

time_t Event::getTimeStamp()
{
    return this->v["timeStamp"].as<time_t>();
}
