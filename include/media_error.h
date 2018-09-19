#pragma once

#include "libhtml5.h"

class MediaError : public Object {
public:

    enum {
        MEDIA_ERR_ABORTED = 1,
        MEDIA_ERR_NETWORK = 2,
        MEDIA_ERR_DECODE  = 3,
        MEDIA_ERR_SRC_NOT_SUPPORTED = 4,
    };

    emscripten::val v;

    HTML5_PROPERTY(MediaError, unsigned short, code);

    MediaError(emscripten::val v);
    virtual ~MediaError();
    static MediaError *create(emscripten::val v);
};
