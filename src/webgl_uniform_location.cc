#include "webgl_uniform_location.h"

USING_NAMESPACE_HTML5;

WebGLUniformLocation::WebGLUniformLocation(emscripten::val v) :
    Object(),
    v(v)
{

}

WebGLUniformLocation::~WebGLUniformLocation()
{

}

WebGLUniformLocation *WebGLUniformLocation::create(emscripten::val v)
{
    auto location = new WebGLUniformLocation(v);
    location->autorelease();
    return location;
}
