#pragma once

#include "libhtml5.h"

NAMESPACE_HTML5_BEGIN;

class WebGLActiveInfo : public Object {
public:
    emscripten::val v;
    HTML5_PROPERTY(WebGLActiveInfo, std::string, name);
    HTML5_PROPERTY(WebGLActiveInfo, GLint, size);
    HTML5_PROPERTY(WebGLActiveInfo, GLenum, type);

    WebGLActiveInfo(emscripten::val v);
    virtual ~WebGLActiveInfo();
    static WebGLActiveInfo *create(emscripten::val v);
};

NAMESPACE_HTML5_END;
