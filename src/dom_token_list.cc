#include "dom_token_list.h"

DOMTokenList::DOMTokenList(emscripten::val v) : v(v)
{

}

DOMTokenList::~DOMTokenList()
{

}

DOMTokenList *DOMTokenList::create(emscripten::val v)
{
    return new DOMTokenList(v);
}

void DOMTokenList::add(std::vector<std::string> tokens)
{
    for (auto &token : tokens) {
        this->v.call<void>("add", token);
    }
}

bool DOMTokenList::contains(std::string token)
{
    return this->v.call<bool>("contains", token);
}

void DOMTokenList::remove(std::vector<std::string> tokens)
{
    for (auto &token : tokens) {
        this->v.call<void>("remove", token);
    }
}

bool DOMTokenList::toggle(std::string token, bool force)
{
    return this->v.call<bool>("toggle", token, force);
}

unsigned long DOMTokenList::getLength()
{
    return this->v["length"].as<unsigned long>();
}

void DOMTokenList::setLength(unsigned long value)
{
    this->_length = value;
    this->v.set("length", value);
}
