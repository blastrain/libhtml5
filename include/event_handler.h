#pragma once

#include "event.h"
#include <functional>
#include <string>

NAMESPACE_HTML5_BEGIN;

typedef std::function<void(Event*)> EventHandler;
typedef std::function<void(Event*, std::string, unsigned long, unsigned long, void*)> OnErrorEventHandler;

NAMESPACE_HTML5_END;
