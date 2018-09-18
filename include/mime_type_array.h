#pragma once

#include "libhtml5.h"

class MimeType;

class MimeTypeArray : public Object {
public:
    emscripten::val v;

    HTML5_PROPERTY(MimeTypeArray, unsigned long, length);

    MimeTypeArray(emscripten::val v);
    virtual ~MimeTypeArray();
    static MimeTypeArray *create(emscripten::val v);
    MimeType *item(unsigned long index);
    MimeType *namedItem(std::string name);
};
