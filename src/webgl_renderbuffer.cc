#include "webgl_renderbuffer.h"

USING_NAMESPACE_HTML5;

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
