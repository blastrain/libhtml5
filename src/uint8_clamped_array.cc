#include "array_buffer.h"
#include "uint8_clamped_array.h"

USING_NAMESPACE_HTML5;

Uint8ClampedArray::Uint8ClampedArray(emscripten::val v) :
    ArrayBufferView(v)
{

}

Uint8ClampedArray::~Uint8ClampedArray()
{

}

Uint8ClampedArray *Uint8ClampedArray::create(emscripten::val v)
{
    auto array = new Uint8ClampedArray(v);
    array->autorelease();
    return array;
}
    
Uint8ClampedArray *Uint8ClampedArray::create()
{
    return create(HTML5_NEW_PRIMITIVE_INSTANCE(Uint8ClampedArray));
}

Uint8ClampedArray *Uint8ClampedArray::create(unsigned long length)
{
    return create(HTML5_NEW_PRIMITIVE_INSTANCE(Uint8ClampedArray, length));
}

Uint8ClampedArray *Uint8ClampedArray::create(Uint8ClampedArray *array)
{
    return create(array->v);
}

Uint8ClampedArray *Uint8ClampedArray::create(ArrayBuffer *buffer)
{
    return create(HTML5_NEW_PRIMITIVE_INSTANCE(Uint8ClampedArray, buffer->v));
}

Uint8ClampedArray *Uint8ClampedArray::create(ArrayBuffer *buffer, unsigned long byteOffset)
{
    return create(HTML5_NEW_PRIMITIVE_INSTANCE(Uint8ClampedArray, buffer->v, byteOffset));
}

Uint8ClampedArray *Uint8ClampedArray::create(ArrayBuffer *buffer, unsigned long byteOffset, unsigned long length)
{
    return create(HTML5_NEW_PRIMITIVE_INSTANCE(Uint8ClampedArray, buffer->v, byteOffset, length));
}

uint8_t Uint8ClampedArray::operator[](std::size_t index) const
{
#if ENABLE_EMSCRIPTEN
    return this->v[index].as<uint8_t>();
#else
    return this->_rawdata[index];
#endif
}

Uint8ClampedArray::uint8WrapType::uint8WrapType(emscripten::val v, size_t index) :
    v(v),
    index(index)
{

}

Uint8ClampedArray::uint8WrapType::~uint8WrapType()
{

}

void Uint8ClampedArray::uint8WrapType::operator=(uint8_t value)
{
    this->v.set(this->index, value);
}

Uint8ClampedArray::uint8WrapType Uint8ClampedArray::operator[](std::size_t index)
{
    return Uint8ClampedArray::uint8WrapType(this->v, index);
}

HTML5_PROPERTY_IMPL(Uint8ClampedArray, unsigned long, length);
