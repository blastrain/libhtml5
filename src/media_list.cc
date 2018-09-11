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
    this->v.call<void>("appendMedium", medium);
}

void MediaList::deleteMedium(std::string medium)
{
    this->v.call<void>("deleteMedium", medium);
}

std::string MediaList::item(unsigned long index)
{
    return this->v.call<std::string>("item", index);
}

unsigned long MediaList::getLength() const
{
    return this->v["length"].as<unsigned long>();
}

void MediaList::setLength(unsigned long value)
{
    this->_length = value;
    this->v.set("length", value);
}

std::string MediaList::getMediaText() const
{
    return this->v["mediaText"].as<std::string>();
}

void MediaList::setMediaText(std::string value)
{
    this->_mediaText = value;
    this->v.set("mediaText", value);
}
