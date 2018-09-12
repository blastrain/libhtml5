#include "rendering_context.h"
#include <map>
#include <functional>
#include "canvas_rendering_context_2d.h"
#include "webgl_rendering_context.h"

static std::map<std::string, std::function<RenderingContext*(emscripten::val)>> classFactories = {
    CLASS_FACTORY_MAP(CanvasRenderingContext2D),
    CLASS_FACTORY_MAP(WebGLRenderingContext),
};

RenderingContext::RenderingContext(emscripten::val v) : v(v)
{

}

RenderingContext::~RenderingContext()
{

}

RenderingContext *RenderingContext::create(emscripten::val v)
{
#if ENABLE_EMSCRIPTEN
    std::string className = v["constructor"]["name"].as<std::string>();
#else
    std::string className = "";
#endif
    return classFactories[className](v);
}
