#pragma once

#include "html5.h"

NAMESPACE_HTML5_BEGIN;

class Plugin;

class PluginArray : public Object {
public:

    HTML5_PROPERTY(PluginArray, unsigned long, length);

    PluginArray(emscripten::val v);
    virtual ~PluginArray();
    static PluginArray *create(emscripten::val v);
    Plugin *item(unsigned long index);
    Plugin *namedItem(std::string name);
    void refresh(bool reload);
};

NAMESPACE_HTML5_END;
