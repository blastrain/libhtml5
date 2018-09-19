#include "webgl_buffer.h"

USING_NAMESPACE_HTML5;

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
