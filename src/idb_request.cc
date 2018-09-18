#include "dom_error.h"
#include "idb_transaction.h"
#include "idb_request.h"

IDBRequest::IDBRequest(emscripten::val v) :
    EventTarget(v)
{

}

IDBRequest::~IDBRequest()
{

}

IDBRequest *IDBRequest::create(emscripten::val v)
{
    auto req = new IDBRequest(v);
    req->autorelease();
    return req;
}


HTML5_PROPERTY_OBJECT_IMPL(IDBRequest, DOMError, error);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(IDBRequest, EventHandler *, onerror);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(IDBRequest, EventHandler *, onsuccess);
HTML5_PROPERTY_OBJECT_IMPL(IDBRequest, IDBTransaction, transaction);
