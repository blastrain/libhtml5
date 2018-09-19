#pragma once

#include "libhtml5.h"

NAMESPACE_HTML5_BEGIN;

class RenderingContext : public Object {
public:
    emscripten::val v;

    RenderingContext(emscripten::val v);
    virtual ~RenderingContext();
    static RenderingContext *create(emscripten::val v);
};

NAMESPACE_HTML5_END;
