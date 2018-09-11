#include "text_track_cue.h"
#include "text_track_cue_list.h"
#include "text_track.h"

TextTrack::TextTrack(emscripten::val v) :
    EventTarget(v)
{

}

TextTrack::~TextTrack()
{

}

TextTrack *TextTrack::create(emscripten::val v)
{
    TextTrack *track = new TextTrack(v);
    track->autorelease();
    return track;
}

emscripten::val TextTrack::getValue() const
{
    return this->v;
}

void TextTrack::addCue(TextTrackCue *cue)
{
    HTML5_CALL(this->v, addCue, cue->v);
}

void TextTrack::removeCue(TextTrackCue *cue)
{
    HTML5_CALL(this->v, removeCue, cue->v);
}

TextTrackCueList *TextTrack::getActiveCues() const
{
    return HTML5_PROPERTY_GET(activeCues, TextTrackCueList);
}

void TextTrack::setActiveCues(TextTrackCueList *value)
{
    this->_activeCues = value;
    this->v.set("activeCues", value->v);
}

TextTrackCueList *TextTrack::getCues() const
{
    return HTML5_PROPERTY_GET(cues, TextTrackCueList);
}

void TextTrack::setCues(TextTrackCueList *value)
{
    this->_cues = value;
    this->v.set("cues", value->v);
}

std::string TextTrack::getId() const
{
    return HTML5_PROPERTY_GET(id, std::string);
}

void TextTrack::setId(std::string value)
{
    this->_id = value;
    this->v.set("id", value);
}

std::string TextTrack::getInBandMetadataTrackDispatchType() const
{
    return HTML5_PROPERTY_GET(inBandMetadataTrackDispatchType, std::string);
}

void TextTrack::setInBandMetadataTrackDispatchType(std::string value)
{
    this->_inBandMetadataTrackDispatchType = value;
    this->v.set("inBandMetadataTrackDispatchType", value);
}

std::string TextTrack::getKind() const
{
#if ENABLE_EMSCRIPTEN
    return this->v["kind"].as<std::string>();
#else
    return "";
#endif
}

void TextTrack::setKind(TextTrackKind value)
{
    this->_kind = value;
    switch (value) {
    case TextTrackKind::SUBTITLES:
        this->v.set("kind", "subtitles");
        break;
    case TextTrackKind::CAPTIONS:
        this->v.set("kind", "captions");
        break;
    case TextTrackKind::DESCRIPTIONS:
        this->v.set("kind", "descriptions");
        break;
    case TextTrackKind::CHAPTERS:
        this->v.set("kind", "chapters");
        break;
    case TextTrackKind::METADATA:
        this->v.set("kind", "metadata");
        break;
    }
}

std::string TextTrack::getLabel() const
{
    return HTML5_PROPERTY_GET(label, std::string);
}

void TextTrack::setLabel(std::string value)
{
    this->_label = value;
    this->v.set("label", value);
}

std::string TextTrack::getLanguage() const
{
    return HTML5_PROPERTY_GET(language, std::string);
}

void TextTrack::setLanguage(std::string value)
{
    this->_language = value;
    this->v.set("language", value);
}

std::string TextTrack::getMode() const
{
#if ENABLE_EMSCRIPTEN
    return this->v["mode"].as<std::string>();
#else
    return "";
#endif
}

void TextTrack::setMode(TextTrackMode value)
{
    this->_mode = value;
    switch (value) {
    case TextTrackMode::DISABLED:
        this->v.set("mode", "disabled");
        break;
    case TextTrackMode::HIDDEN:
        this->v.set("mode", "hidden");
        break;
    case TextTrackMode::SHOWING:
        this->v.set("mode", "showing");
        break;
    }
}

EventHandler *TextTrack::getOnCueChange() const
{
    return this->_oncuechange;
}

void TextTrack::setOnCueChange(EventHandler *value)
{
    this->_oncuechange = value;
    EM_ASM_({
        const element = Module.toTextTrack($0);
        element._value.oncuechange = function(e) { element.onCueChangeCallback(e); };
    }, this);
}

void TextTrack::onCueChangeCallback(emscripten::val e)
{
    if (!this->_oncuechange) return;

    (*this->_oncuechange)(Event::create(e));
}
