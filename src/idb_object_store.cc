#include "idb_transaction.h"
#include "idb_request.h"
#include "idb_index.h"
#include "idb_object_store.h"

USING_NAMESPACE_HTML5;

IDBObjectStore::IDBObjectStore(emscripten::val v) :
    Object(v)
{

}

IDBObjectStore::~IDBObjectStore()
{

}

IDBObjectStore *IDBObjectStore::create(emscripten::val v)
{
    auto store = new IDBObjectStore(v);
    store->autorelease();
    return store;
}

IDBRequest *IDBObjectStore::add(int value, std::string key)
{
    return IDBRequest::create(HTML5_CALLv(this->v, add, value, key));
}
    
IDBRequest *IDBObjectStore::clear()
{
    return IDBRequest::create(HTML5_CALLv(this->v, clear));
}

IDBRequest *IDBObjectStore::count(int key)
{
    return IDBRequest::create(HTML5_CALLv(this->v, count, key));
}

IDBIndex *IDBObjectStore::createIndex(std::string name, std::string keyPath)
{
    return IDBIndex::create(HTML5_CALLv(this->v, cleateIndex, name, keyPath));
}

IDBIndex *IDBObjectStore::createIndex(std::string name, std::vector<std::string> keyPath)
{
    return IDBIndex::create(HTML5_CALLv(this->v, cleateIndex, name, toJSArray<std::string>(keyPath)));
}

IDBRequest *IDBObjectStore::deleteWithKey(int key)
{
    return IDBRequest::create(HTML5_CALLv(this->v, delete, key));
}

void IDBObjectStore::deleteIndex(std::string indexName)
{
    HTML5_CALL(this->v, deleteIndex, indexName);
}

IDBRequest *IDBObjectStore::get(int key)
{
    return IDBRequest::create(HTML5_CALLv(this->v, get, key));
}

IDBIndex *IDBObjectStore::index(std::string name)
{
    return IDBIndex::create(HTML5_CALLv(this->v, index, name));
}

IDBRequest *IDBObjectStore::put(int value, int key)
{
    return IDBRequest::create(HTML5_CALLv(this->v, put, value, key));
}

HTML5_PROPERTY_IMPL(IDBObjectStore, bool, autoIncrement);
HTML5_PROPERTY_IMPL(IDBObjectStore, std::string, keyPath);
HTML5_PROPERTY_IMPL(IDBObjectStore, std::string, name);
HTML5_PROPERTY_OBJECT_IMPL(IDBObjectStore, IDBTransaction, transaction);
