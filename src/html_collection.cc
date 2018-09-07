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
    return new HTMLCollection(v);
}

HTMLCollection *HTMLCollection::create()
{
    emscripten::val klass = emscripten::val::global("HTMLCollection");
    emscripten::val v = klass.new_();
    HTMLCollection *c = new HTMLCollection(v);
    return c;
}

Element *HTMLCollection::item(unsigned long index)
{
    return Element::create(this->v.call<emscripten::val>("item", index));
}

Element *HTMLCollection::namedItem(std::string name)
{
    return Element::create(this->v.call<emscripten::val>("namedItem", name));
}

unsigned long HTMLCollection::getLength()
{
    return this->v["length"].as<unsigned long>();
}

void HTMLCollection::setLength(unsigned long value)
{
    this->_length = value;
    this->v.set("length", value);
}
