#pragma once

#include "webgl_object.h"

NAMESPACE_HTML5_BEGIN;

class WebGLShader : public WebGLObject {
public:

    WebGLShader(emscripten::val v);
    virtual ~WebGLShader();
    static WebGLShader *create(emscripten::val v);
};

NAMESPACE_HTML5_END;
