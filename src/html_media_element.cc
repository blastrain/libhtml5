#include "date.h"
#include "time_ranges.h"
#include "audio_track_list.h"
#include "text_track_list.h"
#include "video_track_list.h"
#include "media_controller.h"
#include "media_error.h"
#include "html_media_element.h"

USING_NAMESPACE_HTML5;

HTMLMediaElement::HTMLMediaElement(emscripten::val v) :
    HTMLElement(v)
{

}

HTMLMediaElement::~HTMLMediaElement()
{

}

HTMLMediaElement *HTMLMediaElement::create(emscripten::val v)
{
    HTMLMediaElement *media = new HTMLMediaElement(v);
    media->autorelease();
    return media;
}

TextTrack *HTMLMediaElement::addTextTrack(TextTrackKind kind)
{
    std::string param;
    switch (kind) {
    case TextTrackKind::SUBTITLES:
        param = "subtitles";
        break;
    case TextTrackKind::CAPTIONS:
        param = "captions";
        break;
    case TextTrackKind::DESCRIPTIONS:
        param = "descriptions";
        break;
    case TextTrackKind::CHAPTERS:
        param = "capters";
        break;
    case TextTrackKind::METADATA:
        param = "metadata";
        break;
    }
    return TextTrack::create(HTML5_CALLv(this->v, addTextTrack, param));
}

TextTrack *HTMLMediaElement::addTextTrack(TextTrackKind kind, std::string label, std::string language)
{
    std::string param;
    switch (kind) {
    case TextTrackKind::SUBTITLES:
        param = "subtitles";
        break;
    case TextTrackKind::CAPTIONS:
        param = "captions";
        break;
    case TextTrackKind::DESCRIPTIONS:
        param = "descriptions";
        break;
    case TextTrackKind::CHAPTERS:
        param = "capters";
        break;
    case TextTrackKind::METADATA:
        param = "metadata";
        break;
    }
    return TextTrack::create(HTML5_CALLv(this->v, addTextTrack, param, label, language));
}

CanPlayTypeResult HTMLMediaElement::canPlayType(std::string type)
{
    std::string result = HTML5_CALLs(this->v, canPlayType, type);
    if (result == "maybe") {
        return CanPlayTypeResult::MAYBE;
    } else if (result == "probably") {
        return CanPlayTypeResult::PROBABLY;
    }
    return CanPlayTypeResult::UNKNOWN;
}

void HTMLMediaElement::fastSeek(double time)
{
    HTML5_CALL(this->v, fastSeek, time);
}

Date *HTMLMediaElement::getStartDate()
{
    return Date::create(HTML5_CALLv(this->v, getStartDate));
}

void HTMLMediaElement::load()
{
    HTML5_CALL(this->v, load);
}

void HTMLMediaElement::pause()
{
    HTML5_CALL(this->v, pause);
}

void HTMLMediaElement::play()
{
    HTML5_CALL(this->v, play);
}

HTML5_PROPERTY_OBJECT_IMPL(HTMLMediaElement, AudioTrackList, audioTracks);
HTML5_PROPERTY_IMPL(HTMLMediaElement, bool, autoPlay);
HTML5_PROPERTY_OBJECT_IMPL(HTMLMediaElement, TimeRanges, buffered);
HTML5_PROPERTY_OBJECT_IMPL(HTMLMediaElement, MediaController, controller);
HTML5_PROPERTY_IMPL(HTMLMediaElement, bool, controls);
HTML5_PROPERTY_IMPL(HTMLMediaElement, std::string, crossOrigin);
HTML5_PROPERTY_IMPL(HTMLMediaElement, std::string, currentSrc);
HTML5_PROPERTY_IMPL(HTMLMediaElement, double, currentTime);
HTML5_PROPERTY_IMPL(HTMLMediaElement, bool, defaultMuted);
HTML5_PROPERTY_IMPL(HTMLMediaElement, double, defaultPlaybackRate);
HTML5_PROPERTY_IMPL(HTMLMediaElement, double, duration);
HTML5_PROPERTY_IMPL(HTMLMediaElement, bool, ended);
HTML5_PROPERTY_OBJECT_IMPL(HTMLMediaElement, MediaError, error);
HTML5_PROPERTY_IMPL(HTMLMediaElement, bool, loop);
HTML5_PROPERTY_IMPL(HTMLMediaElement, std::string, mediaGroup);
HTML5_PROPERTY_IMPL(HTMLMediaElement, bool, muted);
HTML5_PROPERTY_IMPL(HTMLMediaElement, unsigned short, networkState);
HTML5_PROPERTY_IMPL(HTMLMediaElement, bool, paused);
HTML5_PROPERTY_IMPL(HTMLMediaElement, double, playbackRate);
HTML5_PROPERTY_OBJECT_IMPL(HTMLMediaElement, TimeRanges, played);
HTML5_PROPERTY_IMPL(HTMLMediaElement, std::string, preload);
HTML5_PROPERTY_IMPL(HTMLMediaElement, unsigned short, readyState);
HTML5_PROPERTY_OBJECT_IMPL(HTMLMediaElement, TimeRanges, seekable);
HTML5_PROPERTY_IMPL(HTMLMediaElement, bool, seeking);
HTML5_PROPERTY_IMPL(HTMLMediaElement, std::string, src);
HTML5_PROPERTY_OBJECT_IMPL(HTMLMediaElement, TextTrackList, textTracks);
HTML5_PROPERTY_OBJECT_IMPL(HTMLMediaElement, VideoTrackList, videoTracks);
HTML5_PROPERTY_IMPL(HTMLMediaElement, double, volume);
