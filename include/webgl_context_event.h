#pragma once

#include "event.h"

NAMESPACE_HTML5_BEGIN;

class WebGLContextEvent : public Event {
public:
    HTML5_PROPERTY(WebGLContextEvent, std::string, statusMessage);

    WebGLContextEvent(emscripten::val v);
    virtual ~WebGLContextEvent();
    static WebGLContextEvent *create(emscripten::val v);
};

NAMESPACE_HTML5_END;
