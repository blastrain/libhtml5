#pragma once

#include "html_element.h"

class HTMLHeadElement : public HTMLElement {
public:

    HTMLHeadElement(emscripten::val v);
    virtual ~HTMLHeadElement();
    static HTMLHeadElement *create(emscripten::val v);
};
