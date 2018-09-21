#pragma once

#include "libhtml5.h"

NAMESPACE_HTML5_BEGIN;

class MimeType;

class MimeTypeArray : public Object {
public:

    HTML5_PROPERTY(MimeTypeArray, unsigned long, length);

    MimeTypeArray(emscripten::val v);
    virtual ~MimeTypeArray();
    static MimeTypeArray *create(emscripten::val v);
    MimeType *item(unsigned long index);
    MimeType *namedItem(std::string name);
};

NAMESPACE_HTML5_END;
