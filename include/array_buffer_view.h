#pragma once

#include "libhtml5.h"

NAMESPACE_HTML5_BEGIN;

class ArrayBuffer;

class ArrayBufferView : public Object {
public:

    HTML5_PROPERTY_OBJECT(ArrayBufferView, ArrayBuffer, buffer);
    HTML5_PROPERTY(ArrayBufferView, unsigned long, byteLength);
    HTML5_PROPERTY(ArrayBufferView, unsigned long, byteOffset);

    ArrayBufferView(emscripten::val v);
    virtual ~ArrayBufferView();
    static std::unique_ptr<ArrayBufferView> create(emscripten::val v);
};

NAMESPACE_HTML5_END;
