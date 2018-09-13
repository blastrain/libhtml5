#include "html_canvas_element.h"
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

HTML5_PROPERTY_OBJECT_IMPL(WebGLRenderingContext, HTMLCanvasElement, canvas);
HTML5_PROPERTY_IMPL(WebGLRenderingContext, GLsizei, drawingBufferHeight);
HTML5_PROPERTY_IMPL(WebGLRenderingContext, GLsizei, drawingBufferWidth);
