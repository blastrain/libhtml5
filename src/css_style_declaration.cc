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
    return HTML5_CALLs(this->v, getPropertyPriority, property);
}

std::string CSSStyleDeclaration::getPropertyValue(std::string property)
{
    return HTML5_CALLs(this->v, getPropertyValue, property);
}
   
std::string CSSStyleDeclaration::item(unsigned long index)
{
    return HTML5_CALLs(this->v, item, index);
}

std::string CSSStyleDeclaration::removeProperty(std::string property)
{
    return HTML5_CALLs(this->v, removeProperty, property);
}

void CSSStyleDeclaration::setProperty(std::string property, std::string value, std::string priority)
{
    HTML5_CALL(this->v, setProperty, property, value, priority);
}

void CSSStyleDeclaration::setPropertyPriority(std::string property, std::string priority)
{
    HTML5_CALL(this->v, setPropertyPriority, property, priority);
}

void CSSStyleDeclaration::setPropertyValue(std::string property, std::string value)
{
    HTML5_CALL(this->v, setPropertyValue, property, value);
}

std::string CSSStyleDeclaration::getCSSFloat() const
{
    return HTML5_PROPERTY_GET(cssFloat, std::string);
}

void CSSStyleDeclaration::setCSSFloat(std::string value)
{
    this->_cssFloat = value;
    this->v.set("cssFloat", value);
}

std::string CSSStyleDeclaration::getCSSText() const
{
    return HTML5_PROPERTY_GET(cssText, std::string);
}

void CSSStyleDeclaration::setCSSText(std::string value)
{
    this->_cssText = value;
    this->v.set("cssText", value);
}

unsigned long CSSStyleDeclaration::getLength() const
{
    return HTML5_PROPERTY_GET(length, unsigned long);
}

void CSSStyleDeclaration::setLength(unsigned long value)
{
    this->_length = value;
    this->v.set("length", value);
}

CSSRule *CSSStyleDeclaration::getParentRule() const
{
    return HTML5_PROPERTY_GET(parentRule, CSSRule);
}

void CSSStyleDeclaration::setParentRule(CSSRule *value)
{
    this->_parentRule = value;
    this->v.set("parentRule", value->v);
}

