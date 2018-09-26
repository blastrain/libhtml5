#pragma once

#include "libhtml5.h"

NAMESPACE_HTML5_BEGIN;

class CSSRule;

class CSSRuleList : public Object {
public:

    HTML5_PROPERTY(CSSRuleList, unsigned long, length);
    HTML5_DEFINE_ITERATOR(CSSRuleList, CSSRule);

    CSSRuleList(emscripten::val v);
    virtual ~CSSRuleList();
    static CSSRuleList *create(emscripten::val v);
    CSSRule *item(unsigned long index);

    
};

NAMESPACE_HTML5_END;
