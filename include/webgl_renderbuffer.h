#pragma once

#include "webgl_object.h"

class WebGLRenderbuffer : public WebGLObject {
public:

    WebGLRenderbuffer(emscripten::val v);
    virtual ~WebGLRenderbuffer();
    static WebGLRenderbuffer *create(emscripten::val v);
};
