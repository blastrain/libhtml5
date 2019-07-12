#pragma once

#include "html5.h"

NAMESPACE_HTML5_BEGIN;

class BarProp : public Object {
public:
    HTML5_PROPERTY(BarProp, bool, visible);

    BarProp(emscripten::val v);
    virtual ~BarProp();
    static BarProp *create(emscripten::val v);
};

NAMESPACE_HTML5_END;
