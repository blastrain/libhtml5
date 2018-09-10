#pragma once

#include "event_target.h"

class TimeRanges;

enum class MediaControllerPlaybackState {
    WAITING,
    PLAYING,
    ENDED,
};

class MediaController : public EventTarget {
public:
    TimeRanges *_buffered;
    double _currentTime;
    double _defaultPlaybackRate;
    double _duration;
    bool _muted;
    EventHandler *_oncanplay;
    EventHandler *_oncanplaythrough;
    EventHandler *_ondurationchange;
    EventHandler *_onemptied;
    EventHandler *_onended;
    EventHandler *_onloadeddata;
    EventHandler *_onloadedmetadata;
    EventHandler *_onpause;
    EventHandler *_onplay;
    EventHandler *_onplaying;
    EventHandler *_onratechange;
    EventHandler *_ontimeupdate;
    EventHandler *_onvolumechange;
    EventHandler *_onwaiting;
    bool _paused;
    double _playbackRate;
    MediaControllerPlaybackState _playbackState;
    TimeRanges *_played;
    unsigned short _readyState;
    TimeRanges *_seekable;
    double _volume;

    MediaController(emscripten::val v);
    virtual ~MediaController();
    static MediaController *create(emscripten::val v);
    void pause();
    void play();
    void unpause();
    emscripten::val getValue() const;
    TimeRanges *getBuffered() const;
    void setBuffered(TimeRanges *value);
    double getCurrentTime() const;
    void setCurrentTime(double value);
    double getDefaultPlaybackRate() const;
    void setDefaultPlaybackRate(double value);
    double getDuration() const;
    void setDuration(double value);
    bool getMuted() const;
    void setMuted(bool value);
    EventHandler *getOnCanplay() const;
    void setOnCanplay(EventHandler *value);
    void onCanplayCallback(emscripten::val e);
    EventHandler *getOnCanplayThrough() const;
    void setOnCanplayThrough(EventHandler *value);
    void onCanplayThroughCallback(emscripten::val e);
    EventHandler *getOnDurationChange() const;
    void setOnDurationChange(EventHandler *value);
    void onDurationChangeCallback(emscripten::val e);
    EventHandler *getOnEmptied() const;
    void setOnEmptied(EventHandler *value);
    void onEmptiedCallback(emscripten::val e);
    EventHandler *getOnEnded() const;
    void setOnEnded(EventHandler *value);
    void onEndedCallback(emscripten::val e);
    EventHandler *getOnLoadedData() const;
    void setOnLoadedData(EventHandler *value);
    void onLoadedDataCallback(emscripten::val e);
    EventHandler *getOnLoadedMetaData() const;
    void setOnLoadedMetaData(EventHandler *value);
    void onLoadedMetaDataCallback(emscripten::val e);
    EventHandler *getOnPause() const;
    void setOnPause(EventHandler *value);
    void onPauseCallback(emscripten::val e);
    EventHandler *getOnPlay() const;
    void setOnPlay(EventHandler *value);
    void onPlayCallback(emscripten::val e);
    EventHandler *getOnPlaying() const;
    void setOnPlaying(EventHandler *value);
    void onPlayingCallback(emscripten::val e);
    EventHandler *getOnRateChange() const;    
    void setOnRateChange(EventHandler *value);
    void onRateChangeCallback(emscripten::val e);
    EventHandler *getOnTimeUpdate() const;
    void setOnTimeUpdate(EventHandler *value);
    void onTimeUpdateCallback(emscripten::val e);
    EventHandler *getOnVolumeChange() const;
    void setOnVolumeChange(EventHandler *value);
    void onVolumeChangeCallback(emscripten::val e);
    EventHandler *getOnWaiting() const;
    void setOnWaiting(EventHandler *value);
    void onWaitingCallback(emscripten::val e);
    bool getPaused() const;
    void setPaused(bool value);
    double getPlaybackRate() const;
    void setPlaybackRate(double value);
    std::string getPlaybackState() const;
    void setPlaybackState(MediaControllerPlaybackState value);
    TimeRanges *getPlayed() const;
    void setPlayed(TimeRanges *value);
    unsigned short getReadyState() const;
    void setReadyState(unsigned short value);
    TimeRanges *getSeekable() const;
    void setSeekable(TimeRanges *value);
    double getVolume() const;
    void setVolume(double value);

    struct {
        MediaController &self;
        void operator=(TimeRanges *value) { self.setBuffered(value); };
        operator TimeRanges *() { return self.getBuffered(); };
    } buffered{*this};

    struct {
        MediaController &self;
        void operator=(double value) { self.setCurrentTime(value); };
        operator double() { return self.getCurrentTime(); };
    } currentTime{*this};

    struct {
        MediaController &self;
        void operator=(double value) { self.setDefaultPlaybackRate(value); };
        operator double() { return self.getDefaultPlaybackRate(); };
    } defaultPlaybackRate{*this};

    struct {
        MediaController &self;
        void operator=(double value) { self.setDuration(value); };
        operator double() { return self.getDuration(); };
    } duration{*this};

    struct {
        MediaController &self;
        void operator=(bool value) { self.setMuted(value); };
        operator bool() { return self.getMuted(); };
    } muted{*this};

    struct {
        MediaController &self;
        void operator=(EventHandler *value) { self.setOnCanplay(value); };
        operator EventHandler *() { return self.getOnCanplay(); };
    } oncanplay{*this};

    struct {
        MediaController &self;
        void operator=(EventHandler *value) { self.setOnCanplayThrough(value); };
        operator EventHandler *() { return self.getOnCanplayThrough(); };
    } oncanplaythrough{*this};

    struct {
        MediaController &self;
        void operator=(EventHandler *value) { self.setOnDurationChange(value); };
        operator EventHandler *() { return self.getOnDurationChange(); };
    } ondurationchange{*this};

    struct {
        MediaController &self;
        void operator=(EventHandler *value) { self.setOnEmptied(value); };
        operator EventHandler *() { return self.getOnEmptied(); };
    } onemptied{*this};

    struct {
        MediaController &self;
        void operator=(EventHandler *value) { self.setOnEnded(value); };
        operator EventHandler *() { return self.getOnEnded(); };
    } onended{*this};

    struct {
        MediaController &self;
        void operator=(EventHandler *value) { self.setOnLoadedData(value); };
        operator EventHandler *() { return self.getOnLoadedData(); };
    } onloadeddata{*this};

    struct {
        MediaController &self;
        void operator=(EventHandler *value) { self.setOnLoadedMetaData(value); };
        operator EventHandler *() { return self.getOnLoadedMetaData(); };
    } onloadedmetadata{*this};

    struct {
        MediaController &self;
        void operator=(EventHandler *value) { self.setOnPause(value); };
        operator EventHandler *() { return self.getOnPause(); };
    } onpause{*this};

    struct {
        MediaController &self;
        void operator=(EventHandler *value) { self.setOnPlay(value); };
        operator EventHandler *() { return self.getOnPlay(); };
    } onplay{*this};

    struct {
        MediaController &self;
        void operator=(EventHandler *value) { self.setOnPlaying(value); };
        operator EventHandler *() { return self.getOnPlaying(); };
    } onplaying{*this};

    struct {
        MediaController &self;
        void operator=(EventHandler *value) { self.setOnRateChange(value); };
        operator EventHandler *() { return self.getOnRateChange(); };
    } onratechange{*this};

    struct {
        MediaController &self;
        void operator=(EventHandler *value) { self.setOnTimeUpdate(value); };
        operator EventHandler *() { return self.getOnTimeUpdate(); };
    } ontimeupdate{*this};

    struct {
        MediaController &self;
        void operator=(EventHandler *value) { self.setOnVolumeChange(value); };
        operator EventHandler *() { return self.getOnVolumeChange(); };
    } onvolumechange{*this};

    struct {
        MediaController &self;
        void operator=(EventHandler *value) { self.setOnWaiting(value); };
        operator EventHandler *() { return self.getOnWaiting(); };
    } onwaiting{*this};

    struct {
        MediaController &self;
        void operator=(bool value) { self.setPaused(value); };
        operator bool() { return self.getPaused(); };
    } paused{*this};

    struct {
        MediaController &self;
        void operator=(double value) { self.setPlaybackRate(value); };
        operator double() { return self.getPlaybackRate(); };
    } playbackRate{*this};
    
    struct {
        MediaController &self;
        void operator=(MediaControllerPlaybackState value) { self.setPlaybackState(value); };
        operator std::string() { return self.getPlaybackState(); };
    } playbackState{*this};

    struct {
        MediaController &self;
        void operator=(TimeRanges *value) { self.setPlayed(value); };
        operator TimeRanges *() { return self.getPlayed(); };
    } played{*this};

    struct {
        MediaController &self;
        void operator=(unsigned short value) { self.setReadyState(value); };
        operator unsigned short() { return self.getReadyState(); };
    } readyState{*this};

    struct {
        MediaController &self;
        void operator=(TimeRanges *value) { self.setSeekable(value); };
        operator TimeRanges *() { return self.getSeekable(); };
    } seekable{*this};

    struct {
        MediaController &self;
        void operator=(double value) { self.setVolume(value); };
        operator double() { return self.getVolume(); };
    } volume{*this};

};
