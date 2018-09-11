#include "time_ranges.h"
#include "event_handler.h"
#include "media_controller.h"

MediaController::MediaController(emscripten::val v) :
    EventTarget(v)
{

}

MediaController::~MediaController()
{

}

MediaController *MediaController::create(emscripten::val v)
{
    MediaController *mc = new MediaController(v);
    mc->autorelease();
    return mc;
}

emscripten::val MediaController::getValue() const
{
    return this->v;
}

void MediaController::pause()
{
    HTML5_CALL(this->v, pause);
}

void MediaController::play()
{
    HTML5_CALL(this->v, play);
}

void MediaController::unpause()
{
    HTML5_CALL(this->v, unpause);
}

TimeRanges *MediaController::getBuffered() const
{
    return HTML5_PROPERTY_GET(buffered, TimeRanges);
}

void MediaController::setBuffered(TimeRanges *value)
{
    this->_buffered = value;
    this->v.set("buffered", value->v);
}

double MediaController::getCurrentTime() const
{
    return HTML5_PROPERTY_GET(currentTime, double);
}

void MediaController::setCurrentTime(double value)
{
    this->_currentTime = value;
    this->v.set("currentTime", value);
}

double MediaController::getDefaultPlaybackRate() const
{
    return HTML5_PROPERTY_GET(defaultPlaybackRate, double);
}

void MediaController::setDefaultPlaybackRate(double value)
{
    this->_defaultPlaybackRate = value;
    this->v.set("defaultPlaybackRate", value);
}

double MediaController::getDuration() const
{
    return HTML5_PROPERTY_GET(duration, double);
}

void MediaController::setDuration(double value)
{
    this->_duration = value;
    this->v.set("duration", value);
}

bool MediaController::getMuted() const
{
    return HTML5_PROPERTY_GET(muted, bool);
}

void MediaController::setMuted(bool value)
{
    this->_muted = value;
    this->v.set("muted", value);
}

EventHandler *MediaController::getOnCanplay() const
{
    return this->_oncanplay;
}

void MediaController::setOnCanplay(EventHandler *value)
{
    this->_oncanplay = value;
    EM_ASM_({
        const element = Module.toMediaController($0);
        element._value.oncanplay = function(e) { element.onCanplayCallback(e); };
    }, this);
}

void MediaController::onCanplayCallback(emscripten::val e)
{
    if (!this->_oncanplay) return;

    (*this->_oncanplay)(Event::create(e));
}

EventHandler *MediaController::getOnCanplayThrough() const
{
    return this->_oncanplaythrough;
}

void MediaController::setOnCanplayThrough(EventHandler *value)
{
    this->_oncanplaythrough = value;
    EM_ASM_({
        const element = Module.toMediaController($0);
        element._value.oncanplaythrough = function(e) { element.onCanplayThroughCallback(e); };
    }, this);
}

void MediaController::onCanplayThroughCallback(emscripten::val e)
{
    if (!this->_oncanplaythrough) return;

    (*this->_oncanplaythrough)(Event::create(e));
}

EventHandler *MediaController::getOnDurationChange() const
{
    return this->_ondurationchange;
}

void MediaController::setOnDurationChange(EventHandler *value)
{
    this->_ondurationchange = value;
    EM_ASM_({
        const element = Module.toMediaController($0);
        element._value.ondurationchange = function(e) { element.onDurationChangeCallback(e); };
    }, this);
}

void MediaController::onDurationChangeCallback(emscripten::val e)
{
    if (!this->_ondurationchange) return;

    (*this->_ondurationchange)(Event::create(e));
}

EventHandler *MediaController::getOnEmptied() const
{
    return this->_onemptied;
}

void MediaController::setOnEmptied(EventHandler *value)
{
    this->_onemptied = value;
    EM_ASM_({
        const element = Module.toMediaController($0);
        element._value.onemptied = function(e) { element.onEmptiedCallback(e); };
    }, this);
}

void MediaController::onEmptiedCallback(emscripten::val e)
{
    if (!this->_onemptied) return;

    (*this->_onemptied)(Event::create(e));
}

EventHandler *MediaController::getOnEnded() const
{
    return this->_onended;
}

void MediaController::setOnEnded(EventHandler *value)
{
    this->_onended = value;
    EM_ASM_({
        const element = Module.toMediaController($0);
        element._value.onended = function(e) { element.onEndedCallback(e); };
    }, this);
}

void MediaController::onEndedCallback(emscripten::val e)
{
    if (!this->_onended) return;

    (*this->_onended)(Event::create(e));
}

EventHandler *MediaController::getOnLoadedData() const
{
    return this->_onloadeddata;
}

void MediaController::setOnLoadedData(EventHandler *value)
{
    this->_onloadeddata = value;
    EM_ASM_({
        const element = Module.toMediaController($0);
        element._value.onloadeddata = function(e) { element.onLoadedDataCallback(e); };
    }, this);
}

void MediaController::onLoadedDataCallback(emscripten::val e)
{
    if (!this->_onloadeddata) return;

    (*this->_onloadeddata)(Event::create(e));
}
    
EventHandler *MediaController::getOnLoadedMetaData() const
{
    return this->_onloadedmetadata;
}

void MediaController::setOnLoadedMetaData(EventHandler *value)
{
    this->_onloadedmetadata = value;
    EM_ASM_({
        const element = Module.toMediaController($0);
        element._value.onloadedmetadata = function(e) { element.onLoadedMetaDataCallback(e); };
    }, this);
}

void MediaController::onLoadedMetaDataCallback(emscripten::val e)
{
    if (!this->_onloadedmetadata) return;

    (*this->_onloadedmetadata)(Event::create(e));
}

EventHandler *MediaController::getOnPause() const
{
    return this->_onpause;
}

void MediaController::setOnPause(EventHandler *value)
{
    this->_onpause = value;
    EM_ASM_({
        const element = Module.toMediaController($0);
        element._value.onpause = function(e) { element.onPauseCallback(e); };
    }, this);
}

void MediaController::onPauseCallback(emscripten::val e)
{
    if (!this->_onpause) return;

    (*this->_onpause)(Event::create(e));
}

EventHandler *MediaController::getOnPlay() const
{
    return this->_onplay;
}

void MediaController::setOnPlay(EventHandler *value)
{
    this->_onplay = value;
    EM_ASM_({
        const element = Module.toMediaController($0);
        element._value.onplay = function(e) { element.onPlayCallback(e); };
    }, this);
}

void MediaController::onPlayCallback(emscripten::val e)
{
    if (!this->_onplay) return;

    (*this->_onplay)(Event::create(e));
}

EventHandler *MediaController::getOnPlaying() const
{
    return this->_onplaying;
}

void MediaController::setOnPlaying(EventHandler *value)
{
    this->_onplaying = value;
    EM_ASM_({
        const element = Module.toMediaController($0);
        element._value.onplaying = function(e) { element.onPlayingCallback(e); };
    }, this);
}

void MediaController::onPlayingCallback(emscripten::val e)
{
    if (!this->_onplaying) return;

    (*this->_onplaying)(Event::create(e));
}

EventHandler *MediaController::getOnRateChange() const
{
    return this->_onratechange;
}

void MediaController::setOnRateChange(EventHandler *value)
{
    this->_onratechange = value;
    EM_ASM_({
        const element = Module.toMediaController($0);
        element._value.onratechange = function(e) { element.onRateChangeCallback(e); };
    }, this);
}

void MediaController::onRateChangeCallback(emscripten::val e)
{
    if (!this->_onratechange) return;

    (*this->_onratechange)(Event::create(e));
}


EventHandler *MediaController::getOnTimeUpdate() const
{
    return this->_ontimeupdate;
}

void MediaController::setOnTimeUpdate(EventHandler *value)
{
    this->_ontimeupdate = value;
    EM_ASM_({
        const element = Module.toMediaController($0);
        element._value.ontimeupdate = function(e) { element.onTimeUpdateCallback(e); };
    }, this);
}

void MediaController::onTimeUpdateCallback(emscripten::val e)
{
    if (!this->_ontimeupdate) return;

    (*this->_ontimeupdate)(Event::create(e));
}

EventHandler *MediaController::getOnVolumeChange() const
{
    return this->_onvolumechange;
}

void MediaController::setOnVolumeChange(EventHandler *value)
{
    this->_onvolumechange = value;
    EM_ASM_({
        const element = Module.toMediaController($0);
        element._value.onvolumechange = function(e) { element.onVolumeChangeCallback(e); };
    }, this);
}

void MediaController::onVolumeChangeCallback(emscripten::val e)
{
    if (!this->_onvolumechange) return;

    (*this->_onvolumechange)(Event::create(e));
}

EventHandler *MediaController::getOnWaiting() const
{
    return this->_onwaiting;
}

void MediaController::setOnWaiting(EventHandler *value)
{
    this->_onwaiting = value;
    EM_ASM_({
        const element = Module.toMediaController($0);
        element._value.onwaiting = function(e) { element.onWaitingCallback(e); };
    }, this);
}

void MediaController::onWaitingCallback(emscripten::val e)
{
    if (!this->_onwaiting) return;

    (*this->_onwaiting)(Event::create(e));
}

bool MediaController::getPaused() const
{
    return HTML5_PROPERTY_GET(paused, bool);
}

void MediaController::setPaused(bool value)
{
    this->_paused = value;
    this->v.set("paused", value);
}

double MediaController::getPlaybackRate() const
{
    return HTML5_PROPERTY_GET(playbackRate, double);
}

void MediaController::setPlaybackRate(double value)
{
    this->_playbackRate = value;
    this->v.set("playbackRate", value);
}

std::string MediaController::getPlaybackState() const
{
#if ENABLE_EMSCRIPTEN
    return this->v["playbackState"].as<std::string>();
#else
    return "";
#endif
}

void MediaController::setPlaybackState(MediaControllerPlaybackState value)
{
    this->_playbackState = value;
    switch (value) {
    case MediaControllerPlaybackState::WAITING:
        this->v.set("playbackState", "waiting");
        break;
    case MediaControllerPlaybackState::PLAYING:
        this->v.set("playbackState", "playing");
        break;
    case MediaControllerPlaybackState::ENDED:
        this->v.set("playbackState", "ended");
        break;
    }
}

TimeRanges *MediaController::getPlayed() const
{
    return HTML5_PROPERTY_GET(played, TimeRanges);
}

void MediaController::setPlayed(TimeRanges *value)
{
    this->_played = value;
    this->v.set("played", value->v);
}

unsigned short MediaController::getReadyState() const
{
    return HTML5_PROPERTY_GET(readyState, unsigned short);
}

void MediaController::setReadyState(unsigned short value)
{
    this->_readyState = value;
    this->v.set("readyState", value);
}

TimeRanges *MediaController::getSeekable() const
{
    return HTML5_PROPERTY_GET(seekable, TimeRanges);
}

void MediaController::setSeekable(TimeRanges *value)
{
    this->_seekable = value;
    this->v.set("seekable", value->v);
}

double MediaController::getVolume() const
{
    return HTML5_PROPERTY_GET(volume, double);
}

void MediaController::setVolume(double value)
{
    this->_volume = value;
    this->v.set("volume", value);
}
