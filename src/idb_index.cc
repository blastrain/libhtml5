#include "idb_object_store.h"
#include "idb_request.h"
#include "idb_index.h"

USING_NAMESPACE_HTML5;

IDBIndex::IDBIndex(emscripten::val v) :
    Object(v)
{

}

IDBIndex::~IDBIndex()
{

}

IDBIndex *IDBIndex::create(emscripten::val v)
{
    auto idx = new IDBIndex(v);
    idx->autorelease();
    return idx;
}

IDBRequest *IDBIndex::count(int key)
{
    return IDBRequest::create(HTML5_CALLv(this->v, count, key));
}

IDBRequest *IDBIndex::get(int key)
{
    return IDBRequest::create(HTML5_CALLv(this->v, get, key));
}

IDBRequest *IDBIndex::getKey(int key)
{
    return IDBRequest::create(HTML5_CALLv(this->v, getKey, key));
}

HTML5_PROPERTY_IMPL(IDBIndex, std::string, keyPath);
HTML5_PROPERTY_IMPL(IDBIndex, bool, multiEntry);
HTML5_PROPERTY_IMPL(IDBIndex, std::string, name);
HTML5_PROPERTY_OBJECT_IMPL(IDBIndex, IDBObjectStore, objectStore);
HTML5_PROPERTY_IMPL(IDBIndex, bool, unique);
