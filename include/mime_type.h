#pragma once

#include "libhtml5.h"

class Plugin;

class MimeType : public Object {
public:
    emscripten::val v;

    HTML5_PROPERTY(MimeType, std::string, description);
    HTML5_PROPERTY(MimeType, Plugin *, enabledPlugin);
    HTML5_PROPERTY(MimeType, std::string, suffixes);
    HTML5_PROPERTY(MimeType, std::string, type);

    MimeType(emscripten::val v);
    virtual ~MimeType();
    static MimeType *create(emscripten::val v);
};
