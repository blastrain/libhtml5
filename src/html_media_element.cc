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

AudioTrackList *HTMLMediaElement::getAudioTracks() const
{
    return HTML5_PROPERTY_GET(audioTracks, AudioTrackList);
}

void HTMLMediaElement::setAudioTracks(AudioTrackList *value)
{
    this->_audioTracks = value;
    this->v.set("audioTracks", value->v);
}

bool HTMLMediaElement::getAutoPlay() const
{
    return HTML5_PROPERTY_GET(autoPlay, bool);
}

void HTMLMediaElement::setAutoPlay(bool value)
{
    this->_autoPlay = value;
    this->v.set("autoPlay", value);
}

TimeRanges *HTMLMediaElement::getBuffered() const
{
    return HTML5_PROPERTY_GET(buffered, TimeRanges);
}

void HTMLMediaElement::setBuffered(TimeRanges *value)
{
    this->_buffered = value;
    this->v.set("buffered", value->v);
}

MediaController *HTMLMediaElement::getController() const
{
    return HTML5_PROPERTY_GET(controller, MediaController);
}

void HTMLMediaElement::setController(MediaController *value)
{
    this->_controller = value;
    this->v.set("controller", value->v);
}

bool HTMLMediaElement::getControls() const
{
    return HTML5_PROPERTY_GET(controls, bool);
}

void HTMLMediaElement::setControls(bool value)
{
    this->_controls = value;
    this->v.set("controls", value);
}

std::string HTMLMediaElement::getCrossOrigin() const
{
    return HTML5_PROPERTY_GET(crossOrigin, std::string);
}

void HTMLMediaElement::setCrossOrigin(std::string value)
{
    this->_crossOrigin = value;
    this->v.set("crossOrigin", value);
}

std::string HTMLMediaElement::getCurrentSrc() const
{
    return HTML5_PROPERTY_GET(currentSrc, std::string);
}

void HTMLMediaElement::setCurrentSrc(std::string value)
{
    this->_currentSrc = value;
    this->v.set("currentSrc", value);
}

double HTMLMediaElement::getCurrentTime() const
{
    return HTML5_PROPERTY_GET(currentTime, double);
}

void HTMLMediaElement::setCurrentTime(double value)
{
    this->_currentTime = value;
    this->v.set("currentTime", value);
}

bool HTMLMediaElement::getDefaultMuted() const
{
    return HTML5_PROPERTY_GET(defaultMuted, bool);
}

void HTMLMediaElement::setDefaultMuted(bool value)
{
    this->_defaultMuted = value;
    this->v.set("defaultMuted", value);
}

double HTMLMediaElement::getDefaultPlaybackRate() const
{
    return HTML5_PROPERTY_GET(defaultPlaybackRate, double);
}

void HTMLMediaElement::setDefaultPlaybackRate(double value)
{
    this->_defaultPlaybackRate = value;
    this->v.set("defaultPlaybackRate", value);
}

double HTMLMediaElement::getDuration() const
{
    return HTML5_PROPERTY_GET(duration, double);
}

void HTMLMediaElement::setDuration(double value)
{
    this->_duration = value;
    this->v.set("duration", value);
}
    
bool HTMLMediaElement::getEnded() const
{
    return HTML5_PROPERTY_GET(ended, bool);
}

void HTMLMediaElement::setEnded(bool value)
{
    this->_ended = value;
    this->v.set("ended", value);
}

MediaError *HTMLMediaElement::getError() const
{
    return HTML5_PROPERTY_GET(error, MediaError);
}

void HTMLMediaElement::setError(MediaError *value)
{
    this->_error = value;
    this->v.set("error", value->v);
}

bool HTMLMediaElement::getLoop() const
{
    return HTML5_PROPERTY_GET(loop, bool);
}

void HTMLMediaElement::setLoop(bool value)
{
    this->_loop = value;
    this->v.set("loop", value);
}

std::string HTMLMediaElement::getMediaGroup() const
{
    return HTML5_PROPERTY_GET(mediaGroup, std::string);
}

void HTMLMediaElement::setMediaGroup(std::string value)
{
    this->_mediaGroup = value;
    this->v.set("mediaGroup", value);
}

bool HTMLMediaElement::getMuted() const
{
    return HTML5_PROPERTY_GET(muted, bool);
}

void HTMLMediaElement::setMuted(bool value)
{
    this->_muted = value;
    this->v.set("muted", value);
}

unsigned short HTMLMediaElement::getNetworkState() const
{
    return HTML5_PROPERTY_GET(networkState, unsigned short);
}

void HTMLMediaElement::setNetworkState(unsigned short value)
{
    this->_networkState = value;
    this->v.set("networkState", value);
}

bool HTMLMediaElement::getPaused() const
{
    return HTML5_PROPERTY_GET(paused, bool);
}

void HTMLMediaElement::setPaused(bool value)
{
    this->_paused = value;
    this->v.set("paused", value);
}

double HTMLMediaElement::getPlaybackRate() const
{
    return HTML5_PROPERTY_GET(playbackRate, double);
}

void HTMLMediaElement::setPlaybackRate(double value)
{
    this->_playbackRate = value;
    this->v.set("playbackRate", value);
}

TimeRanges *HTMLMediaElement::getPlayed() const
{
    return HTML5_PROPERTY_GET(played, TimeRanges);
}

void HTMLMediaElement::setPlayed(TimeRanges *value)
{
    this->_played = value;
    this->v.set("played", value->v);
}

std::string HTMLMediaElement::getPreload() const
{
    return HTML5_PROPERTY_GET(preload, std::string);
}

void HTMLMediaElement::setPreload(std::string value)
{
    this->_preload = value;
    this->v.set("preload", value);
}

unsigned short HTMLMediaElement::getReadyState() const
{
    return HTML5_PROPERTY_GET(readyState, unsigned short);
}

void HTMLMediaElement::setReadyState(unsigned short value)
{
    this->_readyState = value;
    this->v.set("readyState", value);
}

TimeRanges *HTMLMediaElement::getSeekable() const
{
    return HTML5_PROPERTY_GET(seekable, TimeRanges);
}

void HTMLMediaElement::setSeekable(TimeRanges *value)
{
    this->_seekable = value;
    this->v.set("seekable", value->v);
}

bool HTMLMediaElement::getSeeking() const
{
    return HTML5_PROPERTY_GET(seeking, bool);
}

void HTMLMediaElement::setSeeking(bool value)
{
    this->_seeking = value;
    this->v.set("seeking", value);
}

std::string HTMLMediaElement::getSrc() const
{
    return HTML5_PROPERTY_GET(src, std::string);
}

void HTMLMediaElement::setSrc(std::string value)
{
    this->_src = value;
    this->v.set("src", value);
}

TextTrackList *HTMLMediaElement::getTextTracks() const
{
    return HTML5_PROPERTY_GET(textTracks, TextTrackList);
}

void HTMLMediaElement::setTextTracks(TextTrackList *value)
{
    this->_textTracks = value;
    this->v.set("textTracks", value->v);
}

VideoTrackList *HTMLMediaElement::getVideoTracks() const
{
    return HTML5_PROPERTY_GET(videoTracks, VideoTrackList);
}

void HTMLMediaElement::setVideoTracks(VideoTrackList *value)
{
    this->_videoTracks = value;
    this->v.set("videoTracks", value->v);
}

double HTMLMediaElement::getVolume() const
{
    return HTML5_PROPERTY_GET(volume, double);
}

void HTMLMediaElement::setVolume(double value)
{
    this->_volume = value;
    this->v.set("volume", value);
}
