#include "date.h"
#include "time_ranges.h"
#include "audio_track_list.h"
#include "text_track_list.h"
#include "video_track_list.h"
#include "media_controller.h"
#include "media_error.h"
#include "html_media_element.h"

HTMLMediaElement::HTMLMediaElement(emscripten::val v) :
    HTMLElement(v)
{

}

HTMLMediaElement::~HTMLMediaElement()
{

}

HTMLMediaElement *HTMLMediaElement::create(emscripten::val v)
{
    return new HTMLMediaElement(v);
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
    emscripten::val v = this->v.call<emscripten::val>("addTextTrack", param);
    return TextTrack::create(v);
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
    emscripten::val v = this->v.call<emscripten::val>("addTextTrack", param, label, language);
    return TextTrack::create(v);
}

CanPlayTypeResult HTMLMediaElement::canPlayType(std::string type)
{
    std::string result = this->v.call<std::string>("canPlayType", type);
    if (result == "maybe") {
        return CanPlayTypeResult::MAYBE;
    } else if (result == "probably") {
        return CanPlayTypeResult::PROBABLY;
    }
    return CanPlayTypeResult::UNKNOWN;
}

void HTMLMediaElement::fastSeek(double time)
{
    this->v.call<void>("fastSeek", time);
}

Date *HTMLMediaElement::getStartDate()
{
    return Date::create(this->v.call<emscripten::val>("getStartDate"));
}

void HTMLMediaElement::load()
{
    this->v.call<void>("load");
}

void HTMLMediaElement::pause()
{
    this->v.call<void>("pause");
}

void HTMLMediaElement::play()
{
    this->v.call<void>("play");
}

AudioTrackList *HTMLMediaElement::getAudioTracks() const
{
    return AudioTrackList::create(this->v["audioTracks"]);
}

void HTMLMediaElement::setAudioTracks(AudioTrackList *value)
{
    this->_audioTracks = value;
    this->v.set("audioTracks", value->v);
}

bool HTMLMediaElement::getAutoPlay() const
{
    return this->v["autoPlay"].as<bool>();
}

void HTMLMediaElement::setAutoPlay(bool value)
{
    this->_autoPlay = value;
    this->v.set("autoPlay", value);
}

TimeRanges *HTMLMediaElement::getBuffered() const
{
    return TimeRanges::create(this->v["buffered"]);
}

void HTMLMediaElement::setBuffered(TimeRanges *value)
{
    this->_buffered = value;
    this->v.set("buffered", value->v);
}

MediaController *HTMLMediaElement::getController() const
{
    return MediaController::create(this->v["controller"]);
}

void HTMLMediaElement::setController(MediaController *value)
{
    this->_controller = value;
    this->v.set("controller", value->v);
}

bool HTMLMediaElement::getControls() const
{
    return this->v["controls"].as<bool>();
}

void HTMLMediaElement::setControls(bool value)
{
    this->_controls = value;
    this->v.set("controls", value);
}

std::string HTMLMediaElement::getCrossOrigin() const
{
    return this->v["crossOrigin"].as<std::string>();
}

void HTMLMediaElement::setCrossOrigin(std::string value)
{
    this->_crossOrigin = value;
    this->v.set("crossOrigin", value);
}

std::string HTMLMediaElement::getCurrentSrc() const
{
    return this->v["currentSrc"].as<std::string>();
}

void HTMLMediaElement::setCurrentSrc(std::string value)
{
    this->_currentSrc = value;
    this->v.set("currentSrc", value);
}

double HTMLMediaElement::getCurrentTime() const
{
    return this->v["currentTime"].as<double>();
}

void HTMLMediaElement::setCurrentTime(double value)
{
    this->_currentTime = value;
    this->v.set("currentTime", value);
}

bool HTMLMediaElement::getDefaultMuted() const
{
    return this->_defaultMuted;
}

void HTMLMediaElement::setDefaultMuted(bool value)
{
    this->_defaultMuted = value;
    this->v.set("defaultMuted", value);
}

double HTMLMediaElement::getDefaultPlaybackRate() const
{
    return this->v["defaultPlaybackRate"].as<double>();
}

void HTMLMediaElement::setDefaultPlaybackRate(double value)
{
    this->_defaultPlaybackRate = value;
    this->v.set("defaultPlaybackRate", value);
}

double HTMLMediaElement::getDuration() const
{
    return this->v["duration"].as<double>();
}

void HTMLMediaElement::setDuration(double value)
{
    this->_duration = value;
    this->v.set("duration", value);
}
    
bool HTMLMediaElement::getEnded() const
{
    return this->v["ended"].as<bool>();
}

void HTMLMediaElement::setEnded(bool value)
{
    this->_ended = value;
    this->v.set("ended", value);
}

MediaError *HTMLMediaElement::getError() const
{
    return MediaError::create(this->v["error"]);
}

void HTMLMediaElement::setError(MediaError *value)
{
    this->_error = value;
    this->v.set("error", value->v);
}

bool HTMLMediaElement::getLoop() const
{
    return this->v["loop"].as<bool>();
}

void HTMLMediaElement::setLoop(bool value)
{
    this->_loop = value;
    this->v.set("loop", value);
}

std::string HTMLMediaElement::getMediaGroup() const
{
    return this->v["mediaGroup"].as<std::string>();
}

void HTMLMediaElement::setMediaGroup(std::string value)
{
    this->_mediaGroup = value;
    this->v.set("mediaGroup", value);
}

bool HTMLMediaElement::getMuted() const
{
    return this->v["muted"].as<bool>();
}

void HTMLMediaElement::setMuted(bool value)
{
    this->_muted = value;
    this->v.set("muted", value);
}

unsigned short HTMLMediaElement::getNetworkState() const
{
    return this->v["networkState"].as<unsigned short>();
}

void HTMLMediaElement::setNetworkState(unsigned short value)
{
    this->_networkState = value;
    this->v.set("networkState", value);
}

bool HTMLMediaElement::getPaused() const
{
    return this->v["paused"].as<bool>();
}

void HTMLMediaElement::setPaused(bool value)
{
    this->_paused = value;
    this->v.set("paused", value);
}

double HTMLMediaElement::getPlaybackRate() const
{
    return this->v["playbackRate"].as<double>();
}

void HTMLMediaElement::setPlaybackRate(double value)
{
    this->_playbackRate = value;
    this->v.set("playbackRate", value);
}

TimeRanges *HTMLMediaElement::getPlayed() const
{
    return TimeRanges::create(this->v["played"]);
}

void HTMLMediaElement::setPlayed(TimeRanges *value)
{
    this->_played = value;
    this->v.set("played", value->v);
}

std::string HTMLMediaElement::getPreload() const
{
    return this->v["preload"].as<std::string>();
}

void HTMLMediaElement::setPreload(std::string value)
{
    this->_preload = value;
    this->v.set("preload", value);
}

unsigned short HTMLMediaElement::getReadyState() const
{
    return this->v["readyState"].as<unsigned short>();
}

void HTMLMediaElement::setReadyState(unsigned short value)
{
    this->_readyState = value;
    this->v.set("readyState", value);
}

TimeRanges *HTMLMediaElement::getSeekable() const
{
    return TimeRanges::create(this->v["seekable"]);
}

void HTMLMediaElement::setSeekable(TimeRanges *value)
{
    this->_seekable = value;
    this->v.set("seekable", value->v);
}

bool HTMLMediaElement::getSeeking() const
{
    return this->v["seeking"].as<bool>();
}

void HTMLMediaElement::setSeeking(bool value)
{
    this->_seeking = value;
    this->v.set("seeking", value);
}

std::string HTMLMediaElement::getSrc() const
{
    return this->v["src"].as<std::string>();
}

void HTMLMediaElement::setSrc(std::string value)
{
    this->_src = value;
    this->v.set("src", value);
}

TextTrackList *HTMLMediaElement::getTextTracks() const
{
    return TextTrackList::create(this->v["textTracks"]);
}

void HTMLMediaElement::setTextTracks(TextTrackList *value)
{
    this->_textTracks = value;
    this->v.set("textTracks", value->v);
}

VideoTrackList *HTMLMediaElement::getVideoTracks() const
{
    return VideoTrackList::create(this->v["videoTracks"]);
}

void HTMLMediaElement::setVideoTracks(VideoTrackList *value)
{
    this->_videoTracks = value;
    this->v.set("videoTracks", value->v);
}

double HTMLMediaElement::getVolume() const
{
    return this->v["volume"].as<double>();
}

void HTMLMediaElement::setVolume(double value)
{
    this->_volume = value;
    this->v.set("volume", value);
}
