#pragma once

#include "html_element.h"
#include <emscripten/val.h>

class HTMLMenuElement : public HTMLElement {
public:

    HTMLMenuElement(emscripten::val v);
    virtual ~HTMLMenuElement();
    static HTMLMenuElement *create(emscripten::val v);
};
