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

unsigned long CSSRuleList::getLength() const
{
    return HTML5_PROPERTY_GET(length, unsigned long);
}

void CSSRuleList::setLength(unsigned long value)
{
    this->_length = value;
    this->v.set("length", value);
}
