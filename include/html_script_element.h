#pragma once

#include "html_element.h"

NAMESPACE_HTML5_BEGIN;

class HTMLScriptElement : public HTMLElement {
public:

    HTML5_PROPERTY(HTMLScriptElement, bool, async);
    HTML5_PROPERTY(HTMLScriptElement, std::string, charset);
    HTML5_PROPERTY(HTMLScriptElement, std::string, crossOrigin);
    HTML5_PROPERTY(HTMLScriptElement, bool, defer);
    HTML5_PROPERTY(HTMLScriptElement, std::string, src);
    HTML5_PROPERTY(HTMLScriptElement, std::string, text);
    HTML5_PROPERTY(HTMLScriptElement, std::string, type);

    HTMLScriptElement(emscripten::val v);
    virtual ~HTMLScriptElement();
    static HTMLScriptElement *create(emscripten::val v);
};

NAMESPACE_HTML5_END;
