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

HTML5_PROPERTY_IMPL(MediaList, unsigned long, length);
HTML5_PROPERTY_IMPL(MediaList, std::string, mediaText);
