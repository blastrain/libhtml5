#pragma once

#include "libhtml5.h"

NAMESPACE_HTML5_BEGIN;

class ArrayBuffer : public Object {
public:

    HTML5_PROPERTY(ArrayBuffer, unsigned long, byteLength);

    ArrayBuffer(emscripten::val v);
    virtual ~ArrayBuffer();
    static ArrayBuffer *create(emscripten::val v);
    static ArrayBuffer *create(unsigned long length);
    static bool isView(Object *o);
    ArrayBuffer *slice(long begin);
    ArrayBuffer *slice(long begin, long end);
};

NAMESPACE_HTML5_END;
