#include "libhtml5.h"
#include "object.h"
#include "auto_release_pool.h"

USING_NAMESPACE_HTML5;

static AutoReleasePool g_sharedInstance;

AutoReleasePool::AutoReleasePool()
{

}

AutoReleasePool::~AutoReleasePool()
{

}

AutoReleasePool *AutoReleasePool::sharedInstance()
{
    return &g_sharedInstance;
}

void AutoReleasePool::addObject(NativeObject *object)
{
    this->objects.push_back(object);
}

bool AutoReleasePool::contains(NativeObject *o) const
{
    for (NativeObject *obj : this->objects) {
        if (obj == o) {
            return true;
        }
    }
    return false;
}

void AutoReleasePool::clear()
{
    
}

void AutoReleasePool::releaseObjects()
{
    std::vector<NativeObject *> newObjects;
    for (NativeObject *o : this->objects) {
        if (o->referenceCount() == 0) {
            delete o;
        } else {
            newObjects.push_back(o);
        }
    }
    this->objects = newObjects;
}
