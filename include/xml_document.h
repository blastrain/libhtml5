#pragma once

#include "document.h"

NAMESPACE_HTML5_BEGIN;

class XMLDocument : Document {
public:

    XMLDocument(emscripten::val v);
    virtual ~XMLDocument();
    static XMLDocument *create(emscripten::val v);
    bool load(std::string url);
};

NAMESPACE_HTML5_END;
