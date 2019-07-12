#pragma once

#include "html5.h"

NAMESPACE_HTML5_BEGIN;

class Element;

class HTMLCollection : public Object {
public:

    HTML5_PROPERTY(HTMLCollection, unsigned long, length);

    HTMLCollection(emscripten::val v);
    virtual ~HTMLCollection();
    static HTMLCollection *create();
    static HTMLCollection *create(emscripten::val v);
    Element *item(unsigned long index);
    Element *namedItem(std::string name);
};

NAMESPACE_HTML5_END;
