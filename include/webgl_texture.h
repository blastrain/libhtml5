#pragma once

#include "webgl_object.h"

class WebGLTexture : public WebGLObject {
public:

    WebGLTexture(emscripten::val v);
    virtual ~WebGLTexture();
    static WebGLTexture *create(emscripten::val v);
};
