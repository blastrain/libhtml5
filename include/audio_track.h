#pragma once

#include "libhtml5.h"

NAMESPACE_HTML5_BEGIN;

class AudioTrack : public Object {
public:
    emscripten::val v;

    HTML5_PROPERTY(AudioTrack, bool, enabled);
    HTML5_PROPERTY(AudioTrack, std::string, id);
    HTML5_PROPERTY(AudioTrack, std::string, kind);
    HTML5_PROPERTY(AudioTrack, std::string, label);
    HTML5_PROPERTY(AudioTrack, std::string, language);

    AudioTrack(emscripten::val v);
    virtual ~AudioTrack();
    static AudioTrack *create(emscripten::val v);
};

NAMESPACE_HTML5_END;
