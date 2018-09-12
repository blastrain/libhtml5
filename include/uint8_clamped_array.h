#pragma once

#include "array_buffer_view.h"

class Uint8ClampedArray : public ArrayBufferView {
public:
    const long BYTES_PER_ELEMENT = 1;
    unsigned long _length;

    Uint8ClampedArray(emscripten::val v);
    virtual ~Uint8ClampedArray();
    static Uint8ClampedArray *create(emscripten::val v);
    static Uint8ClampedArray *create();
    static Uint8ClampedArray *create(unsigned long length);
    static Uint8ClampedArray *create(Uint8ClampedArray *array);
    static Uint8ClampedArray *create(ArrayBuffer *buffer);
    static Uint8ClampedArray *create(ArrayBuffer *buffer, unsigned long byteOffset);
    static Uint8ClampedArray *create(ArrayBuffer *buffer, unsigned long byteOffset, unsigned long length);

    unsigned long getLength() const;
    void setLength(unsigned long value);

    struct {
        Uint8ClampedArray &self;
        void operator=(unsigned long value) { self.setLength(value); };
        operator unsigned long() { return self.getLength(); };
    } length{*this};
};
