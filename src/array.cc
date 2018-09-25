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

std::unique_ptr<Array> Array::create(emscripten::val v)
{
    return std::unique_ptr<Array>(new Array(v));
}
