#pragma once

#include "libhtml5.h"

class IDBFactory;

class IDBEnvironment : public Object {
public:
    emscripten::val v;

    HTML5_PROPERTY(IDBEnvironment, IDBFactory *, indexedDB);

    IDBEnvironment(emscripten::val v);
    virtual ~IDBEnvironment();
    static IDBEnvironment *create(emscripten::val v);
};
