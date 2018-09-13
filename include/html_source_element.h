#pragma once

#include "html_element.h"

class HTMLSourceElement : public HTMLElement {
public:

    PROPERTY(HTMLSourceElement, std::string, src);
    PROPERTY(HTMLSourceElement, std::string, type);

    HTMLSourceElement(emscripten::val v);
    ~HTMLSourceElement();
    static HTMLSourceElement *create();
    static HTMLSourceElement *create(emscripten::val v);
};
