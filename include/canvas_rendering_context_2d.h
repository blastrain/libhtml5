#pragma once

#include "rendering_context.h"

class CanvasRenderingContext2D : public RenderingContext {
public:

    CanvasRenderingContext2D(emscripten::val v);
    virtual ~CanvasRenderingContext2D();
    static CanvasRenderingContext2D *create(emscripten::val v);
};
