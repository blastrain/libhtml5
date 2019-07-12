#pragma once

#include "html5.h"

NAMESPACE_HTML5_BEGIN;

class Plugin;

class MimeType : public Object {
public:

    HTML5_PROPERTY(MimeType, std::string, description);
    HTML5_PROPERTY(MimeType, Plugin *, enabledPlugin);
    HTML5_PROPERTY(MimeType, std::string, suffixes);
    HTML5_PROPERTY(MimeType, std::string, type);

    MimeType(emscripten::val v);
    virtual ~MimeType();
    static MimeType *create(emscripten::val v);
};

NAMESPACE_HTML5_END;
