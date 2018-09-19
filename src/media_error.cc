#include "media_error.h"

USING_NAMESPACE_HTML5;

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

HTML5_PROPERTY_IMPL(MediaError, unsigned short, code);
