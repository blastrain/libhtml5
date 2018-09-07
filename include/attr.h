#pragma once

#include <string>
#include <emscripten/val.h>

class Attr {
public:
    emscripten::val v;
    std::string _localName;
    std::string _name;
    std::string _namespaceURI;
    std::string _prefix;
    bool _specified;
    std::string _value;

    Attr(emscripten::val v);
    virtual ~Attr();
    static Attr *create(emscripten::val v);
    static Attr *create();

    struct {
        Attr &self;
        void operator=(std::string value) { self.setLocalName(value); };
        operator std::string() { return self.getLocalName(); };
    } localName{*this};

    struct {
        Attr &self;
        void operator=(std::string value) { self.setName(value); };
        operator std::string() { return self.getName(); };
    } name{*this};

    struct {
        Attr &self;
        void operator=(std::string value) { self.setNamespaceURI(value); };
        operator std::string() { return self.getNamespaceURI(); };
    } namespaceURI{*this};

    struct {
        Attr &self;
        void operator=(std::string value) { self.setPrefix(value); };
        operator std::string() { return self.getPrefix(); };
    } prefix{*this};

    struct {
        Attr &self;
        void operator=(bool value) { self.setSpecified(value); };
        operator bool() { return self.getSpecified(); };
    } specified{*this};

    struct {
        Attr &self;
        void operator=(std::string value) { self.setValue(value); };
        operator std::string() { return self.getValue(); };
    } value{*this};

private:
    std::string getLocalName();
    void setLocalName(std::string value);
    std::string getName();
    void setName(std::string value);
    std::string getNamespaceURI();
    void setNamespaceURI(std::string value);
    std::string getPrefix();
    void setPrefix(std::string value);
    bool getSpecified();
    void setSpecified(bool value);
    std::string getValue();
    void setValue(std::string value);
};
