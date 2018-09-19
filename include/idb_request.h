#pragma once

#include "event_target.h"

NAMESPACE_HTML5_BEGIN;

enum class IDBRequestReadyState {
    PENDING,
    DONE,
};

class DOMError;
class IDBTransaction;

class IDBRequest : public EventTarget {
public:

    HTML5_PROPERTY(IDBRequest, DOMError *, error);
    HTML5_EVENT_HANDLER_PROPERTY(IDBRequest, EventHandler *, onerror);
    HTML5_EVENT_HANDLER_PROPERTY(IDBRequest, EventHandler *, onsuccess);
    HTML5_PROPERTY(IDBRequest, IDBTransaction *, transaction);
    void *_result;
    void *_source;
    IDBRequestReadyState _readyState;

    IDBRequest(emscripten::val v);
    virtual ~IDBRequest();
    static IDBRequest *create(emscripten::val v);
};

NAMESPACE_HTML5_END;
