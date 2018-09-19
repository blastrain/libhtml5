#pragma once

#include "libhtml5.h"

class ArrayBuffer;

class ArrayBufferView : public Object {
public:
    emscripten::val v;

    HTML5_PROPERTY_OBJECT(ArrayBufferView, ArrayBuffer, buffer);
    HTML5_PROPERTY(ArrayBufferView, unsigned long, byteLength);
    HTML5_PROPERTY(ArrayBufferView, unsigned long, byteOffset);

    ArrayBufferView(emscripten::val v);
    virtual ~ArrayBufferView();
    static ArrayBufferView *create(emscripten::val v);
};
