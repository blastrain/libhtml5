#pragma once

#include "html_element.h"

class HTMLSourceElement : public HTMLElement {
public:
    std::string _src;
    std::string _type;

    HTMLSourceElement(emscripten::val v);
    ~HTMLSourceElement();
    static HTMLSourceElement *create();
    static HTMLSourceElement *create(emscripten::val v);
    struct {
        HTMLSourceElement &self;
        void operator=(std::string v) { self.setType(v); };
        operator std::string() { return self.getType(); };
    } type{*this};
    struct {
        HTMLSourceElement &self;
        void operator=(std::string v) { self.setSrc(v); };
        operator std::string() { return self.getSrc(); };
    } src{*this};

private:
    std::string getType();
    void setType(std::string value);
    std::string getSrc();
    void setSrc(std::string value);
};
