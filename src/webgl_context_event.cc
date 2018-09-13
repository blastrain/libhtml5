#include "webgl_context_event.h"

WebGLContextEvent::WebGLContextEvent(emscripten::val v) :
    Event(v)
{

}

WebGLContextEvent::~WebGLContextEvent()
{

}

WebGLContextEvent *WebGLContextEvent::create(emscripten::val v)
{
    auto event = new WebGLContextEvent(v);
    event->autorelease();
    return event;
}

HTML5_PROPERTY_IMPL(WebGLContextEvent, std::string, statusMessage);
