#pragma once

#include "libhtml5.h"

class CSSRule;

class CSSRuleList : public Object {
public:
    emscripten::val v;

    HTML5_PROPERTY(CSSRuleList, unsigned long, length);

    CSSRuleList(emscripten::val v);
    virtual ~CSSRuleList();
    static CSSRuleList *create(emscripten::val v);
    CSSRule *item(unsigned long index);
};
