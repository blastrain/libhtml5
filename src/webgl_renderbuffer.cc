#include "webgl_renderbuffer.h"

WebGLRenderbuffer::WebGLRenderbuffer(emscripten::val v) :
    WebGLObject(v)
{

}

WebGLRenderbuffer::~WebGLRenderbuffer()
{

}

WebGLRenderbuffer *WebGLRenderbuffer::create(emscripten::val v)
{
    auto buffer = new WebGLRenderbuffer(v);
    buffer->autorelease();
    return buffer;
}
