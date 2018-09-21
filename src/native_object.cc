#include "libhtml5.h"
#include "native_object.h"
#include "auto_release_pool.h"

USING_NAMESPACE_HTML5;

NativeObject::NativeObject() :
    _isAutoRelease(false),
    _refCount(0)
{
}

NativeObject::~NativeObject()
{

}

bool NativeObject::isAutoRelease()
{
    return this->_isAutoRelease;
}

void NativeObject::autorelease()
{
    this->_isAutoRelease = true;
    AutoReleasePool::sharedInstance()->addObject(this);
}

void NativeObject::release()
{
    if (this->_refCount > 0) {
        this->_refCount--;
    }
}

void NativeObject::retain()
{
    this->_refCount++;
}

unsigned int NativeObject::referenceCount()
{
    return this->_refCount;
}
