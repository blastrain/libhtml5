#include "attr.h"

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
    emscripten::val v = HTML5_NEW_PRIMITIVE_INSTANCE(Attr);
    Attr *attr = new Attr(v);
    attr->autorelease();
    return attr;
}

std::string Attr::getLocalName()
{
    return HTML5_PROPERTY_GET(localName, std::string);
}

void Attr::setLocalName(std::string value)
{
    this->_localName = value;
    this->v.set("localName", value);
}

std::string Attr::getName()
{
    return HTML5_PROPERTY_GET(name, std::string);
}

void Attr::setName(std::string value)
{
    this->_name = value;
    this->v.set("name", value);
}

std::string Attr::getNamespaceURI()
{
    return HTML5_PROPERTY_GET(namespaceURI, std::string);
}

void Attr::setNamespaceURI(std::string value)
{
    this->_namespaceURI = value;
    this->v.set("namespaceURI", value);
}

std::string Attr::getPrefix()
{
    return HTML5_PROPERTY_GET(prefix, std::string);
}

void Attr::setPrefix(std::string value)
{
    this->_prefix = value;
    this->v.set("prefix", value);
}

bool Attr::getSpecified()
{
    return HTML5_PROPERTY_GET(specified, bool);
}

void Attr::setSpecified(bool value)
{
    this->_specified = value;
    this->v.set("specified", value);
}

std::string Attr::getValue()
{
    return HTML5_PROPERTY_GET(value, std::string);
}

void Attr::setValue(std::string value)
{
    this->_value = value;
    this->v.set("value", value);
}

