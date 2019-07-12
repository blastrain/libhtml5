#pragma once

#include "html5.h"

NAMESPACE_HTML5_BEGIN;

class WebGLUniformLocation : public Object {
public:

    WebGLUniformLocation(emscripten::val v);
    virtual ~WebGLUniformLocation();
    static WebGLUniformLocation *create(emscripten::val v);
};

NAMESPACE_HTML5_END;
