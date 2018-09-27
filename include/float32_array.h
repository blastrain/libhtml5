#pragma once

#include "array_buffer_view.h"
#include <vector>

NAMESPACE_HTML5_BEGIN;

class ArrayBuffer;

class Float32Array : public ArrayBufferView {
public:
    const long BYTES_PER_ELEMENT = 4;

    HTML5_PROPERTY(Float32Array, unsigned long, length);

    Float32Array(emscripten::val v);
    virtual ~Float32Array();
    static Float32Array *create(emscripten::val v);
    static Float32Array *create(unsigned long length);
    static Float32Array *create(Float32Array *array);
    static Float32Array *create(const std::vector<double> &array);
    static Float32Array *create(ArrayBuffer *buffer);
    static Float32Array *create(ArrayBuffer *buffer, unsigned long byteOffset);
    static Float32Array *create(ArrayBuffer *buffer, unsigned long byteOffset, unsigned long length);
    double get(unsigned long index);
    void set(Array *array, unsigned long offset = 0);
    Float32Array *subarray(long start, long end);
    double operator[](std::size_t index) const;
    double& operator[](std::size_t index);

private:
    std::vector<double> _rawdata;
};

NAMESPACE_HTML5_END;
