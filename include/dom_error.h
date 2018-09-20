#pragma once

#include "libhtml5.h"

NAMESPACE_HTML5_BEGIN;

class DOMError : public Object {
public:

    HTML5_PROPERTY(DOMError, std::string, message);
    HTML5_PROPERTY(DOMError, std::string, name);

    DOMError(emscripten::val v);
    virtual ~DOMError();
    static DOMError *create(emscripten::val v);
};

NAMESPACE_HTML5_END;
