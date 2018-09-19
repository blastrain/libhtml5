#include "html_properties_collection.h"

HTMLPropertiesCollection::HTMLPropertiesCollection(emscripten::val v) :
    HTMLCollection(v)
{

}

HTMLPropertiesCollection::~HTMLPropertiesCollection()
{

}

HTMLPropertiesCollection *HTMLPropertiesCollection::create(emscripten::val v)
{
    auto c = new HTMLPropertiesCollection(v);
    c->autorelease();
    return c;
}
