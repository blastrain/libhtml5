#pragma once

#include "libhtml5.h"

class TextTrackCue;

class TextTrackCueList : public Object {
public:
    emscripten::val v;

    HTML5_PROPERTY(TextTrackCueList, unsigned long, length);

    TextTrackCueList(emscripten::val v);
    virtual ~TextTrackCueList();
    static TextTrackCueList *create(emscripten::val v);
    TextTrackCue *getCueById(std::string id);
    TextTrackCue *getter(unsigned long index);
};
