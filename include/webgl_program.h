#pragma once

#include "webgl_object.h"

class WebGLProgram : public WebGLObject {
public:

    WebGLProgram(emscripten::val v);
    virtual ~WebGLProgram();
    static WebGLProgram *create(emscripten::val v);
};
