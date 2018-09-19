#pragma once

#include "style_sheet.h"

NAMESPACE_HTML5_BEGIN;

class CSSRule;
class CSSRuleList;

class CSSStyleSheet : public StyleSheet {
public:

    HTML5_PROPERTY_OBJECT(CSSStyleSheet, CSSRuleList, cssRules);
    HTML5_PROPERTY_OBJECT(CSSStyleSheet, CSSRule, ownerRule);

    CSSStyleSheet(emscripten::val v);
    virtual ~CSSStyleSheet();
    static CSSStyleSheet *create(emscripten::val v);
    void deleteRule(unsigned long index);
    unsigned long insertRule(std::string rule, unsigned long index);
};

NAMESPACE_HTML5_END;
