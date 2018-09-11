#include "audio_track.h"

AudioTrack::AudioTrack(emscripten::val v) : v(v)
{

}

AudioTrack::~AudioTrack()
{

}

AudioTrack *AudioTrack::create(emscripten::val v)
{
    AudioTrack *track = new AudioTrack(v);
    track->autorelease();
    return track;
}

bool AudioTrack::getEnabled() const
{
    return HTML5_PROPERTY_GET(enabled, bool);
}

void AudioTrack::setEnabled(bool value)
{
    this->_enabled = value;
    this->v.set("enabled", value);
}

std::string AudioTrack::getId() const
{
    return HTML5_PROPERTY_GET(id, std::string);
}

void AudioTrack::setId(std::string value)
{
    this->_id = value;
    this->v.set("id", value);
}

std::string AudioTrack::getKind() const
{
    return HTML5_PROPERTY_GET(kind, std::string);
}

void AudioTrack::setKind(std::string value)
{
    this->_kind = value;
    this->v.set("kind", value);
}

std::string AudioTrack::getLabel() const
{
    return HTML5_PROPERTY_GET(label, std::string);
}

void AudioTrack::setLabel(std::string value)
{
    this->_label = value;
    this->v.set("label", value);
}

std::string AudioTrack::getLanguage() const
{
    return HTML5_PROPERTY_GET(language, std::string);
}

void AudioTrack::setLanguage(std::string value)
{
    this->_language = value;
    this->v.set("language", value);
}
