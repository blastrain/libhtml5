#include "array_buffer.h"
#include "float64_array.h"
#include "array.h"

USING_NAMESPACE_HTML5;

Float64Array::Float64Array(emscripten::val v) :
    ArrayBufferView(v)
{

}

Float64Array::~Float64Array()
{

}

Float64Array *Float64Array::create(emscripten::val v)
{
    auto array = new Float64Array(v);
    array->autorelease();
    return array;
}

Float64Array *Float64Array::create(unsigned long length)
{
    return create(HTML5_NEW_PRIMITIVE_INSTANCE(Float64Array, length));
}

Float64Array *Float64Array::create(Float64Array *array)
{
    return create(HTML5_NEW_PRIMITIVE_INSTANCE(Float64Array, array->v));
}

Float64Array *Float64Array::create(const std::vector<double> &array)
{
    return create(HTML5_NEW_PRIMITIVE_INSTANCE(Float64Array, toJSArray<double>(array)));
}

Float64Array *Float64Array::create(ArrayBuffer *buffer)
{
    return create(HTML5_NEW_PRIMITIVE_INSTANCE(Float64Array, buffer->v));
}

Float64Array *Float64Array::create(ArrayBuffer *buffer, unsigned long byteOffset)
{
    return create(HTML5_NEW_PRIMITIVE_INSTANCE(Float64Array, buffer->v, byteOffset));
}

Float64Array *Float64Array::create(ArrayBuffer *buffer, unsigned long byteOffset, unsigned long length)
{
    return create(HTML5_NEW_PRIMITIVE_INSTANCE(Float64Array, buffer->v, byteOffset, length));
}

double Float64Array::get(unsigned long index)
{
    return HTML5_CALLf(this->v, get, double, index);
}

void Float64Array::set(Array *array, unsigned long offset)
{
    HTML5_CALL(this->v, set, array->v, offset);
}

Float64Array *Float64Array::subarray(long start, long end)
{
    return create(HTML5_CALLv(this->v, subarray, start, end));
}

double Float64Array::operator[](std::size_t index) const
{
#if ENABLE_EMSCRIPTEN
    return this->v[index].as<double>();
#else
    return this->_rawdata[index];
#endif
}

Float64Array::doubleWrapType::doubleWrapType(emscripten::val v, size_t index) :
    v(v),
    index(index)
{

}

Float64Array::doubleWrapType::~doubleWrapType()
{

}

void Float64Array::doubleWrapType::operator=(double value)
{
    this->v.set(this->index, value);
}

Float64Array::doubleWrapType Float64Array::operator[](std::size_t index)
{
    return Float64Array::doubleWrapType(this->v, index);
}

HTML5_PROPERTY_IMPL(Float64Array, unsigned long, length);
