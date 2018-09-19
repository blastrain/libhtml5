#pragma once

#include "event.h"

NAMESPACE_HTML5_BEGIN;

class IDBVersionChangeEvent : public Event {
public:

    HTML5_PROPERTY(IDBVersionChangeEvent, unsigned long long, newVersion);
    HTML5_PROPERTY(IDBVersionChangeEvent, unsigned long long, oldVersion);

    IDBVersionChangeEvent(emscripten::val v);
    virtual ~IDBVersionChangeEvent();
    static IDBVersionChangeEvent *create(emscripten::val v);
};

NAMESPACE_HTML5_END;
