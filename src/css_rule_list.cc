#include "css_rule.h"
#include "css_rule_list.h"

CSSRuleList::CSSRuleList(emscripten::val v) : v(v)
{

}

CSSRuleList::~CSSRuleList()
{

}

CSSRuleList *CSSRuleList::create(emscripten::val v)
{
    CSSRuleList *ruleList = new CSSRuleList(v);
    ruleList->autorelease();
    return ruleList;
}

CSSRule *CSSRuleList::item(unsigned long index)
{
    return CSSRule::create(HTML5_CALLv(this->v, item, index));
}

HTML5_PROPERTY_IMPL(CSSRuleList, unsigned long, length);
