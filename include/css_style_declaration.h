#pragma once

#include <emscripten/val.h>
#include <string>

class CSSRule;

class CSSStyleDeclaration {
public:
    emscripten::val v;
    std::string _cssFloat;
    std::string _cssText;
    unsigned long _length;
    CSSRule *_parentRule;

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

    std::string getCSSFloat() const;
    void setCSSFloat(std::string value);
    std::string getCSSText() const;
    void setCSSText(std::string value);
    unsigned long getLength() const;
    void setLength(unsigned long value);
    CSSRule *getParentRule() const;
    void setParentRule(CSSRule *value);

    struct {
        CSSStyleDeclaration &self;
        void operator=(std::string value) { self.setCSSFloat(value); };
        operator std::string() { return self.getCSSFloat(); };
    } cssFloat{*this};

    struct {
        CSSStyleDeclaration &self;
        void operator=(std::string value) { self.setCSSText(value); };
        operator std::string() { return self.getCSSText(); };
    } cssText{*this};

    struct {
        CSSStyleDeclaration &self;
        void operator=(unsigned long value) { self.setLength(value); };
        operator unsigned long() { return self.getLength(); };
    } length{*this};

    struct {
        CSSStyleDeclaration &self;
        void operator=(CSSRule *value) { self.setParentRule(value); };
        operator CSSRule *() { return self.getParentRule(); };
    } parentRule{*this};

};
