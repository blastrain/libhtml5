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
class CanPlayTypeResult;
class Date;

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
    static HTMLMediaElement *create();
    static HTMLMediaElement *create(emscripten::val v);
    TextTrack *addTextTrack(TextTrackKind *kind);
    TextTrack *addTextTrack(TextTrackKind *kind, std::string label, std::string language);
    CanPlayTypeResult *canPlayType(std::string type);
    void fastSeek(double time);
    Date *getStartDate();
    void load();
    void pause();
    void play();
};
