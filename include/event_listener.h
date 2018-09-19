#pragma once

#include "event.h"

NAMESPACE_HTML5_BEGIN;

class EventListener {
public:
    virtual void handleEvent(Event *event) = 0;
};

NAMESPACE_HTML5_END;
