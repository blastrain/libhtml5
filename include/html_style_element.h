#pragma once

#include "html_element.h"
#include "link_style.h"
#include "style_sheet.h"

NAMESPACE_HTML5_BEGIN;

class HTMLStyleElement : public HTMLElement, public LinkStyle {
public:

    HTML5_PROPERTY(HTMLStyleElement, std::string, media);
    HTML5_PROPERTY(HTMLStyleElement, bool, scoped);
    HTML5_VIRTUAL_READONLY_PROPERTY_OBJECT(HTMLStyleElement, StyleSheet, sheet);
    HTML5_PROPERTY(HTMLStyleElement, std::string, type);

    HTMLStyleElement(emscripten::val v);
    virtual ~HTMLStyleElement();
    static HTMLStyleElement *create(emscripten::val v);
};

NAMESPACE_HTML5_END;
