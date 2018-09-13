#pragma once

#include "libhtml5.h"

class WebGLShaderPrecisionFormat : public Object {
public:
    emscripten::val v;
    HTML5_PROPERTY(WebGLShaderPrecisionFormat, GLint, precision);
    HTML5_PROPERTY(WebGLShaderPrecisionFormat, GLint, rangeMax);
    HTML5_PROPERTY(WebGLShaderPrecisionFormat, GLint, rangeMin);

    WebGLShaderPrecisionFormat(emscripten::val v);
    virtual ~WebGLShaderPrecisionFormat();
    static WebGLShaderPrecisionFormat *create(emscripten::val v);
};
