#include "video_track.h"

USING_NAMESPACE_HTML5;

VideoTrack::VideoTrack(emscripten::val v) :
    Object(v)
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

HTML5_PROPERTY_IMPL(VideoTrack, std::string, id);
HTML5_PROPERTY_IMPL(VideoTrack, std::string, kind);
HTML5_PROPERTY_IMPL(VideoTrack, std::string, label);
HTML5_PROPERTY_IMPL(VideoTrack, std::string, language);
HTML5_PROPERTY_IMPL(VideoTrack, bool, selected);
