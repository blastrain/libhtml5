#include "webgl_buffer.h"

WebGLBuffer::WebGLBuffer(emscripten::val v) :
    WebGLObject(v)
{

}

WebGLBuffer::~WebGLBuffer()
{

}

WebGLBuffer *WebGLBuffer::create(emscripten::val v)
{
    auto buffer = new WebGLBuffer(v);
    buffer->autorelease();
    return buffer;
}
