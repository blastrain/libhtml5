#include "libhtml5.h"
#include "native_array.h"

USING_NAMESPACE_HTML5;

NativeArray::NativeArray()
{

}

NativeArray::~NativeArray()
{
    for (NativeObject *o : this->arr) {
        HTML5_RELEASE(o);
    }
    this->arr.clear();
}

NativeArray *NativeArray::create()
{
    NativeArray *arr = new NativeArray();
    arr->autorelease();
    return arr;
}

void NativeArray::add(NativeObject *o)
{
    if (o->isAutoRelease()) {
        o->retain();
    }
    this->arr.push_back(o);
}
