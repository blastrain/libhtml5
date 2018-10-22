#pragma once

#include "libhtml5.h"
#include "html_element.h"

NAMESPACE_HTML5_BEGIN;

class HTMLBaseElement : public HTMLElement {
public:

    HTML5_PROPERTY(HTMLBaseElement, std::string, href);
    HTML5_PROPERTY(HTMLBaseElement, std::string, target);

    HTMLBaseElement(emscripten::val v);
    virtual ~HTMLBaseElement();
    static HTMLBaseElement *create(emscripten::val v);

};

NAMESPACE_HTML5_END;