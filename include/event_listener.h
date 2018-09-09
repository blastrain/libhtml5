#pragma once

#include "event.h"

class EventListener {
public:
    virtual void handleEvent(Event *event) = 0;
};
