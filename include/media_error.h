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
    unsigned short _code;

    MediaError(emscripten::val v);
    virtual ~MediaError();
    static MediaError *create(emscripten::val v);
    unsigned short getCode() const;
    void setCode(unsigned short value);

    struct {
        MediaError &self;
        void operator=(unsigned short value) { self.setCode(value); };
        operator unsigned short() { return self.getCode(); };
    } code{*this};

};
