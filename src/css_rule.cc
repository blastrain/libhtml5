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

std::string CSSRule::getCSSText() const
{
    return HTML5_PROPERTY_GET(cssText, std::string);
}

void CSSRule::setCSSText(std::string value)
{
    this->_cssText = value;
    this->v.set("cssText", value);
}
   
CSSRule *CSSRule::getParentRule() const
{
    return HTML5_PROPERTY_GET(parentRule, CSSRule);
}

void CSSRule::setParentRule(CSSRule *value)
{
    this->_parentRule = value;
    this->v.set("parentRule", value->v);
}

CSSStyleSheet *CSSRule::getParentStyleSheet() const
{
    return HTML5_PROPERTY_GET(parentStyleSheet, CSSStyleSheet);
}

void CSSRule::setParentStyleSheet(CSSStyleSheet *value)
{
    this->_parentStyleSheet = value;
    this->v.set("parentStyleSheet", value->v);
}

unsigned short CSSRule::getType() const
{
    return HTML5_PROPERTY_GET(type, unsigned short);
}

void CSSRule::setType(unsigned short value)
{
    this->_type = value;
    this->v.set("type", value);
}