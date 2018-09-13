#pragma once

#include "libhtml5.h"

class WebGLContextAttributes : public Object {
public:
    emscripten::val v;

    HTML5_PROPERTY(WebGLContextAttributes, GLboolean, alpha);
    HTML5_PROPERTY(WebGLContextAttributes, GLboolean, antialias);
    HTML5_PROPERTY(WebGLContextAttributes, GLboolean, depth);
    HTML5_PROPERTY(WebGLContextAttributes, GLboolean, failIfMajorPerformanceCaveat);
    HTML5_PROPERTY(WebGLContextAttributes, GLboolean, preferLowPowerToHighPerformance);
    HTML5_PROPERTY(WebGLContextAttributes, GLboolean, premultipliedAlpha);
    HTML5_PROPERTY(WebGLContextAttributes, GLboolean, preserveDrawingBuffer);
    HTML5_PROPERTY(WebGLContextAttributes, GLboolean, stencil);
    
    WebGLContextAttributes(emscripten::val v);
    virtual ~WebGLContextAttributes();
    static WebGLContextAttributes *create(emscripten::val v);
};
