#pragma once

#include "event_target.h"
#include "idb_transaction.h"

NAMESPACE_HTML5_BEGIN;

class IDBObjectStore;

class IDBDatabase : public EventTarget {
public:

    HTML5_PROPERTY(IDBDatabase, std::string, name);
    HTML5_EVENT_HANDLER_PROPERTY(IDBDatabase, EventHandler *, onabort);
    HTML5_EVENT_HANDLER_PROPERTY(IDBDatabase, EventHandler *, onerror);
    HTML5_EVENT_HANDLER_PROPERTY(IDBDatabase, EventHandler *, onversionchange);
    HTML5_PROPERTY(IDBDatabase, unsigned long long, version);

    IDBDatabase(emscripten::val v);
    virtual ~IDBDatabase();
    static IDBDatabase *create(emscripten::val v);
    void close();
    IDBObjectStore *createObjectStore(std::string name);
    void deleteObjectStore(std::string name);
    IDBTransaction *transaction(std::string storeName, IDBTransactionMode mode);
    IDBTransaction *transaction(std::vector<std::string> storeNames, IDBTransactionMode mode);
};

NAMESPACE_HTML5_END;
