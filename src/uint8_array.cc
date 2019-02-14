#include "array_buffer.h"
#include "uint8_array.h"

USING_NAMESPACE_HTML5;

Uint8Array::Uint8Array(emscripten::val v) :
    ArrayBufferView(v)
{

}

Uint8Array::~Uint8Array()
{

}

Uint8Array *Uint8Array::create(emscripten::val v)
{
    auto array = new Uint8Array(v);
    array->autorelease();
    return array;
}
    
Uint8Array *Uint8Array::create()
{
    return create(HTML5_NEW_PRIMITIVE_INSTANCE(Uint8Array));
}

Uint8Array *Uint8Array::create(unsigned long length)
{
    return create(HTML5_NEW_PRIMITIVE_INSTANCE(Uint8Array, length));
}

Uint8Array *Uint8Array::create(Uint8Array *array)
{
    return create(array->v);
}

Uint8Array *Uint8Array::create(ArrayBuffer *buffer)
{
    return create(HTML5_NEW_PRIMITIVE_INSTANCE(Uint8Array, buffer->v));
}

Uint8Array *Uint8Array::create(ArrayBuffer *buffer, unsigned long byteOffset)
{
    return create(HTML5_NEW_PRIMITIVE_INSTANCE(Uint8Array, buffer->v, byteOffset));
}

Uint8Array *Uint8Array::create(ArrayBuffer *buffer, unsigned long byteOffset, unsigned long length)
{
    return create(HTML5_NEW_PRIMITIVE_INSTANCE(Uint8Array, buffer->v, byteOffset, length));
}

Uint8Array::uint8WrapType Uint8Array::operator[](std::size_t index) const
{
    return Uint8Array::uint8WrapType(this->v, index);
}

Uint8Array::uint8WrapType Uint8Array::operator[](std::size_t index)
{
    return Uint8Array::uint8WrapType(this->v, index);
}

Uint8Array::uint8WrapType::uint8WrapType(emscripten::val v, size_t index) :
    v(v),
    index(index)
{

}

Uint8Array::uint8WrapType::~uint8WrapType()
{

}

void Uint8Array::uint8WrapType::operator=(uint8_t value)
{
    this->v.set(this->index, value);
}

HTML5_PROPERTY_IMPL(Uint8Array, unsigned long, length);
