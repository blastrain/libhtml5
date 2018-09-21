#pragma once

#include "libhtml5.h"

NAMESPACE_HTML5_BEGIN;

class Storage : public Object {
public:

    HTML5_PROPERTY(Storage, unsigned long, length);

    Storage(emscripten::val v);
    virtual ~Storage();
    static Storage *create(emscripten::val v);
    void clear();
    std::string getItem(std::string key);
    std::string key(unsigned long index);
    void removeItem(std::string key);
    void setItem(std::string key, std::string value);
};

NAMESPACE_HTML5_END;
