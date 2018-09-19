#pragma once

#include "webgl_object.h"

NAMESPACE_HTML5_BEGIN;

class WebGLTexture : public WebGLObject {
public:

    WebGLTexture(emscripten::val v);
    virtual ~WebGLTexture();
    static WebGLTexture *create(emscripten::val v);
};

NAMESPACE_HTML5_END;
