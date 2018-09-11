#include "media_error.h"

MediaError::MediaError(emscripten::val v) : v(v)
{

}

MediaError::~MediaError()
{

}

MediaError *MediaError::create(emscripten::val v)
{
    MediaError *me = new MediaError(v);
    me->autorelease();
    return me;
}

unsigned short MediaError::getCode() const
{
    return HTML5_PROPERTY_GET(code, unsigned short);
}

void MediaError::setCode(unsigned short value)
{
    this->_code = value;
    this->v.set("code", value);
}
