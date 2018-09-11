#include "css_rule.h"
#include "css_style_declaration.h"

CSSStyleDeclaration::CSSStyleDeclaration(emscripten::val v) : v(v)
{

}

CSSStyleDeclaration::~CSSStyleDeclaration()
{

}

CSSStyleDeclaration *CSSStyleDeclaration::create(emscripten::val v)
{
    CSSStyleDeclaration *decl = new CSSStyleDeclaration(v);
    decl->autorelease();
    return decl;
}

std::string CSSStyleDeclaration::getPropertyPriority(std::string property)
{
    return this->v.call<std::string>("getPropertyPriority", property);
}

std::string CSSStyleDeclaration::getPropertyValue(std::string property)
{
    return this->v.call<std::string>("getPropertyValue", property);
}
   
std::string CSSStyleDeclaration::item(unsigned long index)
{
    return this->v.call<std::string>("item", index);
}

std::string CSSStyleDeclaration::removeProperty(std::string property)
{
    return this->v.call<std::string>("removeProperty", property);
}

void CSSStyleDeclaration::setProperty(std::string property, std::string value, std::string priority)
{
    this->v.call<void>("setProperty", property, value, priority);
}

void CSSStyleDeclaration::setPropertyPriority(std::string property, std::string priority)
{
    this->v.call<void>("setPropertyPriority", property, priority);
}

void CSSStyleDeclaration::setPropertyValue(std::string property, std::string value)
{
    this->v.call<void>("setPropertyValue", property, value);
}

std::string CSSStyleDeclaration::getCSSFloat() const
{
    return this->v["cssFloat"].as<std::string>();
}

void CSSStyleDeclaration::setCSSFloat(std::string value)
{
    this->_cssFloat = value;
    this->v.set("cssFloat", value);
}

std::string CSSStyleDeclaration::getCSSText() const
{
    return this->v["cssText"].as<std::string>();
}

void CSSStyleDeclaration::setCSSText(std::string value)
{
    this->_cssText = value;
    this->v.set("cssText", value);
}

unsigned long CSSStyleDeclaration::getLength() const
{
    return this->v["length"].as<unsigned long>();
}

void CSSStyleDeclaration::setLength(unsigned long value)
{
    this->_length = value;
    this->v.set("length", value);
}

CSSRule *CSSStyleDeclaration::getParentRule() const
{
    return this->_parentRule;
}

void CSSStyleDeclaration::setParentRule(CSSRule *value)
{
    this->_parentRule = value;
    this->v.set("parentRule", value->v);
}

