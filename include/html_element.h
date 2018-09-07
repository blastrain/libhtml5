#pragma once

#include "element.h"
#include <emscripten/val.h>

class HTMLElement : public Element {
public:

    HTMLElement(emscripten::val v);
    virtual ~HTMLElement();
    static HTMLElement *create(emscripten::val v);
};
