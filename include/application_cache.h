#pragma once

#include "event_target.h"

class ApplicationCache : public EventTarget {
public:
    enum {
        UNCACHED    = 0,
        IDLE        = 1,
        CHECKING    = 2,
        DOWNLOADING = 3,
        UPDATEREADY = 4,
        OBSOLETE    = 5,
    };

    HTML5_EVENT_HANDLER_PROPERTY(ApplicationCache, EventHandler *, oncached);
    HTML5_EVENT_HANDLER_PROPERTY(ApplicationCache, EventHandler *, onchecking);
    HTML5_EVENT_HANDLER_PROPERTY(ApplicationCache, EventHandler *, ondownloading);
    HTML5_EVENT_HANDLER_PROPERTY(ApplicationCache, EventHandler *, onerror);
    HTML5_EVENT_HANDLER_PROPERTY(ApplicationCache, EventHandler *, onnoupdate);
    HTML5_EVENT_HANDLER_PROPERTY(ApplicationCache, EventHandler *, onobsolete);
    HTML5_EVENT_HANDLER_PROPERTY(ApplicationCache, EventHandler *, onprogress);
    HTML5_EVENT_HANDLER_PROPERTY(ApplicationCache, EventHandler *, onupdateready);
    HTML5_PROPERTY(ApplicationCache, unsigned short, status);

    ApplicationCache(emscripten::val v);
    virtual ~ApplicationCache();
    static ApplicationCache *create(emscripten::val v);
    void abort();
    void swapCache();
    void update();
};
