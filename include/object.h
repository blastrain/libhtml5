#pragma once

#include "libhtml5.h"
#include "native_object.h"

NAMESPACE_HTML5_BEGIN;

class Object : public NativeObject {
public:
    emscripten::val v;

    Object(emscripten::val v);
    virtual ~Object();
    static Object *create();
    static Object *create(emscripten::val v);
    virtual emscripten::val getValue() const { return this->v; };
};

NAMESPACE_HTML5_END;
