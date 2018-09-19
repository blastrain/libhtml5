#pragma once

#include "libhtml5.h"

class Element;

class HTMLCollection : public Object {
public:
    emscripten::val v;

    HTML5_PROPERTY(HTMLCollection, unsigned long, length);

    HTMLCollection(emscripten::val v);
    virtual ~HTMLCollection();
    static HTMLCollection *create();
    static HTMLCollection *create(emscripten::val v);
    Element *item(unsigned long index);
    Element *namedItem(std::string name);
};
