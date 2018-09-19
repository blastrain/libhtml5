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

    HTML5_PROPERTY(MediaController, double, currentTime);
    HTML5_PROPERTY_OBJECT(MediaController, TimeRanges, buffered);
    HTML5_PROPERTY(MediaController, double, defaultPlaybackRate);
    HTML5_PROPERTY(MediaController, double, duration);
    HTML5_PROPERTY(MediaController, bool, muted);
    HTML5_EVENT_HANDLER_PROPERTY(MediaController, EventHandler *, oncanplay);
    HTML5_EVENT_HANDLER_PROPERTY(MediaController, EventHandler *, oncanplaythrough);
    HTML5_EVENT_HANDLER_PROPERTY(MediaController, EventHandler *, ondurationchange);
    HTML5_EVENT_HANDLER_PROPERTY(MediaController, EventHandler *, onemptied);
    HTML5_EVENT_HANDLER_PROPERTY(MediaController, EventHandler *, onended);
    HTML5_EVENT_HANDLER_PROPERTY(MediaController, EventHandler *, onloadeddata);
    HTML5_EVENT_HANDLER_PROPERTY(MediaController, EventHandler *, onloadedmetadata);
    HTML5_EVENT_HANDLER_PROPERTY(MediaController, EventHandler *, onpause);
    HTML5_EVENT_HANDLER_PROPERTY(MediaController, EventHandler *, onplay);
    HTML5_EVENT_HANDLER_PROPERTY(MediaController, EventHandler *, onplaying);
    HTML5_EVENT_HANDLER_PROPERTY(MediaController, EventHandler *, onratechange);
    HTML5_EVENT_HANDLER_PROPERTY(MediaController, EventHandler *, ontimeupdate);
    HTML5_EVENT_HANDLER_PROPERTY(MediaController, EventHandler *, onvolumechange);
    HTML5_EVENT_HANDLER_PROPERTY(MediaController, EventHandler *, onwaiting);
    HTML5_PROPERTY(MediaController, bool, paused);
    HTML5_PROPERTY(MediaController, double, playbackRate);
    MediaControllerPlaybackState _playbackState;
    HTML5_PROPERTY_OBJECT(MediaController, TimeRanges, played);
    HTML5_PROPERTY(MediaController, unsigned short, readyState);
    HTML5_PROPERTY_OBJECT(MediaController, TimeRanges, seekable);
    HTML5_PROPERTY(MediaController, double, volume);

    MediaController(emscripten::val v);
    virtual ~MediaController();
    static MediaController *create(emscripten::val v);
    void pause();
    void play();
    void unpause();

    std::string getPlaybackState() const;
    void setPlaybackState(MediaControllerPlaybackState value);

    struct {
        MediaController &self;
        void operator=(MediaControllerPlaybackState value) { self.setPlaybackState(value); };
        operator std::string() { return self.getPlaybackState(); };
    } playbackState{*this};
};
