#include "idb_factory.h"
#include "idb_environment.h"

IDBEnvironment::IDBEnvironment(emscripten::val v) :
    Object(),
    v(v)
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
