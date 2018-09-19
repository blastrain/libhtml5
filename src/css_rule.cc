#include "css_style_sheet.h"
#include "css_rule.h"

CSSRule::CSSRule(emscripten::val v) : v(v)
{

}

CSSRule::~CSSRule()
{

}

CSSRule *CSSRule::create(emscripten::val v)
{
    CSSRule *rule = new CSSRule(v);
    rule->autorelease();
    return rule;
}

HTML5_PROPERTY_IMPL(CSSRule, std::string, cssText);
HTML5_PROPERTY_OBJECT_IMPL(CSSRule, CSSRule, parentRule);
HTML5_PROPERTY_OBJECT_IMPL(CSSRule, CSSStyleSheet, parentStyleSheet);
HTML5_PROPERTY_IMPL(CSSRule, unsigned short, type);
