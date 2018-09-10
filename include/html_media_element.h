#pragma once

#include "html_element.h"
#include <string>

#include "text_track.h"

class AudioTrackList;
class TimeRanges;
class MediaController;
class MediaError;
class TextTrackList;
class VideoTrackList;
class TextTrack;
class Date;

enum class CanPlayTypeResult {
    MAYBE,
    PROBABLY,
    UNKNOWN,
};

class HTMLMediaElement : public HTMLElement {
public:
    enum {
        HAVE_NOTHING      = 0,
        HAVE_METADATA     = 1,
        HAVE_CURRENT_DATA = 2,
        HAVE_FUTURE_DATA  = 3,
        HAVE_ENOUGH_DATA  = 4,
    };

    enum {
        NETWORK_EMPTY     = 0,
        NETWORK_IDLE      = 1,
        NETWORK_LOADING   = 2,
        NETWORK_NO_SOURCE = 3,
    };

    AudioTrackList *_audioTracks;
    bool _autoPlay;
    TimeRanges *_buffered;
    MediaController *_controller;
    bool _controls;
    std::string _crossOrigin;
    std::string _currentSrc;
    double _currentTime;
    bool _defaultMuted;
    double _defaultPlaybackRate;
    double _duration;
    bool _ended;
    MediaError *_error;
    bool _loop;
    std::string _mediaGroup;
    bool _muted;
    unsigned short _networkState;
    bool _paused;
    double _playbackRate;
    TimeRanges *_played;
    std::string _preload;
    unsigned short _readyState;
    TimeRanges *_seekable;
    bool _seeking;
    std::string _src;
    TextTrackList *_textTracks;
    VideoTrackList *_videoTracks;
    double _volume;

    HTMLMediaElement(emscripten::val v);
    virtual ~HTMLMediaElement();
    static HTMLMediaElement *create(emscripten::val v);
    TextTrack *addTextTrack(TextTrackKind kind);
    TextTrack *addTextTrack(TextTrackKind kind, std::string label, std::string language);
    CanPlayTypeResult canPlayType(std::string type);
    void fastSeek(double time);
    Date *getStartDate();
    void load();
    void pause();
    void play();

    AudioTrackList *getAudioTracks() const;
    void setAudioTracks(AudioTrackList *value);
    bool getAutoPlay() const;
    void setAutoPlay(bool value);
    TimeRanges *getBuffered() const;
    void setBuffered(TimeRanges *value);
    MediaController *getController() const;
    void setController(MediaController *value);
    bool getControls() const;
    void setControls(bool value);
    std::string getCrossOrigin() const;
    void setCrossOrigin(std::string value);
    std::string getCurrentSrc() const;
    void setCurrentSrc(std::string value);
    double getCurrentTime() const;
    void setCurrentTime(double value);
    bool getDefaultMuted() const;
    void setDefaultMuted(bool value);
    double getDefaultPlaybackRate() const;
    void setDefaultPlaybackRate(double value);
    double getDuration() const;
    void setDuration(double value);
    bool getEnded() const;
    void setEnded(bool value);
    MediaError *getError() const;
    void setError(MediaError *value);
    bool getLoop() const;
    void setLoop(bool value);
    std::string getMediaGroup() const;
    void setMediaGroup(std::string value);
    bool getMuted() const;
    void setMuted(bool value);
    unsigned short getNetworkState() const;
    void setNetworkState(unsigned short value);
    bool getPaused() const;
    void setPaused(bool value);
    double getPlaybackRate() const;
    void setPlaybackRate(double value);
    TimeRanges *getPlayed() const;
    void setPlayed(TimeRanges *value);
    std::string getPreload() const;
    void setPreload(std::string value);
    unsigned short getReadyState() const;
    void setReadyState(unsigned short value);
    TimeRanges *getSeekable() const;
    void setSeekable(TimeRanges *value);
    bool getSeeking() const;
    void setSeeking(bool value);
    std::string getSrc() const;
    void setSrc(std::string value);
    TextTrackList *getTextTracks() const;
    void setTextTracks(TextTrackList *value);
    VideoTrackList *getVideoTracks() const;
    void setVideoTracks(VideoTrackList *value);
    double getVolume() const;
    void setVolume(double value);

    struct {
        HTMLMediaElement &self;
        void operator=(AudioTrackList *value) { self.setAudioTracks(value); };
        operator AudioTrackList *() { return self.getAudioTracks(); };
    } audioTracks{*this};

    struct {
        HTMLMediaElement &self;
        void operator=(bool value) { self.setAutoPlay(value); };
        operator bool() { return self.getAutoPlay(); };
    } autoplay{*this};

    struct {
        HTMLMediaElement &self;
        void operator=(TimeRanges *value) { self.setBuffered(value); };
        operator TimeRanges *() { return self.getBuffered(); };
    } buffered{*this};

    struct {
        HTMLMediaElement &self;
        void operator=(MediaController *value) { self.setController(value); };
        operator MediaController *() { return self.getController(); };
    } controller{*this};

    struct {
        HTMLMediaElement &self;
        void operator=(bool value) { self.setControls(value); };
        operator bool() { return self.getControls(); };
    } controls{*this};

    struct {
        HTMLMediaElement &self;
        void operator=(std::string value) { self.setCrossOrigin(value); };
        operator std::string() { return self.getCrossOrigin(); };
    } crossOrigin{*this};

    struct {
        HTMLMediaElement &self;
        void operator=(std::string value) { self.setCurrentSrc(value); };
        operator std::string() { return self.getCurrentSrc(); };
    } currentSrc{*this};

    struct {
        HTMLMediaElement &self;
        void operator=(double value) { self.setCurrentTime(value); };
        operator double() { return self.getCurrentTime(); };
    } currentTime{*this};

    struct {
        HTMLMediaElement &self;
        void operator=(bool value) { self.setDefaultMuted(value); };
        operator bool() { return self.getDefaultMuted(); };
    } defaultMuted{*this};

    struct {
        HTMLMediaElement &self;
        void operator=(double value) { self.setDefaultPlaybackRate(value); };
        operator double() { return self.getDefaultPlaybackRate(); };
    } defaultPlaybackRate{*this};

    struct {
        HTMLMediaElement &self;
        void operator=(double value) { self.setDuration(value); };
        operator double() { return self.getDuration(); };
    } duration{*this};

    struct {
        HTMLMediaElement &self;
        void operator=(bool value) { self.setEnded(value); };
        operator bool() { return self.getEnded(); };
    } ended{*this};

    struct {
        HTMLMediaElement &self;
        void operator=(MediaError *value) { self.setError(value); };
        operator MediaError *() { return self.getError(); };
    } error{*this};

    struct {
        HTMLMediaElement &self;
        void operator=(bool value) { self.setLoop(value); };
        operator bool() { return self.getLoop(); };
    } loop{*this};

    struct {
        HTMLMediaElement &self;
        void operator=(std::string value) { self.setMediaGroup(value); };
        operator std::string() { return self.getMediaGroup(); };
    } mediaGroup{*this};

    struct {
        HTMLMediaElement &self;
        void operator=(bool value) { self.setMuted(value); };
        operator bool() { return self.getMuted(); };
    } muted{*this};

    struct {
        HTMLMediaElement &self;
        void operator=(unsigned short value) { self.setNetworkState(value); };
        operator unsigned short() { return self.getNetworkState(); };
    } networkState{*this};

    struct {
        HTMLMediaElement &self;
        void operator=(bool value) { self.setPaused(value); };
        operator bool() { return self.getPaused(); };
    } paused{*this};

    struct {
        HTMLMediaElement &self;
        void operator=(double value) { self.setPlaybackRate(value); };
        operator double() { return self.getPlaybackRate(); };
    } playbackRate{*this};

    struct {
        HTMLMediaElement &self;
        void operator=(TimeRanges *value) { self.setPlayed(value); };
        operator TimeRanges *() { return self.getPlayed(); };
    } played{*this};

    struct {
        HTMLMediaElement &self;
        void operator=(std::string value) { self.setPreload(value); };
        operator std::string() { return self.getPreload(); };
    } preload{*this};

    struct {
        HTMLMediaElement &self;
        void operator=(unsigned short value) { self.setReadyState(value); };
        operator unsigned short() { return self.getReadyState(); };
    } readyState{*this};

    struct {
        HTMLMediaElement &self;
        void operator=(TimeRanges *value) { self.setSeekable(value); };
        operator TimeRanges *() { return self.getSeekable(); };
    } seekable{*this};

    struct {
        HTMLMediaElement &self;
        void operator=(bool value) { self.setSeeking(value); };
        operator bool() { return self.getSeeking(); };
    } seeking{*this};

    struct {
        HTMLMediaElement &self;
        void operator=(std::string value) { self.setSrc(value); };
        operator std::string() { return self.getSrc(); };
    } src{*this};

    struct {
        HTMLMediaElement &self;
        void operator=(TextTrackList *value) { self.setTextTracks(value); };
        operator TextTrackList *() { return self.getTextTracks(); };
    } textTracks{*this};

    struct {
        HTMLMediaElement &self;
        void operator=(VideoTrackList *value) { self.setVideoTracks(value); };
        operator VideoTrackList *() { return self.getVideoTracks(); };
    } videoTracks{*this};

    struct {
        HTMLMediaElement &self;
        void operator=(double value) { self.setVolume(value); };
        operator double() { return self.getVolume(); };
    } volume{*this};
};
