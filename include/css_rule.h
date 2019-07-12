#pragma once

#include "html5.h"

NAMESPACE_HTML5_BEGIN;

class CSSStyleSheet;

class CSSRule : public Object {
public:

    enum {
        STYLE_RULE     = 1,
        CHARSET_RULE   = 2,
        IMPORT_RULE    = 3,
        MEDIA_RULE     = 4,
        FONT_FACE_RULE = 5,
        PAGE_RULE      = 6,
        MARGIN_RULE    = 9,
        NAMESPACE_RULE = 10,
        HOST_RULE      = 1001,
    };

    HTML5_PROPERTY(CSSRule, std::string, cssText);
    HTML5_PROPERTY_OBJECT(CSSRule, CSSRule, parentRule);
    HTML5_PROPERTY_OBJECT(CSSRule, CSSStyleSheet, parentStyleSheet);
    HTML5_PROPERTY(CSSRule, unsigned short, type);

    CSSRule(emscripten::val v);
    virtual ~CSSRule();
    static CSSRule *create(emscripten::val v);
};

NAMESPACE_HTML5_END;
