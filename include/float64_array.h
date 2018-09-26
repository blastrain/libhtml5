#pragma once

#include "array_buffer_view.h"

NAMESPACE_HTML5_BEGIN;

class ArrayBuffer;

class Float64Array : public ArrayBufferView {
public:
    const long BYTES_PER_ELEMENT = 8;

    HTML5_PROPERTY(Float64Array, unsigned long, length);

    Float64Array(emscripten::val v);
    virtual ~Float64Array();
    static Float64Array *create(emscripten::val v);
    static Float64Array *create(unsigned long length);
    static Float64Array *create(Float64Array *array);
    static Float64Array *create(const std::vector<double> &array);
    static Float64Array *create(ArrayBuffer *buffer);
    static Float64Array *create(ArrayBuffer *buffer, unsigned long byteOffset);
    static Float64Array *create(ArrayBuffer *buffer, unsigned long byteOffset, unsigned long length);
    double get(unsigned long index);
    void set(Array *array, unsigned long offset = 0);
    Float64Array *subarray(long start, long end);
};

NAMESPACE_HTML5_END;
