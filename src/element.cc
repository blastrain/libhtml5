#include "element.h"

Element::Element(emscripten::val v) :
    Node(v)
{

}

Element::~Element()
{

}

Element *Element::create(emscripten::val v)
{
    Element *e = new Element(v);
    return e;
}

void Element::setAttribute(std::string qualifiedName, std::string value)
{

}
