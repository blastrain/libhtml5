#pragma once

#include "html5.h"

NAMESPACE_HTML5_BEGIN;

class WebGLShaderPrecisionFormat : public Object {
public:

    HTML5_PROPERTY(WebGLShaderPrecisionFormat, GLint, precision);
    HTML5_PROPERTY(WebGLShaderPrecisionFormat, GLint, rangeMax);
    HTML5_PROPERTY(WebGLShaderPrecisionFormat, GLint, rangeMin);

    WebGLShaderPrecisionFormat(emscripten::val v);
    virtual ~WebGLShaderPrecisionFormat();
    static WebGLShaderPrecisionFormat *create(emscripten::val v);
};

NAMESPACE_HTML5_END;
