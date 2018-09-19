#include "dom_error.h"
#include "idb_database.h"
#include "idb_object_store.h"
#include "idb_transaction.h"

HTML5_BIND_CLASS(IDBTransaction);

IDBTransaction::IDBTransaction(emscripten::val v) :
    EventTarget(v)
{

}

IDBTransaction::~IDBTransaction()
{

}

IDBTransaction *IDBTransaction::create(emscripten::val v)
{
    auto tx = new IDBTransaction(v);
    tx->autorelease();
    return tx;
}

void IDBTransaction::abort()
{
    HTML5_CALL(this->v, abort);
}

IDBObjectStore *IDBTransaction::objectStore(std::string name)
{
    return IDBObjectStore::create(HTML5_CALLv(this->v, objectStore, name));
}

HTML5_PROPERTY_OBJECT_IMPL(IDBTransaction, IDBDatabase, db);
HTML5_PROPERTY_OBJECT_IMPL(IDBTransaction, DOMError, error);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(IDBTransaction, EventHandler *, onabort);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(IDBTransaction, EventHandler *, oncomplete);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(IDBTransaction, EventHandler *, onerror);
