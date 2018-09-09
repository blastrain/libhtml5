#include "audio_track.h"

AudioTrack::AudioTrack(emscripten::val v) : v(v)
{

}

AudioTrack::~AudioTrack()
{

}

AudioTrack *AudioTrack::create(emscripten::val v)
{
    return new AudioTrack(v);
}

bool AudioTrack::getEnabled() const
{
    return this->v["enabled"].as<bool>();
}

void AudioTrack::setEnabled(bool value)
{
    this->_enabled = value;
    this->v.set("enabled", value);
}

std::string AudioTrack::getId() const
{
    return this->v["id"].as<std::string>();
}

void AudioTrack::setId(std::string value)
{
    this->_id = value;
    this->v.set("id", value);
}

std::string AudioTrack::getKind() const
{
    return this->v["kind"].as<std::string>();
}

void AudioTrack::setKind(std::string value)
{
    this->_kind = value;
    this->v.set("kind", value);
}

std::string AudioTrack::getLabel() const
{
    return this->v["label"].as<std::string>();
}

void AudioTrack::setLabel(std::string value)
{
    this->_label = value;
    this->v.set("label", value);
}

std::string AudioTrack::getLanguage() const
{
    return this->v["language"].as<std::string>();
}

void AudioTrack::setLanguage(std::string value)
{
    this->_language = value;
    this->v.set("language", value);
}
