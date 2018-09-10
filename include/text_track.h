#pragma once

#include "event_target.h"
#include "event_handler.h"

class TextTrackCue;
class TextTrackCueList;

enum class TextTrackMode {
    DISABLED,
    HIDDEN,
    SHOWING,
};

enum class TextTrackKind {
    SUBTITLES,
    CAPTIONS,
    DESCRIPTIONS,
    CHAPTERS,
    METADATA,
};

class TextTrack : public EventTarget {
public:
    TextTrackCueList *_activeCues;
    TextTrackCueList *_cues;
    std::string _id;
    std::string _inBandMetadataTrackDispatchType;
    TextTrackKind _kind;
    std::string _label;
    std::string _language;
    TextTrackMode _mode;
    EventHandler *_oncuechange;

    TextTrack(emscripten::val v);
    virtual ~TextTrack();
    static TextTrack *create(emscripten::val v);
    void addCue(TextTrackCue *cue);
    void removeCue(TextTrackCue *cue);
    emscripten::val getValue() const;

    TextTrackCueList *getActiveCues() const;
    void setActiveCues(TextTrackCueList *value);
    TextTrackCueList *getCues() const;
    void setCues(TextTrackCueList *value);
    std::string getId() const;
    void setId(std::string value);
    std::string getInBandMetadataTrackDispatchType() const;
    void setInBandMetadataTrackDispatchType(std::string value);
    std::string getKind() const;
    void setKind(TextTrackKind value);
    std::string getLabel() const;
    void setLabel(std::string value);
    std::string getLanguage() const;
    void setLanguage(std::string value);
    std::string getMode() const;
    void setMode(TextTrackMode value);
    EventHandler *getOnCueChange() const;
    void setOnCueChange(EventHandler *value);
    void onCueChangeCallback(emscripten::val e);

    struct {
        TextTrack &self;
        void operator=(TextTrackCueList *value) { self.setActiveCues(value); };
        operator TextTrackCueList *() { return self.getActiveCues(); };
    } activeCues{*this};

    struct {
        TextTrack &self;
        void operator=(TextTrackCueList *value) { self.setCues(value); };
        operator TextTrackCueList *() { return self.getCues(); };
    } cues{*this};

    struct {
        TextTrack &self;
        void operator=(std::string value) { self.setId(value); };
        operator std::string() { return self.getId(); };
    } id{*this};

    struct {
        TextTrack &self;
        void operator=(std::string value) { self.setInBandMetadataTrackDispatchType(value); };
        operator std::string() { return self.getInBandMetadataTrackDispatchType(); };
    } inBandMetadataTrackDispatchType{*this};

    struct {
        TextTrack &self;
        void operator=(TextTrackKind value) { self.setKind(value); };
        operator std::string() { return self.getKind(); };
    } kind{*this};

    struct {
        TextTrack &self;
        void operator=(std::string value) { self.setLabel(value); };
        operator std::string() { return self.getLabel(); };
    } label{*this};

    struct {
        TextTrack &self;
        void operator=(std::string value) { self.setLanguage(value); };
        operator std::string() { return self.getLanguage(); };
    } language{*this};

    struct {
        TextTrack &self;
        void operator=(TextTrackMode value) { self.setMode(value); };
        operator std::string() { return self.getMode(); };
    } mode{*this};

    struct {
        TextTrack &self;
        void operator=(EventHandler *value) { self.setOnCueChange(value); };
        operator EventHandler *() { return self.getOnCueChange(); };
    } oncuechange{*this};

};
