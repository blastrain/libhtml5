#include "array_buffer.h"
#include "float32_array.h"
#include "array.h"

USING_NAMESPACE_HTML5;

Float32Array::Float32Array(emscripten::val v) :
    ArrayBufferView(v)
{

}

Float32Array::~Float32Array()
{

}

Float32Array *Float32Array::create(emscripten::val v)
{
    auto array = new Float32Array(v);
    array->autorelease();
    return array;
}

Float32Array *Float32Array::create(unsigned long length)
{
    return create(HTML5_NEW_PRIMITIVE_INSTANCE(Float32Array, length));
}

Float32Array *Float32Array::create(Float32Array *array)
{
    return create(HTML5_NEW_PRIMITIVE_INSTANCE(Float32Array, array->v));
}

Float32Array *Float32Array::create(const std::vector<double> &array)
{
    return create(HTML5_NEW_PRIMITIVE_INSTANCE(Float32Array, toJSArray<double>(array)));
}

Float32Array *Float32Array::create(ArrayBuffer *buffer)
{
    return create(HTML5_NEW_PRIMITIVE_INSTANCE(Float32Array, buffer->v));
}

Float32Array *Float32Array::create(ArrayBuffer *buffer, unsigned long byteOffset)
{
    return create(HTML5_NEW_PRIMITIVE_INSTANCE(Float32Array, buffer->v, byteOffset));
}

Float32Array *Float32Array::create(ArrayBuffer *buffer, unsigned long byteOffset, unsigned long length)
{
    return create(HTML5_NEW_PRIMITIVE_INSTANCE(Float32Array, buffer->v, byteOffset, length));
}

double Float32Array::get(unsigned long index)
{
    return HTML5_CALLf(this->v, get, double, index);
}

void Float32Array::set(const array &array, unsigned long offset)
{
    HTML5_CALL(this->v, set, array.v, offset);
}

Float32Array *Float32Array::subarray(long start, long end)
{
    return create(HTML5_CALLv(this->v, subarray, start, end));
}

double Float32Array::operator[](std::size_t index) const
{
#if ENABLE_EMSCRIPTEN
    return this->v[index].as<double>();
#else
    return this->_rawdata[index];
#endif
}

Float32Array::doubleWrapType::doubleWrapType(emscripten::val v, size_t index) :
    v(v),
    index(index)
{

}

Float32Array::doubleWrapType::~doubleWrapType()
{

}

void Float32Array::doubleWrapType::operator=(double value)
{
    this->v.set(this->index, value);
}

Float32Array::doubleWrapType Float32Array::operator[](std::size_t index)
{
    return Float32Array::doubleWrapType(this->v, index);
}

HTML5_PROPERTY_IMPL(Float32Array, unsigned long, length);
