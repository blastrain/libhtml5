#pragma once

#include "libhtml5.h"

class ArrayBuffer;

class ArrayBufferView : public Object {
public:
    emscripten::val v;
    ArrayBuffer *_buffer;
    unsigned long _byteLength;
    unsigned long _byteOffset;

    ArrayBufferView(emscripten::val v);
    virtual ~ArrayBufferView();
    ArrayBuffer *getBuffer() const;
    void setBuffer(ArrayBuffer *value);
    unsigned long getByteLength() const;
    void setByteLength(unsigned long value);
    unsigned long getByteOffset() const;
    void setByteOffset(unsigned long value);

    struct {
        ArrayBufferView &self;
        void operator=(ArrayBuffer *value) { self.setBuffer(value); };
        operator ArrayBuffer *() { return self.getBuffer(); };
    } buffer{*this};

    struct {
        ArrayBufferView &self;
        void operator=(unsigned long value) { self.setByteLength(value); };
        operator unsigned long() { return self.getByteLength(); };
    } byteLength{*this};

    struct {
        ArrayBufferView &self;
        void operator=(unsigned long value) { self.setByteOffset(value); };
        operator unsigned long() { return self.getByteOffset(); };
    } byteOffset{*this};

};
