#pragma once

#include "event_target.h"

enum class IDBTransactionMode {
    READONLY,
    READWRITE,
    VERSIONCHANGE,
};

class IDBObjectStore;
class DOMError;
class IDBDatabase;

class IDBTransaction : public EventTarget {
public:
    HTML5_PROPERTY(IDBTransaction, IDBDatabase *, db);
    HTML5_PROPERTY(IDBTransaction, DOMError *, error);
    HTML5_EVENT_HANDLER_PROPERTY(IDBTransaction, EventHandler *, onabort);
    HTML5_EVENT_HANDLER_PROPERTY(IDBTransaction, EventHandler *, oncomplete);
    HTML5_EVENT_HANDLER_PROPERTY(IDBTransaction, EventHandler *, onerror);
    IDBTransactionMode _mode;
    
    IDBTransaction(emscripten::val v);
    virtual ~IDBTransaction();
    static IDBTransaction *create(emscripten::val v);
    void abort();
    IDBObjectStore *objectStore(std::string name);
};
