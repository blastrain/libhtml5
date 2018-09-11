#include "media_list.h"

MediaList::MediaList(emscripten::val v) : v(v)
{

}

MediaList::~MediaList()
{

}

MediaList *MediaList::create(emscripten::val v)
{
    MediaList *ml = new MediaList(v);
    ml->autorelease();
    return ml;
}

void MediaList::appendMedium(std::string medium)
{
    HTML5_CALL(this->v, appendMedium, medium);
}

void MediaList::deleteMedium(std::string medium)
{
    HTML5_CALL(this->v, deleteMedium, medium);
}

std::string MediaList::item(unsigned long index)
{
    return HTML5_CALLs(this->v, item, index);
}

unsigned long MediaList::getLength() const
{
    return HTML5_PROPERTY_GET(length, unsigned long);
}

void MediaList::setLength(unsigned long value)
{
    this->_length = value;
    this->v.set("length", value);
}

std::string MediaList::getMediaText() const
{
    return HTML5_PROPERTY_GET(mediaText, std::string);
}

void MediaList::setMediaText(std::string value)
{
    this->_mediaText = value;
    this->v.set("mediaText", value);
}
