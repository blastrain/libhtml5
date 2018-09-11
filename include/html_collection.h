#pragma once

#include "libhtml5.h"

class Element;

class HTMLCollection : public Object {
public:
    emscripten::val v;
    unsigned long _length;

    HTMLCollection(emscripten::val v);
    virtual ~HTMLCollection();
    static HTMLCollection *create();
    static HTMLCollection *create(emscripten::val v);
    Element *item(unsigned long index);
    Element *namedItem(std::string name);

    struct {
        HTMLCollection &self;
        void operator=(unsigned long value) { self.setLength(value); };
        operator unsigned long() { return self.getLength(); };
    } length{*this};

private:
    unsigned long getLength();
    void setLength(unsigned long value);
};
