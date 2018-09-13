#pragma once

#include "webgl_object.h"

class WebGLFramebuffer : public WebGLObject {
public:

    WebGLFramebuffer(emscripten::val v);
    virtual ~WebGLFramebuffer();
    static WebGLFramebuffer *create(emscripten::val v);
};
