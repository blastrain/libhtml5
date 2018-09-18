#include "plugin.h"
#include "mime_type.h"

MimeType::MimeType(emscripten::val v) :
    Object(),
    v(v)
{

}

MimeType::~MimeType()
{

}

MimeType *MimeType::create(emscripten::val v)
{
    auto mimetype = new MimeType(v);
    mimetype->autorelease();
    return mimetype;
}

HTML5_PROPERTY_IMPL(MimeType, std::string, description);
HTML5_PROPERTY_OBJECT_IMPL(MimeType, Plugin, enabledPlugin);
HTML5_PROPERTY_IMPL(MimeType, std::string, suffixes);
HTML5_PROPERTY_IMPL(MimeType, std::string, type);
