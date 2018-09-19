#pragma once

#include "libhtml5.h"

NAMESPACE_HTML5_BEGIN;

class BarProp : public Object {
public:
    emscripten::val v;
    HTML5_PROPERTY(BarProp, bool, visible);

    BarProp(emscripten::val v);
    virtual ~BarProp();
    static BarProp *create(emscripten::val v);
};

NAMESPACE_HTML5_END;
