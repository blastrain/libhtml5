#pragma once

#include "object.h"
#include <emscripten/val.h>

class CSSRule;

class CSSRuleList : public Object {
public:
    emscripten::val v;
    unsigned long _length;

    CSSRuleList(emscripten::val v);
    virtual ~CSSRuleList();
    static CSSRuleList *create(emscripten::val v);
    CSSRule *item(unsigned long index);
    unsigned long getLength() const;
    void setLength(unsigned long value);

    struct {
        CSSRuleList &self;
        void operator=(unsigned long value) { self.setLength(value); };
        operator unsigned long() { return self.getLength(); };
    } length{*this};

};
