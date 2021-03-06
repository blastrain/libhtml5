#pragma once

#include "array_buffer_view.h"
#include <vector>

NAMESPACE_HTML5_BEGIN;

class ArrayBuffer;

class Float64Array : public ArrayBufferView {
public:
    const long BYTES_PER_ELEMENT = 8;

    HTML5_PROPERTY(Float64Array, unsigned long, length);

    class doubleWrapType {
    public:
        emscripten::val v;
        size_t index;

        doubleWrapType(emscripten::val v, size_t index);
        ~doubleWrapType();
        void operator=(double value);
    };

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
    void set(const array &array, unsigned long offset = 0);
    Float64Array *subarray(long start, long end);
    double operator[](std::size_t index) const;
    doubleWrapType operator[](std::size_t index);

private:
    std::vector<double> _rawdata;
};

NAMESPACE_HTML5_END;
