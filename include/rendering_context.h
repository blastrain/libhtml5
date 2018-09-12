#pragma once

#include "libhtml5.h"

class RenderingContext : public Object {
public:
    emscripten::val v;

    RenderingContext(emscripten::val v);
    virtual ~RenderingContext();
    static RenderingContext *create(emscripten::val v);
};
