#pragma once

#include "webgl_object.h"

NAMESPACE_HTML5_BEGIN;

class WebGLFramebuffer : public WebGLObject {
public:

    WebGLFramebuffer(emscripten::val v);
    virtual ~WebGLFramebuffer();
    static WebGLFramebuffer *create(emscripten::val v);
};

NAMESPACE_HTML5_END;
