#include "webgl_shader.h"

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
