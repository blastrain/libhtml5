#pragma once

#include "html5.h"

NAMESPACE_HTML5_BEGIN;

class IDBIndexParameters : public Object {
public:

    HTML5_PROPERTY(IDBIndexParameters, bool, multiEntry);
    HTML5_PROPERTY(IDBIndexParameters, bool, unique);

    IDBIndexParameters(emscripten::val v);
    virtual ~IDBIndexParameters();
    static IDBIndexParameters *create(emscripten::val v);
};

NAMESPACE_HTML5_END;
