#include "array_buffer.h"
#include "array_buffer_view.h"

ArrayBufferView::ArrayBufferView(emscripten::val v) :
    Object(),
    v(v)
{

}

ArrayBufferView::~ArrayBufferView()
{

}

ArrayBuffer *ArrayBufferView::getBuffer() const
{
    return HTML5_PROPERTY_GET(buffer, ArrayBuffer);
}

void ArrayBufferView::setBuffer(ArrayBuffer *value)
{
    this->_buffer = value;
    this->v.set("buffer", value->v);
}

unsigned long ArrayBufferView::getByteLength() const
{
    return HTML5_PROPERTY_GET(byteLength, unsigned long);
}

void ArrayBufferView::setByteLength(unsigned long value)
{
    this->_byteLength = value;
    this->v.set("byteLength", value);
}

unsigned long ArrayBufferView::getByteOffset() const
{
    return HTML5_PROPERTY_GET(byteOffset, unsigned long);
}

void ArrayBufferView::setByteOffset(unsigned long value)
{
    this->_byteOffset = value;
    this->v.set("byteOffset", value);
}
