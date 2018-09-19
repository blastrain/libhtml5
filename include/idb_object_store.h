#pragma once

#include "libhtml5.h"

NAMESPACE_HTML5_BEGIN;

class IDBRequest;
class IDBIndex;
class IDBTransaction;

class IDBObjectStore : public Object {
public:
    emscripten::val v;

    HTML5_PROPERTY(IDBObjectStore, bool, autoIncrement);
    HTML5_PROPERTY(IDBObjectStore, std::string, keyPath);
    HTML5_PROPERTY(IDBObjectStore, std::string, name);
    HTML5_PROPERTY(IDBObjectStore, IDBTransaction *, transaction);

    IDBObjectStore(emscripten::val v);
    virtual ~IDBObjectStore();
    static IDBObjectStore *create(emscripten::val v);
    IDBRequest *add(int value, std::string key);
    IDBRequest *clear();
    IDBRequest *count(int key);
    IDBIndex *createIndex(std::string name, std::string keyPath);
    IDBIndex *createIndex(std::string name, std::vector<std::string> keyPath);
    IDBRequest *deleteWithKey(int key);
    void deleteIndex(std::string indexName);
    IDBRequest *get(int key);
    IDBIndex *index(std::string name);
    IDBRequest *put(int value, int key);
};

NAMESPACE_HTML5_END;
