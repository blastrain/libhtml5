#pragma once

#include "html_element.h"

NAMESPACE_HTML5_BEGIN;

class HTMLHeadElement : public HTMLElement {
public:

    HTMLHeadElement(emscripten::val v);
    virtual ~HTMLHeadElement();
    static HTMLHeadElement *create(emscripten::val v);
};

NAMESPACE_HTML5_END;
