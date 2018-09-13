#pragma once

#include "libhtml5.h"

class WebGLObject : public Object {
public:
    emscripten::val v;

    WebGLObject(emscripten::val v);
    virtual ~WebGLObject();
};
