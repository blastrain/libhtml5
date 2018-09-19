#include "attr.h"

USING_NAMESPACE_HTML5;

Attr::Attr(emscripten::val v) : v(v)
{

}

Attr::~Attr()
{

}

Attr *Attr::create(emscripten::val v)
{
    Attr *attr = new Attr(v);
    attr->autorelease();
    return attr;
}

Attr *Attr::create()
{
    return create(HTML5_NEW_PRIMITIVE_INSTANCE(Attr));
}

HTML5_PROPERTY_IMPL(Attr, std::string, localName);
HTML5_PROPERTY_IMPL(Attr, std::string, name);
HTML5_PROPERTY_IMPL(Attr, std::string, namespaceURI);
HTML5_PROPERTY_IMPL(Attr, std::string, prefix);
HTML5_PROPERTY_IMPL(Attr, bool, specified);
HTML5_PROPERTY_IMPL(Attr, std::string, value);
