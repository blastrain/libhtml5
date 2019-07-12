#pragma once

#include "html5.h"

NAMESPACE_HTML5_BEGIN;

class RenderingContext : public Object {
public:

    RenderingContext(emscripten::val v);
    virtual ~RenderingContext();
    static RenderingContext *create(emscripten::val v);
};

NAMESPACE_HTML5_END;
