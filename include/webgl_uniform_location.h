#pragma once

#include "libhtml5.h"

class WebGLUniformLocation : public Object {
public:
    emscripten::val v;

    WebGLUniformLocation(emscripten::val v);
    virtual ~WebGLUniformLocation();
    static WebGLUniformLocation *create(emscripten::val v);
};
