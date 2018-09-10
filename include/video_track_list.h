#pragma once

#include "event_target.h"

class VideoTrack;

class VideoTrackList : public EventTarget {
public:
    unsigned long _length;
    EventHandler *_onaddtrack;
    EventHandler *_onchange;
    EventHandler *_onremovetrack;
    long _selectedIndex;

    VideoTrackList(emscripten::val v);
    virtual ~VideoTrackList();
    emscripten::val getValue() const;
    VideoTrackList *create(emscripten::val v);
    VideoTrack *getter(unsigned long index);
    VideoTrack *getTrackById(std::string id);
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
    long getSelectedIndex() const;
    void setSelectedIndex(long value);

    struct {
        VideoTrackList &self;
        void operator=(unsigned long value) { self.setLength(value); };
        operator unsigned long() { return self.getLength(); };
    } length{*this};

    struct {
        VideoTrackList &self;
        void operator=(EventHandler *value) { self.setOnAddTrack(value); };
        operator EventHandler *() { return self.getOnAddTrack(); };
    } onaddtrack{*this};

    struct {
        VideoTrackList &self;
        void operator=(EventHandler *value) { self.setOnChange(value); };
        operator EventHandler *() { return self.getOnChange(); };
    } onchange{*this};

    struct {
        VideoTrackList &self;
        void operator=(EventHandler *value) { self.setOnRemoveTrack(value); };
        operator EventHandler *() { return self.getOnRemoveTrack(); };
    } onremovetrack{*this};

    struct {
        VideoTrackList &self;
        void operator=(unsigned long value) { self.setSelectedIndex(value); };
        operator unsigned long() { return self.getSelectedIndex(); };
    } selectedIndex{*this};

};
