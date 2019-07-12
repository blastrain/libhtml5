#pragma once

#include "html5.h"

NAMESPACE_HTML5_BEGIN;

class Location : public Object {
public:
    
    Location(emscripten::val v);
    virtual ~Location();
    static Location *create(emscripten::val v);
    void assign(std::string url);
    void reload();
    void replace(std::string url);
};

NAMESPACE_HTML5_END;
