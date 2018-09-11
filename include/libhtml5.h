#pragma once

#include "object.h"

#define HTML5_DELETE(o) do {                    \
        if (o) {                                \
            delete o;                           \
            o = NULL;                           \
        }                                       \
    } while (0)

#define HTML5_RELEASE(o) do {                   \
        if (o && o->isAutoRelease()) {          \
            o->release();                       \
        } else {                                \
            HTML5_DELETE(o);                    \
        }                                       \
    } while (0)

#define HTML5_PROPERTY_SET(to, from) do {       \
        if (to && to->isAutoRelease()) {        \
            to->release();                      \
        }                                       \
        if (from && from->isAutoRelease()) {    \
            from->retain();                     \
        }                                       \
        to = from;                              \
    } while (0)
