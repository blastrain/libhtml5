#pragma once

#include "event.h"
#include <functional>
#include <string>
#include <memory>

NAMESPACE_HTML5_BEGIN;

typedef std::function<void(std::unique_ptr<Event>)> EventHandler;
typedef std::function<void(std::unique_ptr<Event>, std::string, unsigned long, unsigned long, void*)> OnErrorEventHandler;

NAMESPACE_HTML5_END;
