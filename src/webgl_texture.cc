#include "webgl_texture.h"

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
