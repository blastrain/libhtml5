#include "object.h"
#include "auto_release_pool.h"

Object::Object() :
    _isAutoRelease(false),
    _refCount(0)
{
}

Object::~Object()
{

}

bool Object::isAutoRelease()
{
    return this->_isAutoRelease;
}

void Object::autorelease()
{
    this->_isAutoRelease = true;
    AutoReleasePool::sharedInstance()->addObject(this);
}

void Object::release()
{
    if (this->_refCount > 0) {
        this->_refCount--;
    }
}

void Object::retain()
{
    this->_refCount++;
}

unsigned int Object::referenceCount()
{
    return this->_refCount;
}
