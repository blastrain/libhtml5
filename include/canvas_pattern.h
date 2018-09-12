#pragma once

#include "libhtml5.h"

class SVGMatrix;

class CanvasPattern : public Object {
public:
    emscripten::val v;

    CanvasPattern(emscripten::val v);
    virtual ~CanvasPattern();
    static CanvasPattern *create(emscripten::val v);
    void setTransform(SVGMatrix *transform);
};
