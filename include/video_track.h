#pragma once

#include "libhtml5.h"

NAMESPACE_HTML5_BEGIN;

class VideoTrack : public Object {
public:
    emscripten::val v;

    HTML5_PROPERTY(VideoTrack, std::string, id);
    HTML5_PROPERTY(VideoTrack, std::string, kind);
    HTML5_PROPERTY(VideoTrack, std::string, label);
    HTML5_PROPERTY(VideoTrack, std::string, language);
    HTML5_PROPERTY(VideoTrack, bool, selected);

    VideoTrack(emscripten::val v);
    virtual ~VideoTrack();
    static VideoTrack *create(emscripten::val v);
};

NAMESPACE_HTML5_END;
