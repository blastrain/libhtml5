#include "css_rule.h"
#include "css_rule_list.h"
#include "css_style_sheet.h"

USING_NAMESPACE_HTML5;

CSSStyleSheet::CSSStyleSheet(emscripten::val v) :
    StyleSheet(v)
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
    HTML5_CALL(this->v, deleteRule, index);
}

unsigned long CSSStyleSheet::insertRule(std::string rule, unsigned long index)
{
    return HTML5_CALLi(this->v, insertRule, unsigned long, rule, index);
}

HTML5_PROPERTY_OBJECT_IMPL(CSSStyleSheet, CSSRuleList, cssRules);
HTML5_PROPERTY_OBJECT_IMPL(CSSStyleSheet, CSSRule, ownerRule);
