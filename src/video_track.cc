#include "video_track.h"

VideoTrack::VideoTrack(emscripten::val v) : v(v)
{

}

VideoTrack::~VideoTrack()
{

}

VideoTrack *VideoTrack::create(emscripten::val v)
{
    return new VideoTrack(v);
}

std::string VideoTrack::getId() const
{
    return this->v["id"].as<std::string>();
}

void VideoTrack::setId(std::string value)
{
    this->_id = value;
    this->v.set("id", value);
}

std::string VideoTrack::getKind() const
{
    return this->v["kind"].as<std::string>();
}

void VideoTrack::setKind(std::string value)
{
    this->_kind = value;
    this->v.set("kind", value);
}

std::string VideoTrack::getLabel() const
{
    return this->v["label"].as<std::string>();
}

void VideoTrack::setLabel(std::string value)
{
    this->_label = value;
    this->v.set("label", value);
}

std::string VideoTrack::getLanguage() const
{
    return this->v["language"].as<std::string>();
}

void VideoTrack::setLanguage(std::string value)
{
    this->_language = value;
    this->v.set("language", value);
}

bool VideoTrack::getSelected() const
{
    return this->v["selected"].as<bool>();
}

void VideoTrack::setSelected(bool value)
{
    this->_selected = value;
    this->v.set("selected", value);
}
