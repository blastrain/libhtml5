#include "webgl_shader_precision_format.h"

USING_NAMESPACE_HTML5;

WebGLShaderPrecisionFormat::WebGLShaderPrecisionFormat(emscripten::val v) :
    Object(),
    v(v)
{

}

WebGLShaderPrecisionFormat::~WebGLShaderPrecisionFormat()
{

}

WebGLShaderPrecisionFormat *WebGLShaderPrecisionFormat::create(emscripten::val v)
{
    auto format = new WebGLShaderPrecisionFormat(v);
    format->autorelease();
    return format;
}

HTML5_PROPERTY_IMPL(WebGLShaderPrecisionFormat, GLint, precision);
HTML5_PROPERTY_IMPL(WebGLShaderPrecisionFormat, GLint, rangeMax);
HTML5_PROPERTY_IMPL(WebGLShaderPrecisionFormat, GLint, rangeMin);
