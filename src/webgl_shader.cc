#include "webgl_shader.h"

USING_NAMESPACE_HTML5;

WebGLShader::WebGLShader(emscripten::val v) :
    WebGLObject(v)
{

}

WebGLShader::~WebGLShader()
{

}

WebGLShader *WebGLShader::create(emscripten::val v)
{
    auto shader = new WebGLShader(v);
    shader->autorelease();
    return shader;
}
