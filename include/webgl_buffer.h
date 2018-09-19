#pragma once

#include "webgl_object.h"

NAMESPACE_HTML5_BEGIN;

class WebGLBuffer : public WebGLObject {
public:

    WebGLBuffer(emscripten::val v);
    virtual ~WebGLBuffer();
    static WebGLBuffer *create(emscripten::val v);
};

NAMESPACE_HTML5_END;
