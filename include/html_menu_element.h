#pragma once

#include "html5.h"
#include "html_element.h"

NAMESPACE_HTML5_BEGIN;

class HTMLMenuElement : public HTMLElement {
public:

    HTMLMenuElement(emscripten::val v);
    virtual ~HTMLMenuElement();
    static HTMLMenuElement *create(emscripten::val v);
};

NAMESPACE_HTML5_END;
