#include "rendering_context.h"
#include <map>
#include <functional>
#include "canvas_rendering_context_2d.h"
#include "webgl_rendering_context.h"

USING_NAMESPACE_HTML5;

HTML5_CLASS_FACTORY(RenderingContext) {
    HTML5_SUBCLASS_FACTORY(CanvasRenderingContext2D),
    HTML5_SUBCLASS_FACTORY(WebGLRenderingContext),
};

HTML5_CREATE_IMPL(RenderingContext);

RenderingContext::RenderingContext(emscripten::val v) :
    Object(v)
{

}

RenderingContext::~RenderingContext()
{

}
