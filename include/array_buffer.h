#pragma once

#include "libhtml5.h"

class ArrayBuffer : public Object {
public:
    emscripten::val v;
    unsigned long _byteLength;

    ArrayBuffer(emscripten::val v);
    virtual ~ArrayBuffer();
    static ArrayBuffer *create(emscripten::val v);
    static ArrayBuffer *create(unsigned long length);
    static bool isView(Object *o);
    ArrayBuffer *slice(long begin);
    ArrayBuffer *slice(long begin, long end);
    unsigned long getByteLength() const;
    void setByteLength(unsigned long value);

    struct {
        ArrayBuffer &self;
        void operator=(unsigned long value) { self.setByteLength(value); };
        operator unsigned long() { return self.getByteLength(); };
    } byteLength{*this};

};
