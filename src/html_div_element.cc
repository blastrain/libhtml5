#include "html_div_element.h"

USING_NAMESPACE_HTML5;

HTML5_BIND_CLASS(HTMLDivElement);

HTMLDivElement::HTMLDivElement(emscripten::val v) :
    HTMLElement(v)
{

}

HTMLDivElement::~HTMLDivElement()
{

}

HTMLDivElement *HTMLDivElement::create(emscripten::val v)
{
    HTMLDivElement *e = new HTMLDivElement(v);
    e->autorelease();
    return e;
}
