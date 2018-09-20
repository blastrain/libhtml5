#include "idb_open_db_request.h"
#include "idb_factory.h"

USING_NAMESPACE_HTML5;

IDBFactory::IDBFactory(emscripten::val v) :
    Object(v)
{

}

IDBFactory::~IDBFactory()
{

}

IDBFactory *IDBFactory::create(emscripten::val v)
{
    auto factory = new IDBFactory(v);
    factory->autorelease();
    return factory;
}

short IDBFactory::cmp(int a, int b)
{
    return HTML5_CALLi(this->v, cmp, short, a, b);
}

IDBOpenDBRequest *IDBFactory::deleteDatabase(std::string name)
{
    return IDBOpenDBRequest::create(HTML5_CALLv(this->v, deleteDatabase, name));
}

IDBOpenDBRequest *IDBFactory::open(std::string name, unsigned long long version)
{
    return IDBOpenDBRequest::create(HTML5_CALLv(this->v, open, name, version));
}
