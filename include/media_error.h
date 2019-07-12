#pragma once

#include "html5.h"

NAMESPACE_HTML5_BEGIN;

class MediaError : public Object {
public:

    enum {
        MEDIA_ERR_ABORTED = 1,
        MEDIA_ERR_NETWORK = 2,
        MEDIA_ERR_DECODE  = 3,
        MEDIA_ERR_SRC_NOT_SUPPORTED = 4,
    };

    HTML5_PROPERTY(MediaError, unsigned short, code);

    MediaError(emscripten::val v);
    virtual ~MediaError();
    static MediaError *create(emscripten::val v);
};

NAMESPACE_HTML5_END;
