#pragma once

#include "libhtml5.h"

class External : public Object {
public:
    emscripten::val v;

    External(emscripten::val v);
    virtual ~External();
    static External *create(emscripten::val v);
    void AddSearchProvider(std::string engineURL);
    unsigned long IsSearchProviderInstalled(std::string engineURL);
};
