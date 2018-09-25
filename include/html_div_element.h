#pragma once

#include "html_element.h"

NAMESPACE_HTML5_BEGIN;

class HTMLDivElement : public HTMLElement {
public:

    HTMLDivElement(emscripten::val v);
    virtual ~HTMLDivElement();
    static HTMLDivElement *create(emscripten::val v);
};

NAMESPACE_HTML5_END;
