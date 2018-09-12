#include "webgl_rendering_context.h"

WebGLRenderingContext::WebGLRenderingContext(emscripten::val v) :
    RenderingContext(v)
{

}

WebGLRenderingContext::~WebGLRenderingContext()
{

}

WebGLRenderingContext *WebGLRenderingContext::create(emscripten::val v)
{
    auto ctx = new WebGLRenderingContext(v);
    ctx->autorelease();
    return ctx;
}
