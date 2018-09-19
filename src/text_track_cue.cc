#include "text_track.h"
#include "text_track_cue.h"

USING_NAMESPACE_HTML5;

HTML5_BIND_CLASS(TextTrackCue);

TextTrackCue::TextTrackCue(emscripten::val v) :
    EventTarget(v)
{

}

TextTrackCue::~TextTrackCue()
{

}

TextTrackCue *TextTrackCue::create(emscripten::val v)
{
    TextTrackCue *trackCue = new TextTrackCue(v);
    trackCue->autorelease();
    return trackCue;
}

HTML5_PROPERTY_IMPL(TextTrackCue, double, endTime);
HTML5_PROPERTY_IMPL(TextTrackCue, std::string, id);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(TextTrackCue, EventHandler *, onenter);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(TextTrackCue, EventHandler *, onexit);
HTML5_PROPERTY_IMPL(TextTrackCue, bool, pauseOnExit);
HTML5_PROPERTY_IMPL(TextTrackCue, double, startTime);
HTML5_PROPERTY_OBJECT_IMPL(TextTrackCue, TextTrack, track);
