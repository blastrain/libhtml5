#include "event_handler.h"
#include "idb_open_db_request.h"

USING_NAMESPACE_HTML5;

HTML5_BIND_CLASS(IDBOpenDBRequest);

IDBOpenDBRequest::IDBOpenDBRequest(emscripten::val v) :
    IDBRequest(v)
{

}

IDBOpenDBRequest::~IDBOpenDBRequest()
{

}

IDBOpenDBRequest *IDBOpenDBRequest::create(emscripten::val v)
{
    auto req = new IDBOpenDBRequest(v);
    req->autorelease();
    return req;
}

HTML5_EVENT_HANDLER_PROPERTY_IMPL(IDBOpenDBRequest, EventHandler *, onblocked);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(IDBOpenDBRequest, EventHandler *, onupgradeneeded);
