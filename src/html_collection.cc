#include "element.h"
#include "html_collection.h"

USING_NAMESPACE_HTML5;

HTMLCollection::HTMLCollection(emscripten::val v) :
    Object(v)
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

HTML5_PROPERTY_IMPL(HTMLCollection, unsigned long, length);
