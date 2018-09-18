#pragma once

#include "libhtml5.h"

class Location : public Object {
public:
    emscripten::val v;
    
    Location(emscripten::val v);
    virtual ~Location();
    static Location *create(emscripten::val v);
    void assign(std::string url);
    void reload();
    void replace(std::string url);
};
