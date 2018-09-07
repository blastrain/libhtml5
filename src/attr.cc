#include "attr.h"

Attr::Attr(emscripten::val v) : v(v)
{

}

Attr::~Attr()
{

}

Attr *Attr::create(emscripten::val v)
{
    return new Attr(v);
}

Attr *Attr::create()
{
    emscripten::val _Attr = emscripten::val::global("Attr");
    emscripten::val v = _Attr.new_();
    return new Attr(v);
}

std::string Attr::getLocalName()
{
    return this->v["localName"].as<std::string>();
}

void Attr::setLocalName(std::string value)
{
    this->_localName = value;
    this->v.set("localName", value);
}

std::string Attr::getName()
{
    return this->v["name"].as<std::string>();
}

void Attr::setName(std::string value)
{
    this->_name = value;
    this->v.set("name", value);
}

std::string Attr::getNamespaceURI()
{
    return this->v["namespaceURI"].as<std::string>();
}

void Attr::setNamespaceURI(std::string value)
{
    this->_namespaceURI = value;
    this->v.set("namespaceURI", value);
}

std::string Attr::getPrefix()
{
    return this->v["prefix"].as<std::string>();
}

void Attr::setPrefix(std::string value)
{
    this->_prefix = value;
    this->v.set("prefix", value);
}

bool Attr::getSpecified()
{
    return this->v["specified"].as<bool>();
}

void Attr::setSpecified(bool value)
{
    this->_specified = value;
    this->v.set("specified", value);
}

std::string Attr::getValue()
{
    return this->v["value"].as<std::string>();
}

void Attr::setValue(std::string value)
{
    this->_value = value;
    this->v.set("value", value);
}

