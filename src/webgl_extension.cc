#include "webgl_extension.h"

USING_NAMESPACE_HTML5;

WebGLExtension::WebGLExtension(emscripten::val v) :
    Object(v)
{

}

WebGLExtension::~WebGLExtension()
{

}

WebGLExtension *WebGLExtension::create(emscripten::val v)
{
    auto ext = new WebGLExtension(v);
    ext->autorelease();
    return ext;
}
