#include "mime_type.h"
#include "mime_type_array.h"

USING_NAMESPACE_HTML5;

MimeTypeArray::MimeTypeArray(emscripten::val v) :
    Object(v)
{

}

MimeTypeArray::~MimeTypeArray()
{

}

MimeTypeArray *MimeTypeArray::create(emscripten::val v)
{
    auto array = new MimeTypeArray(v);
    array->autorelease();
    return array;
}

MimeType *MimeTypeArray::item(unsigned long index)
{
    return MimeType::create(HTML5_CALLv(this->v, item, index));
}

MimeType *MimeTypeArray::namedItem(std::string name)
{
    return MimeType::create(HTML5_CALLv(this->v, namedItem, name));
}

HTML5_PROPERTY_IMPL(MimeTypeArray, unsigned long, length);
