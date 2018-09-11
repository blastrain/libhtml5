#pragma once

#include "libhtml5.h"
#include "html_element.h"

class HTMLMenuElement : public HTMLElement {
public:

    HTMLMenuElement(emscripten::val v);
    virtual ~HTMLMenuElement();
    static HTMLMenuElement *create(emscripten::val v);
};
