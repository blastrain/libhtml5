#include "webgl_framebuffer.h"

USING_NAMESPACE_HTML5;

WebGLFramebuffer::WebGLFramebuffer(emscripten::val v) :
    WebGLObject(v)
{

}

WebGLFramebuffer::~WebGLFramebuffer()
{

}

WebGLFramebuffer *WebGLFramebuffer::create(emscripten::val v)
{
    auto buffer = new WebGLFramebuffer(v);
    buffer->autorelease();
    return buffer;
}
