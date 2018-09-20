#pragma once

#include "libhtml5.h"

NAMESPACE_HTML5_BEGIN;

class IDBFactory;

class IDBEnvironment : public Object {
public:

    HTML5_PROPERTY(IDBEnvironment, IDBFactory *, indexedDB);

    IDBEnvironment(emscripten::val v);
    virtual ~IDBEnvironment();
    static IDBEnvironment *create(emscripten::val v);
};

NAMESPACE_HTML5_END;
