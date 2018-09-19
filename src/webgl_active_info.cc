#include "webgl_active_info.h"

USING_NAMESPACE_HTML5;

WebGLActiveInfo::WebGLActiveInfo(emscripten::val v) :
    Object(),
    v(v)
{

}

WebGLActiveInfo::~WebGLActiveInfo()
{

}

WebGLActiveInfo *WebGLActiveInfo::create(emscripten::val v)
{
    auto info = new WebGLActiveInfo(v);
    info->autorelease();
    return info;
}

HTML5_PROPERTY_IMPL(WebGLActiveInfo, std::string, name);
HTML5_PROPERTY_IMPL(WebGLActiveInfo, GLint, size);
HTML5_PROPERTY_IMPL(WebGLActiveInfo, GLenum, type);
