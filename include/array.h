#pragma once

#include "object.h"
#include <vector>

NAMESPACE_HTML5_BEGIN;

class Array : public Object {
public:

    HTML5_PROPERTY(Array, unsigned long, length);

    Array(emscripten::val v);
    virtual ~Array();
    static Array *create(emscripten::val v);
};

NAMESPACE_HTML5_END;
