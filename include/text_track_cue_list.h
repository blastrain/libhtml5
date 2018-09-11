#pragma once

#include "libhtml5.h"

class TextTrackCue;

class TextTrackCueList : public Object {
public:
    emscripten::val v;
    unsigned long _length;

    TextTrackCueList(emscripten::val v);
    virtual ~TextTrackCueList();
    static TextTrackCueList *create(emscripten::val v);
    TextTrackCue *getCueById(std::string id);
    TextTrackCue *getter(unsigned long index);
    unsigned long getLength() const;
    void setLength(unsigned long value);

    struct {
        TextTrackCueList &self;
        void operator=(unsigned long value) { self.setLength(value); };
        operator unsigned long() { return self.getLength(); };
    } length{*this};
};
