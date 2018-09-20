#pragma once

#include "libhtml5.h"

NAMESPACE_HTML5_BEGIN;

class CSSRule;

class CSSStyleDeclaration : public Object {
public:

    HTML5_PROPERTY(CSSStyleDeclaration, std::string, cssFloat);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, cssText);
    HTML5_PROPERTY(CSSStyleDeclaration, unsigned long, length);
    HTML5_PROPERTY_OBJECT(CSSStyleDeclaration, CSSRule, parentRule);

    CSSStyleDeclaration(emscripten::val v);
    virtual ~CSSStyleDeclaration();
    static CSSStyleDeclaration *create(emscripten::val v);
    std::string getPropertyPriority(std::string property);
    std::string getPropertyValue(std::string property);
    std::string item(unsigned long index);
    std::string removeProperty(std::string property);
    void setProperty(std::string property, std::string value, std::string priority = "");
    void setPropertyPriority(std::string property, std::string priority);
    void setPropertyValue(std::string property, std::string value);
};

NAMESPACE_HTML5_END;
