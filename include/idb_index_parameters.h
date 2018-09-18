#pragma once

#include "libhtml5.h"

class IDBIndexParameters : public Object {
public:
    emscripten::val v;

    HTML5_PROPERTY(IDBIndexParameters, bool, multiEntry);
    HTML5_PROPERTY(IDBIndexParameters, bool, unique);

    IDBIndexParameters(emscripten::val v);
    virtual ~IDBIndexParameters();
    static IDBIndexParameters *create(emscripten::val v);
};
