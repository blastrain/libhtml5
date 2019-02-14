#pragma once

#include "array_buffer_view.h"
#include <vector>

NAMESPACE_HTML5_BEGIN;

class Uint8Array : public ArrayBufferView {
public:
    const long BYTES_PER_ELEMENT = 1;

    HTML5_PROPERTY(Uint8Array, unsigned long, length);

    class uint8WrapType {
    public:
        emscripten::val v;
        size_t index;

        uint8WrapType(emscripten::val v, size_t index);
        ~uint8WrapType();
        void operator=(uint8_t value);
        operator uint8_t() const {
            return this->v[this->index].as<uint8_t>();
        };
    };

    Uint8Array(emscripten::val v);
    virtual ~Uint8Array();
    static Uint8Array *create(emscripten::val v);
    static Uint8Array *create();
    static Uint8Array *create(unsigned long length);
    static Uint8Array *create(Uint8Array *array);
    static Uint8Array *create(ArrayBuffer *buffer);
    static Uint8Array *create(ArrayBuffer *buffer, unsigned long byteOffset);
    static Uint8Array *create(ArrayBuffer *buffer, unsigned long byteOffset, unsigned long length);
    uint8WrapType operator[](std::size_t index) const;
    uint8WrapType operator[](std::size_t index);
    
private:
    std::vector<uint8_t> _rawdata;
};

NAMESPACE_HTML5_END;
