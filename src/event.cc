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
    Event *event = new Event(HTML5_NEW_PRIMITIVE_INSTANCE(Event));
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
    HTML5_CALL(this->v, initEvent, type, bubbles, cancelable);
}

void Event::preventDefault()
{
    HTML5_CALL(this->v, preventDefault);
}

void Event::stopImmediatePropagation()
{
    HTML5_CALL(this->v, stopImmediatePropagation);
}

void Event::stopPropagation()
{
    HTML5_CALL(this->v, stopPropagation);
}

void Event::setBubbles(bool value)
{
    this->_bubbles = value;
    this->v.set("bubbles", value);
}

bool Event::getBubbles()
{
    return HTML5_PROPERTY_GET(bubbles, bool);
}

void Event::setCancelable(bool value)
{
    this->_cancelable = value;
    this->v.set("cancelable", value);
}

bool Event::getCancelable()
{
    return HTML5_PROPERTY_GET(cancelable, bool);
}

void Event::setCurrentTarget(EventTarget *value)
{
    this->_currentTarget = value;
    this->v.set("currentTarget", value->v);
}

EventTarget *Event::getCurrentTarget()
{
    return HTML5_PROPERTY_GET(currentTarget, EventTarget);
}

void Event::setDefaultPrevented(bool value)
{
    this->_defaultPrevented = value;
    this->v.set("defaultPrevented", value);
}

bool Event::getDefaultPrevented()
{
    return HTML5_PROPERTY_GET(defaultPrevented, bool);
}

void Event::setEventPhase(unsigned short value)
{
    this->_eventPhase = value;
    this->v.set("eventPhase", value);
}

unsigned short Event::getEventPhase()
{
    return HTML5_PROPERTY_GET(eventPhase, unsigned short);
}

void Event::setIsTrusted(bool value)
{
    this->_isTrusted = value;
    this->v.set("isTrusted", value);
}

bool Event::getIsTrusted()
{
    return HTML5_PROPERTY_GET(isTrusted, bool);
}

void Event::setTarget(EventTarget *value)
{
    this->_target = value;
    this->v.set("target", value->v);
}

EventTarget *Event::getTarget()
{
    return HTML5_PROPERTY_GET(target, EventTarget);
}

void Event::setType(std::string value)
{
    this->_type = value;
    this->v.set("type", value);
}

std::string Event::getType()
{
    return HTML5_PROPERTY_GET(type, std::string);
}

void Event::setTimeStamp(time_t value)
{
    this->_timeStamp = value;
    this->v.set("timeStamp", value);
}

time_t Event::getTimeStamp()
{
    return HTML5_PROPERTY_GET(timeStamp, time_t);
}
