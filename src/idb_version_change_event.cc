#include "idb_version_change_event.h"

USING_NAMESPACE_HTML5;

IDBVersionChangeEvent::IDBVersionChangeEvent(emscripten::val v) :
    Event(v)
{

}

IDBVersionChangeEvent::~IDBVersionChangeEvent()
{

}

IDBVersionChangeEvent *IDBVersionChangeEvent::create(emscripten::val v)
{
    auto version = new IDBVersionChangeEvent(v);
    version->autorelease();
    return version;
}

HTML5_PROPERTY_IMPL(IDBVersionChangeEvent, unsigned long long, newVersion);
HTML5_PROPERTY_IMPL(IDBVersionChangeEvent, unsigned long long, oldVersion);
