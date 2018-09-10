#pragma once

#include "event_target.h"
#include "event_handler.h"
#include <string>

class TextTrack;

class TextTrackCue : public EventTarget {
public:
    double _endTime;
    std::string _id;
    EventHandler *_onenter;
    EventHandler *_onexit;
    bool _pauseOnExit;
    double _startTime;
    TextTrack *_track;

    TextTrackCue(emscripten::val v);
    virtual ~TextTrackCue();
    static TextTrackCue *create(emscripten::val v);
    emscripten::val getValue() const;
    double getEndTime() const;
    void setEndTime(double value);
    std::string getId() const;
    void setId(std::string value);
    EventHandler *getOnEnter() const;
    void setOnEnter(EventHandler *value);
    void onEnterCallback(emscripten::val e);
    EventHandler *getOnExit() const;
    void setOnExit(EventHandler *value);
    void onExitCallback(emscripten::val e);
    bool getPauseOnExit() const;
    void setPauseOnExit(bool value);
    double getStartTime() const;
    void setStartTime(double value);
    TextTrack *getTrack() const;
    void setTrack(TextTrack *value);

    struct {
        TextTrackCue &self;
        void operator=(double value) { self.setEndTime(value); };
        operator double() { return self.getEndTime(); };
    } endTime{*this};

    struct {
        TextTrackCue &self;
        void operator=(std::string value) { self.setId(value); };
        operator std::string() { return self.getId(); };
    } id{*this};

    struct {
        TextTrackCue &self;
        void operator=(EventHandler *value) { self.setOnEnter(value); };
        operator EventHandler *() { return self.getOnEnter(); };
    } onenter{*this};

    struct {
        TextTrackCue &self;
        void operator=(EventHandler *value) { self.setOnExit(value); };
        operator EventHandler *() { return self.getOnExit(); };
    } onexit{*this};

    struct {
        TextTrackCue &self;
        void operator=(bool value) { self.setPauseOnExit(value); };
        operator bool() { return self.getPauseOnExit(); };
    } pauseOnExit{*this};

    struct {
        TextTrackCue &self;
        void operator=(double value) { self.setStartTime(value); };
        operator double() { return self.getStartTime(); };
    } startTime{*this};

    struct {
        TextTrackCue &self;
        void operator=(TextTrack *value) { self.setTrack(value); };
        operator TextTrack *() { return self.getTrack(); };
    } track{*this};
};
