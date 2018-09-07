#pragma once

#include <functional>
#include <string>
#include <emscripten/val.h>
#include <map>
#include <vector>

class Event;

class EventTarget {
public:
    emscripten::val v;

    EventTarget(emscripten::val v);
    virtual ~EventTarget();
    static EventTarget *create(emscripten::val v);
    void addEventListener(std::string type, std::function<void(Event*)> *callback, bool capture = false);
    bool dispatchEvent(Event *event);
    void removeEventListener(std::string type, std::function<void(Event*)> *callback, bool capture = false);
    void addEventListenerCallback(emscripten::val v);
    emscripten::val getValue() const { return this->v; };

private:
    std::map<std::string, std::vector<std::function<void(Event*)> *>> listeners;
};
