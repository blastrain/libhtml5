#pragma once

typedef std::function<void(Event*)> EventHandler;
typedef std::function<void(Event*, std::string, unsigned long, unsigned long, void*)> OnErrorEventHandler;
