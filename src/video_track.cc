#include "video_track.h"

VideoTrack::VideoTrack(emscripten::val v) : v(v)
{

}

VideoTrack::~VideoTrack()
{

}

VideoTrack *VideoTrack::create(emscripten::val v)
{
    VideoTrack *track = new VideoTrack(v);
    track->autorelease();
    return track;
}

std::string VideoTrack::getId() const
{
    return HTML5_PROPERTY_GET(id, std::string);
}

void VideoTrack::setId(std::string value)
{
    this->_id = value;
    this->v.set("id", value);
}

std::string VideoTrack::getKind() const
{
    return HTML5_PROPERTY_GET(kind, std::string);
}

void VideoTrack::setKind(std::string value)
{
    this->_kind = value;
    this->v.set("kind", value);
}

std::string VideoTrack::getLabel() const
{
    return HTML5_PROPERTY_GET(label, std::string);
}

void VideoTrack::setLabel(std::string value)
{
    this->_label = value;
    this->v.set("label", value);
}

std::string VideoTrack::getLanguage() const
{
    return HTML5_PROPERTY_GET(language, std::string);
}

void VideoTrack::setLanguage(std::string value)
{
    this->_language = value;
    this->v.set("language", value);
}

bool VideoTrack::getSelected() const
{
    return HTML5_PROPERTY_GET(selected, bool);
}

void VideoTrack::setSelected(bool value)
{
    this->_selected = value;
    this->v.set("selected", value);
}
