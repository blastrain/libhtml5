#pragma once

#include "event_target.h"
#include "event_handler.h"

NAMESPACE_HTML5_BEGIN;

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

    HTML5_PROPERTY_OBJECT(TextTrack, TextTrackCueList, activeCues);
    HTML5_PROPERTY_OBJECT(TextTrack, TextTrackCueList, cues);
    HTML5_PROPERTY(TextTrack, std::string, id);
    HTML5_PROPERTY(TextTrack, std::string, inBandMetadataTrackDispatchType);
    HTML5_PROPERTY(TextTrack, std::string, label);
    HTML5_PROPERTY(TextTrack, std::string, language);
    HTML5_EVENT_HANDLER_PROPERTY(TextTrack, EventHandler *, oncuechange);
    TextTrackKind _kind;
    TextTrackMode _mode;

    TextTrack(emscripten::val v);
    virtual ~TextTrack();
    static TextTrack *create(emscripten::val v);
    void addCue(TextTrackCue *cue);
    void removeCue(TextTrackCue *cue);

    std::string getKind() const;
    void setKind(TextTrackKind value);
    std::string getMode() const;
    void setMode(TextTrackMode value);

    struct {
        TextTrack &self;
        void operator=(TextTrackKind value) { self.setKind(value); };
        operator std::string() { return self.getKind(); };
    } kind{*this};

    struct {
        TextTrack &self;
        void operator=(TextTrackMode value) { self.setMode(value); };
        operator std::string() { return self.getMode(); };
    } mode{*this};
};

NAMESPACE_HTML5_END;
