#include "webgl_object.h"

USING_NAMESPACE_HTML5;

WebGLObject::WebGLObject(emscripten::val v) :
    Object(),
    v(v)
{

}

WebGLObject::~WebGLObject()
{

}
