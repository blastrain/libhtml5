#pragma once

#include "document.h"

class XMLDocument : Document {
public:

    XMLDocument(emscripten::val v);
    virtual ~XMLDocument();
    static XMLDocument *create(emscripten::val v);
    bool load(std::string url);
};
