#include "array_buffer.h"
#include "uint8_clamped_array.h"

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

HTML5_PROPERTY_IMPL(Uint8ClampedArray, unsigned long, length);
