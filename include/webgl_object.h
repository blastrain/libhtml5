#pragma once

#include "libhtml5.h"

NAMESPACE_HTML5_BEGIN;

class WebGLObject : public Object {
public:
    emscripten::val v;

    WebGLObject(emscripten::val v);
    virtual ~WebGLObject();
};

NAMESPACE_HTML5_END;
