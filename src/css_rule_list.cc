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
    return new CSSRuleList(v);
}

CSSRule *CSSRuleList::item(unsigned long index)
{
    return CSSRule::create(this->v.call<emscripten::val>("item", index));
}

unsigned long CSSRuleList::getLength() const
{
    return this->v["length"].as<unsigned long>();
}

void CSSRuleList::setLength(unsigned long value)
{
    this->_length = value;
    this->v.set("length", value);
}
