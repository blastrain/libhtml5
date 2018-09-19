#pragma once

#include "libhtml5.h"

NAMESPACE_HTML5_BEGIN;

class MediaList : public Object {
public:
    emscripten::val v;

    HTML5_PROPERTY(MediaList, unsigned long, length);
    HTML5_PROPERTY(MediaList, std::string, mediaText);

    MediaList(emscripten::val v);
    virtual ~MediaList();
    static MediaList *create(emscripten::val v);
    void appendMedium(std::string medium);
    void deleteMedium(std::string medium);
    std::string item(unsigned long index);
};

NAMESPACE_HTML5_END;
