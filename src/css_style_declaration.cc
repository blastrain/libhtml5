#include "css_rule.h"
#include "css_style_declaration.h"

USING_NAMESPACE_HTML5;

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

HTML5_PROPERTY_IMPL(CSSStyleDeclaration, std::string, cssFloat);
HTML5_PROPERTY_IMPL(CSSStyleDeclaration, std::string, cssText);
HTML5_PROPERTY_IMPL(CSSStyleDeclaration, unsigned long, length);
HTML5_PROPERTY_OBJECT_IMPL(CSSStyleDeclaration, CSSRule, parentRule);
