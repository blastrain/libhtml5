#pragma once

#include "webgl_object.h"

NAMESPACE_HTML5_BEGIN;

class WebGLProgram : public WebGLObject {
public:

    WebGLProgram(emscripten::val v);
    virtual ~WebGLProgram();
    static WebGLProgram *create(emscripten::val v);
};

NAMESPACE_HTML5_END;
