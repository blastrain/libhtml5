#include "text_track_cue.h"
#include "text_track_cue_list.h"
#include "text_track.h"

USING_NAMESPACE_HTML5;

HTML5_BIND_CLASS(TextTrack);

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

void TextTrack::addCue(TextTrackCue *cue)
{
    HTML5_CALL(this->v, addCue, cue->v);
}

void TextTrack::removeCue(TextTrackCue *cue)
{
    HTML5_CALL(this->v, removeCue, cue->v);
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

HTML5_PROPERTY_OBJECT_IMPL(TextTrack, TextTrackCueList, activeCues);
HTML5_PROPERTY_OBJECT_IMPL(TextTrack, TextTrackCueList, cues);
HTML5_PROPERTY_IMPL(TextTrack, std::string, id);
HTML5_PROPERTY_IMPL(TextTrack, std::string, inBandMetadataTrackDispatchType);
HTML5_PROPERTY_IMPL(TextTrack, std::string, label);
HTML5_PROPERTY_IMPL(TextTrack, std::string, language);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(TextTrack, EventHandler *, oncuechange);
