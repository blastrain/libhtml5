#pragma once

#include "event_target.h"
#include "event_handler.h"

class AudioTrack;

class AudioTrackList : public EventTarget {
public:
    unsigned long _length;
    EventHandler *_onaddtrack;
    EventHandler *_onchange;
    EventHandler *_onremovetrack;

    AudioTrackList(emscripten::val v);
    virtual ~AudioTrackList();
    emscripten::val getValue() const;
    static AudioTrackList *create(emscripten::val v);
    AudioTrack *getter(unsigned long index);
    AudioTrack *getTrackById(std::string id);
    unsigned long getLength() const;
    void setLength(unsigned long value);
    EventHandler *getOnAddTrack() const;
    void setOnAddTrack(EventHandler *value);
    void onAddTrackCallback(emscripten::val e);
    EventHandler *getOnChange() const;
    void setOnChange(EventHandler *value);
    void onChangeCallback(emscripten::val e);
    EventHandler *getOnRemoveTrack() const;
    void setOnRemoveTrack(EventHandler *value);
    void onRemoveTrackCallback(emscripten::val e);

    struct {
        AudioTrackList &self;
        void operator=(unsigned long value) { self.setLength(value); };
        operator unsigned long() { return self.getLength(); };
    } length{*this};

    struct {
        AudioTrackList &self;
        void operator=(EventHandler *value) { self.setOnAddTrack(value); };
        operator EventHandler *() { return self.getOnAddTrack(); };
    } onaddtrack{*this};

    struct {
        AudioTrackList &self;
        void operator=(EventHandler *value) { self.setOnChange(value); };
        operator EventHandler *() { return self.getOnChange(); };
    } onchange{*this};

    struct {
        AudioTrackList &self;
        void operator=(EventHandler *value) { self.setOnRemoveTrack(value); };
        operator EventHandler *() { return self.getOnRemoveTrack(); };
    } onremovetrack{*this};

};
