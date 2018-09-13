#include "webgl_extension.h"

WebGLExtension::WebGLExtension(emscripten::val v) :
    Object(),
    v(v)
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
