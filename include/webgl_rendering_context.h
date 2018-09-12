#pragma once

#include "rendering_context.h"

class WebGLRenderingContext : public RenderingContext {
public:

    WebGLRenderingContext(emscripten::val v);
    virtual ~WebGLRenderingContext();
    static WebGLRenderingContext *create(emscripten::val v);
};
