#include "libhtml5.h"
#include "array.h"

USING_NAMESPACE_HTML5;

Array::Array(emscripten::val v) :
    Object(v)
{

}

Array::~Array()
{
}

Array *Array::create(emscripten::val v)
{
    Array *arr = new Array(v);
    arr->autorelease();
    return arr;
}

HTML5_PROPERTY_IMPL(Array, unsigned long, length);
