#include "html_head_element.h"

HTMLHeadElement::HTMLHeadElement(emscripten::val v) :
    HTMLElement(v)
{

}

HTMLHeadElement::~HTMLHeadElement()
{

}

HTMLHeadElement *HTMLHeadElement::create(emscripten::val v)
{
    auto elem = new HTMLHeadElement(v);
    elem->autorelease();
    return elem;
}
