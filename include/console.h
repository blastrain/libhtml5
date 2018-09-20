#pragma once

#include "libhtml5.h"

NAMESPACE_HTML5_BEGIN;

class Console : public Object {
public:
    emscripten::val v;

    Console(emscripten::val v);
    virtual ~Console();
    static Console *create(emscripten::val v);
    void assert(bool expr, std::string ...args);
    void clear();
    void count();
    void count(std::string label);
    void countReset();
    void countReset(std::string label);
    void dir(Object *o);
};

NAMESPACE_HTML5_END;
