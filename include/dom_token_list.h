#pragma once

#include "object.h"
#include <emscripten/val.h>
#include <string>
#include <vector>

class DOMTokenList : public Object {
public:
    emscripten::val v;
    unsigned long _length;

    DOMTokenList(emscripten::val v);
    virtual ~DOMTokenList();
    static DOMTokenList *create(emscripten::val v);
    template<typename... Args> void add(Args ...args) {
        std::vector<std::string> tokens = { args... };
        add(tokens);
    };
    void add(std::vector<std::string> tokens);
    bool contains(std::string token);
    std::string item(unsigned long index);
    template<typename... Args> void remove(Args ...args) {
        std::vector<std::string> tokens = { args... };
        remove(tokens);
    };
    void remove(std::vector<std::string> tokens);
    bool toggle(std::string token, bool force = false);

    struct {
        DOMTokenList &self;
        void operator=(unsigned long value) { self.setLength(value); };
        operator unsigned long() { return self.getLength(); };
    } length{*this};

private:
    unsigned long getLength();
    void setLength(unsigned long value);
};
