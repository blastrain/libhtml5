#pragma once

#include "libhtml5.h"

class Plugin;

class PluginArray : public Object {
public:
    emscripten::val v;

    HTML5_PROPERTY(PluginArray, unsigned long, length);

    PluginArray(emscripten::val v);
    virtual ~PluginArray();
    static PluginArray *create(emscripten::val v);
    Plugin *item(unsigned long index);
    Plugin *namedItem(std::string name);
    void refresh(bool reload);
};
