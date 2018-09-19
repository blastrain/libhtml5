#pragma once

#include "libhtml5.h"

NAMESPACE_HTML5_BEGIN;

class CanvasGradient : public Object {
public:
    emscripten::val v;

    CanvasGradient(emscripten::val v);
    virtual ~CanvasGradient();
    static CanvasGradient *create(emscripten::val v);
    void addColorStop(double offset, std::string color);
};

NAMESPACE_HTML5_END;
