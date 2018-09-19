#pragma once

#include "libhtml5.h"

class ArrayBuffer : public Object {
public:
    emscripten::val v;

    HTML5_PROPERTY(ArrayBuffer, unsigned long, byteLength);

    ArrayBuffer(emscripten::val v);
    virtual ~ArrayBuffer();
    static ArrayBuffer *create(emscripten::val v);
    static ArrayBuffer *create(unsigned long length);
    static bool isView(Object *o);
    ArrayBuffer *slice(long begin);
    ArrayBuffer *slice(long begin, long end);
};
