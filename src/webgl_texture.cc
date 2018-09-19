#include "webgl_texture.h"

USING_NAMESPACE_HTML5;

WebGLTexture::WebGLTexture(emscripten::val v) :
    WebGLObject(v)
{

}

WebGLTexture::~WebGLTexture()
{

}

WebGLTexture *WebGLTexture::create(emscripten::val v)
{
    auto texture = new WebGLTexture(v);
    texture->autorelease();
    return texture;
}
