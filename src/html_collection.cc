#include "element.h"
#include "html_collection.h"

HTMLCollection::HTMLCollection(emscripten::val v) : v(v)
{

}

HTMLCollection::~HTMLCollection()
{


}

HTMLCollection *HTMLCollection::create(emscripten::val v)
{
    HTMLCollection *c = new HTMLCollection(v);
    c->autorelease();
    return c;
}

HTMLCollection *HTMLCollection::create()
{
    HTMLCollection *c = new HTMLCollection(HTML5_NEW_PRIMITIVE_INSTANCE(HTMLCollection));
    c->autorelease();
    return c;
}

Element *HTMLCollection::item(unsigned long index)
{
    return Element::create(HTML5_CALLv(this->v, item, index));
}

Element *HTMLCollection::namedItem(std::string name)
{
    return Element::create(HTML5_CALLv(this->v, namedItem, name));
}

unsigned long HTMLCollection::getLength()
{
    return HTML5_PROPERTY_GET(length, unsigned long);
}

void HTMLCollection::setLength(unsigned long value)
{
    this->_length = value;
    this->v.set("length", value);
}
