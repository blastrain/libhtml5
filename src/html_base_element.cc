#include "html_base_element.h"

USING_NAMESPACE_HTML5;

HTMLBaseElement::HTMLBaseElement(emscripten::val v) :
    HTMLElement(v)
{

}

HTMLBaseElement::~HTMLBaseElement()
{

}

HTMLBaseElement *HTMLBaseElement::create(emscripten::val v)
{
    HTMLBaseElement *e = new HTMLBaseElement(v);
    e->autorelease();
    return e;
}

HTML5_PROPERTY_IMPL(HTMLBaseElement, std::string, href);
HTML5_PROPERTY_IMPL(HTMLBaseElement, std::string, target);