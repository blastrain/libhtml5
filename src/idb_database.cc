#include "idb_transaction.h"
#include "idb_object_store.h"
#include "idb_database.h"

HTML5_BIND_CLASS(IDBDatabase);

IDBDatabase::IDBDatabase(emscripten::val v) :
    EventTarget(v)
{

}

IDBDatabase::~IDBDatabase()
{

}

IDBDatabase *IDBDatabase::create(emscripten::val v)
{
    auto db = new IDBDatabase(v);
    db->autorelease();
    return db;
}

void IDBDatabase::close()
{
    HTML5_CALL(this->v, close);
}

IDBObjectStore *IDBDatabase::createObjectStore(std::string name)
{
    return IDBObjectStore::create(HTML5_CALLv(this->v, createObjectStore, name));
}

void IDBDatabase::deleteObjectStore(std::string name)
{
    HTML5_CALL(this->v, deleteObjectStore, name);
}

IDBTransaction *IDBDatabase::transaction(std::string storeName, IDBTransactionMode mode)
{
    return IDBTransaction::create(HTML5_CALLv(this->v, transaction, storeName, mode));
}

IDBTransaction *IDBDatabase::transaction(std::vector<std::string> storeNames, IDBTransactionMode mode)
{
    return IDBTransaction::create(HTML5_CALLv(this->v, transaction, toJSArray<std::string>(storeNames), mode));
}

HTML5_PROPERTY_IMPL(IDBDatabase, std::string, name);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(IDBDatabase, EventHandler *, onabort);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(IDBDatabase, EventHandler *, onerror);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(IDBDatabase, EventHandler *, onversionchange);
HTML5_PROPERTY_IMPL(IDBDatabase, unsigned long long, version);
