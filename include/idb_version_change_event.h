#pragma once

#include "event.h"

class IDBVersionChangeEvent : public Event {
public:

    HTML5_PROPERTY(IDBVersionChangeEvent, unsigned long long, newVersion);
    HTML5_PROPERTY(IDBVersionChangeEvent, unsigned long long, oldVersion);

    IDBVersionChangeEvent(emscripten::val v);
    virtual ~IDBVersionChangeEvent();
    static IDBVersionChangeEvent *create(emscripten::val v);
};
