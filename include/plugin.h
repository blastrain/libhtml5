#pragma once

#include "libhtml5.h"

NAMESPACE_HTML5_BEGIN;

class MimeType;

class Plugin : public Object {
public:

    HTML5_PROPERTY(Plugin, std::string, description);
    HTML5_PROPERTY(Plugin, std::string, filename);
    HTML5_PROPERTY(Plugin, unsigned long, length);
    HTML5_PROPERTY(Plugin, std::string, name);

    Plugin(emscripten::val v);
    virtual ~Plugin();
    static Plugin *create(emscripten::val v);
    MimeType *item(unsigned long index);
    MimeType *namedItem(std::string name);
};

NAMESPACE_HTML5_END;
