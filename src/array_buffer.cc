#include "array_buffer_view.h"
#include "array_buffer.h"

ArrayBuffer::ArrayBuffer(emscripten::val v) :
    Object(),
    v(v)
{

}

ArrayBuffer::~ArrayBuffer()
{

}

ArrayBuffer *ArrayBuffer::create(emscripten::val v)
{
    ArrayBuffer *buf = new ArrayBuffer(v);
    buf->autorelease();
    return buf;
}

ArrayBuffer *ArrayBuffer::create(unsigned long length)
{
    return create(HTML5_NEW_PRIMITIVE_INSTANCE(ArrayBuffer, length));
}

bool ArrayBuffer::isView(Object *o)
{
    return dynamic_cast<ArrayBufferView *>(o);
}

ArrayBuffer *ArrayBuffer::slice(long begin)
{
    return create(HTML5_CALLv(this->v, slice, begin));
}

ArrayBuffer *ArrayBuffer::slice(long begin, long end)
{
    return create(HTML5_CALLv(this->v, slice, begin, end));
}

unsigned long ArrayBuffer::getByteLength() const
{
    return HTML5_PROPERTY_GET(byteLength, unsigned long);
}

void ArrayBuffer::setByteLength(unsigned long value)
{
    this->_byteLength = value;
    this->v.set("byteLength", value);
}
