#include "dom_token_list.h"

DOMTokenList::DOMTokenList(emscripten::val v) : v(v)
{

}

DOMTokenList::~DOMTokenList()
{

}

DOMTokenList *DOMTokenList::create(emscripten::val v)
{
    DOMTokenList *list = new DOMTokenList(v);
    list->autorelease();
    return list;
}

void DOMTokenList::add(std::vector<std::string> tokens)
{
    for (auto &token : tokens) {
        HTML5_CALL(this->v, add, token);
    }
}

bool DOMTokenList::contains(std::string token)
{
    return HTML5_CALLb(this->v, contains, token);
}

void DOMTokenList::remove(std::vector<std::string> tokens)
{
    for (auto &token : tokens) {
        HTML5_CALL(this->v, remove, token);
    }
}

bool DOMTokenList::toggle(std::string token, bool force)
{
    return HTML5_CALLb(this->v, toggle, token, force);
}

HTML5_PROPERTY_IMPL(DOMTokenList, unsigned long, length);
