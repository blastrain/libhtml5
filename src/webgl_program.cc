#include "webgl_program.h"

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
