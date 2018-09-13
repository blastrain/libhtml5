#pragma once

#include "webgl_object.h"

class WebGLBuffer : public WebGLObject {
public:

    WebGLBuffer(emscripten::val v);
    virtual ~WebGLBuffer();
    static WebGLBuffer *create(emscripten::val v);
};
