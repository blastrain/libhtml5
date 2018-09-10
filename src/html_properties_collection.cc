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
    return new HTMLPropertiesCollection(v);
}
