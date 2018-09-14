#pragma once

#include "libhtml5.h"

class BarProp : public Object {
public:
    emscripten::val v;
    HTML5_PROPERTY(BarProp, bool, visible);

    BarProp(emscripten::val v);
    virtual ~BarProp();
    static BarProp *create(emscripten::val v);
};
