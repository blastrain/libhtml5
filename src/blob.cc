#include "blob.h"

USING_NAMESPACE_HTML5;

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
    return create(HTML5_CALLv(this->v, slice, start));
}

Blob *Blob::slice(long long start, long long end, std::string contentType)
{
    return create(HTML5_CALLv(this->v, slice, start, end, contentType));
}

HTML5_PROPERTY_IMPL(Blob, unsigned long long, size);
HTML5_PROPERTY_IMPL(Blob, std::string, type);
