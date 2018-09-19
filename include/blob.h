#pragma once

#include "libhtml5.h"

NAMESPACE_HTML5_BEGIN;

class Blob : public Object {
public:
    emscripten::val v;

    HTML5_PROPERTY(Blob, unsigned long long, size);
    HTML5_PROPERTY(Blob, std::string, type);

    Blob(emscripten::val v);
    virtual ~Blob();
    static Blob *create(emscripten::val v);
    void close();
    Blob *slice(long long start = 0);
    Blob *slice(long long start, long long end, std::string contentType = "");
};

NAMESPACE_HTML5_END;
