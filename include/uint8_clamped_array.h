#pragma once

#include "array_buffer_view.h"
#include <vector>

NAMESPACE_HTML5_BEGIN;

class Uint8ClampedArray : public ArrayBufferView {
public:
    const long BYTES_PER_ELEMENT = 1;

    HTML5_PROPERTY(Uint8ClampedArray, unsigned long, length);

    Uint8ClampedArray(emscripten::val v);
    virtual ~Uint8ClampedArray();
    static Uint8ClampedArray *create(emscripten::val v);
    static Uint8ClampedArray *create();
    static Uint8ClampedArray *create(unsigned long length);
    static Uint8ClampedArray *create(Uint8ClampedArray *array);
    static Uint8ClampedArray *create(ArrayBuffer *buffer);
    static Uint8ClampedArray *create(ArrayBuffer *buffer, unsigned long byteOffset);
    static Uint8ClampedArray *create(ArrayBuffer *buffer, unsigned long byteOffset, unsigned long length);
    uint8_t operator[](std::size_t index) const;
    uint8_t& operator[](std::size_t index);
    
private:
    std::vector<uint8_t> _rawdata;
};

NAMESPACE_HTML5_END;
