#include "event_target.h"
#include "event.h"

USING_NAMESPACE_HTML5;

Event::Event(emscripten::val v) :
    Object(v)
{

}

Event::~Event()
{

}

Event *Event::create(std::string type)
{
    Event *event = new Event(HTML5_NEW_PRIMITIVE_INSTANCE(Event, type));
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

HTML5_PROPERTY_IMPL(Event, bool, bubbles);
HTML5_PROPERTY_IMPL(Event, bool, cancelable);
HTML5_PROPERTY_OBJECT_IMPL(Event, EventTarget, currentTarget);
HTML5_PROPERTY_IMPL(Event, bool, defaultPrevented);
HTML5_PROPERTY_IMPL(Event, unsigned short, eventPhase);
HTML5_PROPERTY_IMPL(Event, bool, isTrusted);
HTML5_PROPERTY_OBJECT_IMPL(Event, EventTarget, target);
HTML5_PROPERTY_IMPL(Event, std::string, type);
HTML5_PROPERTY_IMPL(Event, time_t, timeStamp);
