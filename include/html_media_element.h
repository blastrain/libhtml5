#pragma once

#include "html_element.h"
#include <string>

class HTMLMediaElement : public HTMLElement {
public:
    typedef enum {
        HAVE_NOTHING      = 0,
        HAVE_METADATA     = 1,
        HAVE_CURRENT_DATA = 2,
        HAVE_FUTURE_DATA  = 3,
        HAVE_ENOUGH_DATA  = 4,
    } READY_STATE;

    void *audioTracks;
    bool autoPlay;
    void *buffered;
    void *controller;
    bool controls;
    std::string crossOrigin;
    std::string currentSrc;
    double _currentTime;
    bool defaultMuted;
    double defaultPlaybackRate;
    double duration;
    bool _ended;
    void *error;
    bool loop;
    std::string mediaGroup;
    void *mediaKeys;
    bool muted;
    unsigned short networkState;
    bool _paused;
    double playbackRate;
    void *played;
    std::string preload;
    bool preservePitch;
    READY_STATE _readyState;
    void *seekable;
    bool seeking;
    std::string skinId;
    std::string _src;
    void *srcObject;
    double volume;
    void *textTracks;
    void *videoTracks;

    HTMLMediaElement(emscripten::val v);
    virtual ~HTMLMediaElement();
    static HTMLMediaElement *create();
    void addTextTrack();
    bool canPlayType();
    void fastSeek();
    void load();
    void pause();
    void play();
    void setMediaKeys();
    void setSkinId();
    READY_STATE readyState();
    bool paused();
    bool ended();
    double currentTime();
    void src(std::string value);
    std::string src();
};
