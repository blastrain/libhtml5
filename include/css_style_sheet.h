#pragma once

#include "style_sheet.h"

class CSSRule;
class CSSRuleList;

class CSSStyleSheet : public StyleSheet {
public:
    emscripten::val v;
    CSSRuleList *_cssRules;
    CSSRule *_ownerRule;

    CSSStyleSheet(emscripten::val v);
    virtual ~CSSStyleSheet();
    static CSSStyleSheet *create(emscripten::val v);
    void deleteRule(unsigned long index);
    unsigned long insertRule(std::string rule, unsigned long index);

    CSSRuleList *getCSSRules() const;
    void setCSSRules(CSSRuleList *value);
    CSSRule *getOwnerRule() const;
    void setOwnerRule(CSSRule *value);

    struct {
        CSSStyleSheet &self;
        void operator=(CSSRuleList *value) { self.setCSSRules(value); };
        operator CSSRuleList *() { return self.getCSSRules(); };
    } cssRules{*this};

    struct {
        CSSStyleSheet &self;
        void operator=(CSSRule *value) { self.setOwnerRule(value); };
        operator CSSRule *() { return self.getOwnerRule(); };
    } ownerRule{*this};

};
