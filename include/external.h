#pragma once

#include "html5.h"

NAMESPACE_HTML5_BEGIN;

class External : public Object {
public:

    External(emscripten::val v);
    virtual ~External();
    static External *create(emscripten::val v);
    void AddSearchProvider(std::string engineURL);
    unsigned long IsSearchProviderInstalled(std::string engineURL);
};

NAMESPACE_HTML5_END;
