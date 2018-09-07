#include "html_element.h"

HTMLElement::HTMLElement(emscripten::val v) :
    Element(v)
{

}

HTMLElement::~HTMLElement()
{

}

HTMLElement *HTMLElement::create(emscripten::val v)
{
    return new HTMLElement(v);
}
