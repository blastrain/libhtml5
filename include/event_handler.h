#pragma once

#include "event.h"
#include <functional>
#include <string>

typedef std::function<void(Event*)> EventHandler;
typedef std::function<void(Event*, std::string, unsigned long, unsigned long, void*)> OnErrorEventHandler;
