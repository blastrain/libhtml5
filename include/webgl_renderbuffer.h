#pragma once

#include "webgl_object.h"

NAMESPACE_HTML5_BEGIN;

class WebGLRenderbuffer : public WebGLObject {
public:

    WebGLRenderbuffer(emscripten::val v);
    virtual ~WebGLRenderbuffer();
    static WebGLRenderbuffer *create(emscripten::val v);
};

NAMESPACE_HTML5_END;
