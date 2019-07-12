#pragma once

#include "html5.h"

NAMESPACE_HTML5_BEGIN;

class Attr : public Object {
public:

    HTML5_PROPERTY(Attr, std::string, localName);
    HTML5_PROPERTY(Attr, std::string, name);
    HTML5_PROPERTY(Attr, std::string, namespaceURI);
    HTML5_PROPERTY(Attr, std::string, prefix);
    HTML5_PROPERTY(Attr, bool, specified);
    HTML5_PROPERTY(Attr, std::string, value);

    Attr(emscripten::val v);
    virtual ~Attr();
    static Attr *create(emscripten::val v);
    static Attr *create();
};

NAMESPACE_HTML5_END;
