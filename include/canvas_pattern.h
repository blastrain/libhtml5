#pragma once

#include "libhtml5.h"

NAMESPACE_HTML5_BEGIN;

class SVGMatrix;

class CanvasPattern : public Object {
public:

    CanvasPattern(emscripten::val v);
    virtual ~CanvasPattern();
    static CanvasPattern *create(emscripten::val v);
    void setTransform(SVGMatrix *transform);
};

NAMESPACE_HTML5_END;
