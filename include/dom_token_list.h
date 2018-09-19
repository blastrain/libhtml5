#pragma once

#include "libhtml5.h"
#include <vector>

NAMESPACE_HTML5_BEGIN;

class DOMTokenList : public Object {
public:
    emscripten::val v;

    HTML5_PROPERTY(DOMTokenList, unsigned long, length);

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
};

NAMESPACE_HTML5_END;
