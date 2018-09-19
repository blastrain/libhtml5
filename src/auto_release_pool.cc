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

void AutoReleasePool::addObject(Object *object)
{
    this->objects.push_back(object);
}

bool AutoReleasePool::contains(Object *o) const
{
    for (Object *obj : this->objects) {
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
    std::vector<Object *> newObjects;
    for (Object *o : this->objects) {
        if (o->referenceCount() == 0) {
            delete o;
        } else {
            newObjects.push_back(o);
        }
    }
    this->objects = newObjects;
}
