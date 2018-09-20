#include "audio_track.h"

USING_NAMESPACE_HTML5;

AudioTrack::AudioTrack(emscripten::val v) :
    Object(v)
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

HTML5_PROPERTY_IMPL(AudioTrack, bool, enabled);
HTML5_PROPERTY_IMPL(AudioTrack, std::string, id);
HTML5_PROPERTY_IMPL(AudioTrack, std::string, kind);
HTML5_PROPERTY_IMPL(AudioTrack, std::string, label);
HTML5_PROPERTY_IMPL(AudioTrack, std::string, language);
