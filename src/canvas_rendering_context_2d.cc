#include "canvas_rendering_context_2d.h"

CanvasRenderingContext2D::CanvasRenderingContext2D(emscripten::val v) :
    RenderingContext(v)
{

}

CanvasRenderingContext2D::~CanvasRenderingContext2D()
{

}

CanvasRenderingContext2D *CanvasRenderingContext2D::create(emscripten::val v)
{
    auto ctx = new CanvasRenderingContext2D(v);
    ctx->autorelease();
    return ctx;
}
