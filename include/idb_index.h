#pragma once

#include "libhtml5.h"

NAMESPACE_HTML5_BEGIN;

class IDBObjectStore;
class IDBRequest;

class IDBIndex : public Object {
public:
    emscripten::val v;

    HTML5_PROPERTY(IDBIndex, std::string, keyPath);
    HTML5_PROPERTY(IDBIndex, bool, multiEntry);
    HTML5_PROPERTY(IDBIndex, std::string, name);
    HTML5_PROPERTY(IDBIndex, IDBObjectStore *, objectStore);
    HTML5_PROPERTY(IDBIndex, bool, unique);

    IDBIndex(emscripten::val v);
    virtual ~IDBIndex();
    static IDBIndex *create(emscripten::val v);
    IDBRequest *count(int key);
    IDBRequest *get(int key);
    IDBRequest *getKey(int key);
};

NAMESPACE_HTML5_END;
