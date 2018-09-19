#include "time_ranges.h"
#include "event_handler.h"
#include "media_controller.h"

USING_NAMESPACE_HTML5;

HTML5_BIND_CLASS(MediaController);

MediaController::MediaController(emscripten::val v) :
    EventTarget(v)
{

}

MediaController::~MediaController()
{

}

MediaController *MediaController::create(emscripten::val v)
{
    MediaController *mc = new MediaController(v);
    mc->autorelease();
    return mc;
}

void MediaController::pause()
{
    HTML5_CALL(this->v, pause);
}

void MediaController::play()
{
    HTML5_CALL(this->v, play);
}

void MediaController::unpause()
{
    HTML5_CALL(this->v, unpause);
}

std::string MediaController::getPlaybackState() const
{
#if ENABLE_EMSCRIPTEN
    return this->v["playbackState"].as<std::string>();
#else
    return "";
#endif
}

void MediaController::setPlaybackState(MediaControllerPlaybackState value)
{
    this->_playbackState = value;
    switch (value) {
    case MediaControllerPlaybackState::WAITING:
        this->v.set("playbackState", "waiting");
        break;
    case MediaControllerPlaybackState::PLAYING:
        this->v.set("playbackState", "playing");
        break;
    case MediaControllerPlaybackState::ENDED:
        this->v.set("playbackState", "ended");
        break;
    }
}

HTML5_PROPERTY_IMPL(MediaController, double, currentTime);
HTML5_PROPERTY_OBJECT_IMPL(MediaController, TimeRanges, buffered);
HTML5_PROPERTY_IMPL(MediaController, double, defaultPlaybackRate);
HTML5_PROPERTY_IMPL(MediaController, double, duration);
HTML5_PROPERTY_IMPL(MediaController, bool, muted);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(MediaController, EventHandler *, oncanplay);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(MediaController, EventHandler *, oncanplaythrough);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(MediaController, EventHandler *, ondurationchange);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(MediaController, EventHandler *, onemptied);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(MediaController, EventHandler *, onended);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(MediaController, EventHandler *, onloadeddata);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(MediaController, EventHandler *, onloadedmetadata);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(MediaController, EventHandler *, onpause);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(MediaController, EventHandler *, onplay);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(MediaController, EventHandler *, onplaying);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(MediaController, EventHandler *, onratechange);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(MediaController, EventHandler *, ontimeupdate);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(MediaController, EventHandler *, onvolumechange);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(MediaController, EventHandler *, onwaiting);
HTML5_PROPERTY_IMPL(MediaController, bool, paused);
HTML5_PROPERTY_IMPL(MediaController, double, playbackRate);
HTML5_PROPERTY_OBJECT_IMPL(MediaController, TimeRanges, played);
HTML5_PROPERTY_IMPL(MediaController, unsigned short, readyState);
HTML5_PROPERTY_OBJECT_IMPL(MediaController, TimeRanges, seekable);
HTML5_PROPERTY_IMPL(MediaController, double, volume);
