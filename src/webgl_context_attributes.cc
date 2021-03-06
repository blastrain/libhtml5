#include "webgl_context_attributes.h"

USING_NAMESPACE_HTML5;

WebGLContextAttributes::WebGLContextAttributes(emscripten::val v) :
    Object(v)
{

}

WebGLContextAttributes::~WebGLContextAttributes()
{

}

WebGLContextAttributes *WebGLContextAttributes::create(emscripten::val v)
{
    auto attr = new WebGLContextAttributes(v);
    attr->autorelease();
    return attr;
}

WebGLContextAttributes *WebGLContextAttributes::create()
{
    return create(HTML5_NEW_PRIMITIVE_INSTANCE(Object));
}

HTML5_PROPERTY_IMPL(WebGLContextAttributes, GLboolean, alpha);
HTML5_PROPERTY_IMPL(WebGLContextAttributes, GLboolean, antialias);
HTML5_PROPERTY_IMPL(WebGLContextAttributes, GLboolean, depth);
HTML5_PROPERTY_IMPL(WebGLContextAttributes, GLboolean, failIfMajorPerformanceCaveat);
HTML5_PROPERTY_IMPL(WebGLContextAttributes, GLboolean, preferLowPowerToHighPerformance);
HTML5_PROPERTY_IMPL(WebGLContextAttributes, GLboolean, premultipliedAlpha);
HTML5_PROPERTY_IMPL(WebGLContextAttributes, GLboolean, preserveDrawingBuffer);
HTML5_PROPERTY_IMPL(WebGLContextAttributes, GLboolean, stencil);
