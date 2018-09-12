#include "blob.h"

Blob::Blob(emscripten::val v) :
    v(v),
    Object()
{

}

Blob::~Blob()
{

}

Blob *Blob::create(emscripten::val v)
{
    Blob *blob = new Blob(v);
    blob->autorelease();
    return blob;
}

void Blob::close()
{
    HTML5_CALL(this->v, close);
}

Blob *Blob::slice(long long start)
{
    return Blob::create(HTML5_CALLv(this->v, slice, start));
}

Blob *Blob::slice(long long start, long long end, std::string contentType)
{
    return Blob::create(HTML5_CALLv(this->v, slice, start, end, contentType));
}

unsigned long long Blob::getSize() const
{
    return HTML5_PROPERTY_GET(size, unsigned long long);
}

void Blob::setSize(unsigned long long value)
{
    this->_size = value;
    this->v.set("size", value);
}

std::string Blob::getType() const
{
    return HTML5_PROPERTY_GET(type, std::string);
}

void Blob::setType(std::string value)
{
    this->_type = value;
    this->v.set("type", value);
}
