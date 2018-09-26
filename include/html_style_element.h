#pragma once

#include "html_element.h"
#include "link_style.h"
#include "style_sheet.h"

NAMESPACE_HTML5_BEGIN;

class HTMLStyleElement : public HTMLElement, public LinkStyle {
public:

    HTMLStyleElement(emscripten::val v);
    virtual ~HTMLStyleElement();
    static HTMLStyleElement *create(emscripten::val v);

    HTML5_PROPERTY(HTMLStyleElement, std::string, media);
    HTML5_PROPERTY(HTMLStyleElement, bool, scoped);
    HTML5_VIRTUAL_PROPERTY_OBJECT(HTMLStyleElement, StyleSheet, sheet);
    HTML5_PROPERTY(HTMLStyleElement, std::string, type);
};

NAMESPACE_HTML5_END;
