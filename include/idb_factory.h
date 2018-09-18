#pragma once

#include "libhtml5.h"

class IDBOpenDBRequest;

class IDBFactory : public Object {
public:
    emscripten::val v;

    IDBFactory(emscripten::val v);
    virtual ~IDBFactory();
    static IDBFactory *create(emscripten::val v);
    short cmp(int a, int b);
    IDBOpenDBRequest *deleteDatabase(std::string name);
    IDBOpenDBRequest *open(std::string name, unsigned long long version);
};
