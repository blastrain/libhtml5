#pragma once

#include "webgl_object.h"

class WebGLShader : public WebGLObject {
public:

    WebGLShader(emscripten::val v);
    virtual ~WebGLShader();
    static WebGLShader *create(emscripten::val v);
};
