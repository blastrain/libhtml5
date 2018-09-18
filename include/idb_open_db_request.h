#pragma once

#include "idb_request.h"

class IDBOpenDBRequest : public IDBRequest {
public:

    HTML5_EVENT_HANDLER_PROPERTY(IDBOpenDBRequest, EventHandler *, onblocked);
    HTML5_EVENT_HANDLER_PROPERTY(IDBOpenDBRequest, EventHandler *, onupgradeneeded);

    IDBOpenDBRequest(emscripten::val v);
    virtual ~IDBOpenDBRequest();
    static IDBOpenDBRequest *create(emscripten::val v);
};
