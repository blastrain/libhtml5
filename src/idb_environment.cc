#include "idb_factory.h"
#include "idb_environment.h"

USING_NAMESPACE_HTML5;

IDBEnvironment::IDBEnvironment(emscripten::val v) :
    Object(v)
{

}

IDBEnvironment::~IDBEnvironment()
{

}

IDBEnvironment *IDBEnvironment::create(emscripten::val v)
{
    auto env = new IDBEnvironment(v);
    env->autorelease();
    return env;
}

HTML5_PROPERTY_OBJECT_IMPL(IDBEnvironment, IDBFactory, indexedDB);
