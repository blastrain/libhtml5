#pragma once

#include "html_element.h"

NAMESPACE_HTML5_BEGIN;

class HTMLContentElement : public HTMLElement {
public:

    HTML5_PROPERTY(HTMLContentElement, bool, resetStyleInheritance);
    HTML5_PROPERTY(HTMLContentElement, std::string, select);

    HTMLContentElement(emscripten::val v);
    virtual ~HTMLContentElement();
    static HTMLContentElement *create(emscripten::val v);
    NodeList *getDistributedNodes();
};

NAMESPACE_HTML5_END;
