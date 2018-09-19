#include "webgl_program.h"

USING_NAMESPACE_HTML5;

WebGLProgram::WebGLProgram(emscripten::val v) :
    WebGLObject(v)
{

}

WebGLProgram::~WebGLProgram()
{

}

WebGLProgram *WebGLProgram::create(emscripten::val v)
{
    auto program = new WebGLProgram(v);
    program->autorelease();
    return program;
}
