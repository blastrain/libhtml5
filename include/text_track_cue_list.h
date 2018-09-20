#pragma once

#include "libhtml5.h"

NAMESPACE_HTML5_BEGIN;

class TextTrackCue;

class TextTrackCueList : public Object {
public:

    HTML5_PROPERTY(TextTrackCueList, unsigned long, length);

    TextTrackCueList(emscripten::val v);
    virtual ~TextTrackCueList();
    static TextTrackCueList *create(emscripten::val v);
    TextTrackCue *getCueById(std::string id);
    TextTrackCue *getter(unsigned long index);
};

NAMESPACE_HTML5_END;
