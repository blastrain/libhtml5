#pragma once

#include "object.h"
#include <string>
#include <time.h>
#include <emscripten/val.h>

class EventTarget;

class Event : public Object {
public:
    enum {
        NONE            = 0,
        CAPTURING_PHASE = 1,
        AT_TARGET       = 2,
        BUBBLING_PHASE  = 3,
    };
    emscripten::val v;
    bool _bubbles;
    bool _cancelable;
    EventTarget *_currentTarget;
    bool _defaultPrevented;
    unsigned short _eventPhase;
    bool _isTrusted;
    EventTarget *_target;
    std::string _type;
    time_t _timeStamp;

    Event(emscripten::val v);
    virtual ~Event();
    static Event *create(std::string type);
    static Event *create(emscripten::val v);
    void initEvent(std::string type, bool bubbles, bool cancelable);
    void preventDefault();
    void stopImmediatePropagation();
    void stopPropagation();
    struct {
        Event &self;
        void operator=(bool v) { self.setBubbles(v); };
        operator bool() { return self.getBubbles(); };
    } bubbles{*this};
    struct {
        Event &self;
        void operator=(bool v) { self.setCancelable(v); };
        operator bool() { return self.getCancelable(); };
    } cancelable{*this};
    struct {
        Event &self;
        void operator=(EventTarget *v) { self.setCurrentTarget(v); };
        operator EventTarget *() { return self.getCurrentTarget(); };
    } currentTarget{*this};
    struct {
        Event &self;
        void operator=(bool v) { self.setDefaultPrevented(v); };
        operator bool() { return self.getDefaultPrevented(); };
    } defaultPrevented{*this};
    struct {
        Event &self;
        void operator=(unsigned short v) { self.setEventPhase(v); };
        operator unsigned short() { return self.getEventPhase(); };
    } eventPhase{*this};
    struct {
        Event &self;
        void operator=(bool v) { self.setIsTrusted(v); };
        operator bool() { return self.getIsTrusted(); };
    } isTrusted{*this};
    struct {
        Event &self;
        void operator=(EventTarget *v) { self.setTarget(v); };
        operator EventTarget *() { return self.getTarget(); };
    } target{*this};
    struct {
        Event &self;
        void operator=(std::string v) { self.setType(v); };
        operator std::string() { return self.getType(); };
    } type{*this};
    struct {
        Event &self;
        void operator=(time_t v) { self.setTimeStamp(v); };
        operator time_t() { return self.getTimeStamp(); };
    } timeStamp{*this};

private:
    void setBubbles(bool value);
    bool getBubbles();
    void setCancelable(bool value);
    bool getCancelable();
    void setCurrentTarget(EventTarget *value);
    EventTarget *getCurrentTarget();
    void setDefaultPrevented(bool value);
    bool getDefaultPrevented();
    void setEventPhase(unsigned short value);
    unsigned short getEventPhase();
    void setIsTrusted(bool value);
    bool getIsTrusted();
    void setTarget(EventTarget *value);
    EventTarget *getTarget();
    void setType(std::string value);
    std::string getType();
    void setTimeStamp(time_t value);
    time_t getTimeStamp();
};
