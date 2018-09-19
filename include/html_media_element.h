#pragma once

#include "html_element.h"
#include <string>

#include "text_track.h"

NAMESPACE_HTML5_BEGIN;

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

    HTML5_PROPERTY_OBJECT(HTMLMediaElement, AudioTrackList, audioTracks);
    HTML5_PROPERTY(HTMLMediaElement, bool, autoPlay);
    HTML5_PROPERTY_OBJECT(HTMLMediaElement, TimeRanges, buffered);
    HTML5_PROPERTY_OBJECT(HTMLMediaElement, MediaController, controller);
    HTML5_PROPERTY(HTMLMediaElement, bool, controls);
    HTML5_PROPERTY(HTMLMediaElement, std::string, crossOrigin);
    HTML5_PROPERTY(HTMLMediaElement, std::string, currentSrc);
    HTML5_PROPERTY(HTMLMediaElement, double, currentTime);
    HTML5_PROPERTY(HTMLMediaElement, bool, defaultMuted);
    HTML5_PROPERTY(HTMLMediaElement, double, defaultPlaybackRate);
    HTML5_PROPERTY(HTMLMediaElement, double, duration);
    HTML5_PROPERTY(HTMLMediaElement, bool, ended);
    HTML5_PROPERTY_OBJECT(HTMLMediaElement, MediaError, error);
    HTML5_PROPERTY(HTMLMediaElement, bool, loop);
    HTML5_PROPERTY(HTMLMediaElement, std::string, mediaGroup);
    HTML5_PROPERTY(HTMLMediaElement, bool, muted);
    HTML5_PROPERTY(HTMLMediaElement, unsigned short, networkState);
    HTML5_PROPERTY(HTMLMediaElement, bool, paused);
    HTML5_PROPERTY(HTMLMediaElement, double, playbackRate);
    HTML5_PROPERTY_OBJECT(HTMLMediaElement, TimeRanges, played);
    HTML5_PROPERTY(HTMLMediaElement, std::string, preload);
    HTML5_PROPERTY(HTMLMediaElement, unsigned short, readyState);
    HTML5_PROPERTY_OBJECT(HTMLMediaElement, TimeRanges, seekable);
    HTML5_PROPERTY(HTMLMediaElement, bool, seeking);
    HTML5_PROPERTY(HTMLMediaElement, std::string, src);
    HTML5_PROPERTY_OBJECT(HTMLMediaElement, TextTrackList, textTracks);
    HTML5_PROPERTY_OBJECT(HTMLMediaElement, VideoTrackList, videoTracks);
    HTML5_PROPERTY(HTMLMediaElement, double, volume);

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
};

NAMESPACE_HTML5_END;
