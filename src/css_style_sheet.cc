#include "css_rule.h"
#include "css_rule_list.h"
#include "css_style_sheet.h"

CSSStyleSheet::CSSStyleSheet(emscripten::val v) : v(v)
{

}

CSSStyleSheet::~CSSStyleSheet()
{

}

CSSStyleSheet *CSSStyleSheet::create(emscripten::val v)
{
    CSSStyleSheet *sheet = new CSSStyleSheet(v);
    sheet->autorelease();
    return sheet;
}

void CSSStyleSheet::deleteRule(unsigned long index)
{
    this->v.call<void>("deleteRule", index);
}

unsigned long CSSStyleSheet::insertRule(std::string rule, unsigned long index)
{
    return this->v.call<unsigned long>("insertRule", rule, index);
}

CSSRuleList *CSSStyleSheet::getCSSRules() const
{
    return CSSRuleList::create(this->v["cssRules"]);
}

void CSSStyleSheet::setCSSRules(CSSRuleList *value)
{
    this->_cssRules = value;
    this->v.set("cssRules", value->v);
}

CSSRule *CSSStyleSheet::getOwnerRule() const
{
    return CSSRule::create(this->v["ownerRule"]);
}

void CSSStyleSheet::setOwnerRule(CSSRule *value)
{
    this->_ownerRule = value;
    this->v.set("ownerRule", value->v);
}
