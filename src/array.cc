#include "libhtml5.h"
#include "array.h"

Array::Array()
{

}

Array::~Array()
{
    for (Object *o : this->arr) {
        HTML5_RELEASE(o);
    }
    this->arr.clear();
}

Array *Array::create()
{
    Array *arr = new Array();
    arr->autorelease();
    return arr;
}

void Array::add(Object *o)
{
    if (o->isAutoRelease()) {
        o->retain();
    }
    this->arr.push_back(o);
}
