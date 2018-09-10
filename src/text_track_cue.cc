#include "text_track.h"
#include "text_track_cue.h"
#include <emscripten/emscripten.h>

TextTrackCue::TextTrackCue(emscripten::val v) :
    EventTarget(v)
{

}

TextTrackCue::~TextTrackCue()
{

}

TextTrackCue *TextTrackCue::create(emscripten::val v)
{
    return new TextTrackCue(v);
}

emscripten::val TextTrackCue::getValue() const
{
    return this->v;
}

double TextTrackCue::getEndTime() const
{
    return this->v["endTime"].as<double>();
}

void TextTrackCue::setEndTime(double value)
{
    this->_endTime = value;
    this->v.set("endTime", value);
}

std::string TextTrackCue::getId() const
{
    return this->v["id"].as<std::string>();
}

void TextTrackCue::setId(std::string value)
{
    this->_id = value;
    this->v.set("id", value);
}

EventHandler *TextTrackCue::getOnEnter() const
{
    return this->_onenter;
}

void TextTrackCue::setOnEnter(EventHandler *value)
{
    this->_onenter = value;
    EM_ASM_({
        const element = Module.toTextTrackCue($0);
        element._value.onenter = function(e) { element.onEnterCallback(e); };
    }, this);
}

void TextTrackCue::onEnterCallback(emscripten::val e)
{
    if (!this->_onenter) return;

    (*this->_onenter)(Event::create(e));
}

EventHandler *TextTrackCue::getOnExit() const
{
    return this->_onexit;
}

void TextTrackCue::setOnExit(EventHandler *value)
{
    this->_onexit = value;
    EM_ASM_({
        const element = Module.toTextTrackCue($0);
        element._value.onexit = function(e) { element.onExitCallback(e); };
    }, this);
}

void TextTrackCue::onExitCallback(emscripten::val e)
{
    if (!this->_onexit) return;

    (*this->_onexit)(Event::create(e));
}

bool TextTrackCue::getPauseOnExit() const
{
    return this->v["pauseOnExit"].as<bool>();
}

void TextTrackCue::setPauseOnExit(bool value)
{
    this->_pauseOnExit = value;
    this->v.set("pauseOnExit", value);
}

double TextTrackCue::getStartTime() const
{
    return this->v["startTime"].as<double>();
}

void TextTrackCue::setStartTime(double value)
{
    this->_startTime = value;
    this->v.set("startTime", value);
}

TextTrack *TextTrackCue::getTrack() const
{
    return TextTrack::create(this->v["track"]);
}

void TextTrackCue::setTrack(TextTrack *value)
{
    this->_track = value;
    this->v.set("track", value->v);
}

