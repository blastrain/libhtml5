#pragma once

#include "libhtml5.h"

class DOMError : public Object {
public:
    emscripten::val v;

    HTML5_PROPERTY(DOMError, std::string, message);
    HTML5_PROPERTY(DOMError, std::string, name);

    DOMError(emscripten::val v);
    virtual ~DOMError();
    static DOMError *create(emscripten::val v);
};
