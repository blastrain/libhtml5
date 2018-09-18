#include <emscripten/bind.h>

#include "document.h"
#include "html_video_element.h"
#include "html_source_element.h"
#include "html_image_element.h"
#include "audio_track_list.h"
#include "text_track.h"
#include "text_track_list.h"
#include "text_track_cue.h"
#include "video_track_list.h"
#include "media_controller.h"
#include "event.h"
#include "event_target.h"
#include "window.h"
#include <iostream>
#include <emscripten/emscripten.h>

static void createVideo()
{
    HTMLVideoElement *video = HTMLVideoElement::create();
    HTMLSourceElement *source = HTMLSourceElement::create();
    source->src = "http://clips.vorwaerts-gmbh.de/VfE_html5.mp4";
    video->appendChild(source);
    static EventHandler f = [](Event *e){
        std::cout << "demo event fired!!!" << std::endl;
        std::cout << (std::string)e->type << std::endl;
        std::cout << e->bubbles << std::endl;
        std::cout << e->timeStamp << std::endl;
    };
    video->addEventListener("demo", &f);
    Document::create()->body->appendChild(video);
    Event *event = Event::create("demo");
    video->dispatchEvent(event);
}

static void createImage(std::string url)
{
    HTMLImageElement *image = HTMLImageElement::create();
    static EventHandler onload = [image](Event *e){
        std::cout << "callback. onload" << std::endl;
        std::cout << "width = " << image->width << std::endl;
        std::cout << "height = " << image->height << std::endl;
        std::cout << "naturalWidth = " << image->naturalWidth << std::endl;
        std::cout << "naturalHeight = " << image->naturalHeight << std::endl;
    };
    image->onload = &onload;
    image->src = url;
    Document::create()->body->appendChild(image);
}

static emscripten::val toString(intptr_t ptr)
{
    return emscripten::val(std::string((char *)ptr));
}

static EventTarget *toEventTarget(intptr_t ptr)
{
    return (EventTarget *)ptr;
}

static HTMLElement *toHTMLElement(intptr_t ptr)
{
    return (HTMLElement *)ptr;
}

static MediaController *toMediaController(intptr_t ptr)
{
    return (MediaController *)ptr;
}

static AudioTrackList *toAudioTrackList(intptr_t ptr)
{
    return (AudioTrackList *)ptr;
}

static TextTrackList *toTextTrackList(intptr_t ptr)
{
    return (TextTrackList *)ptr;
}

static VideoTrackList *toVideoTrackList(intptr_t ptr)
{
    return (VideoTrackList *)ptr;
}

static TextTrack *toTextTrack(intptr_t ptr)
{
    return (TextTrack *)ptr;
}

static TextTrackCue *toTextTrackCue(intptr_t ptr)
{
    return (TextTrackCue *)ptr;
}

static Window *toWindow(intptr_t ptr)
{
    return (Window *)ptr;
}

EMSCRIPTEN_BINDINGS(createVideo) {
    emscripten::class_<EventTarget>("EventTarget")
        .property("_value", &EventTarget::getValue)
        .function("addEventHandlerCallback", &EventTarget::addEventHandlerCallback)
        .function("addEventListenerCallback", &EventTarget::addEventListenerCallback);
    emscripten::class_<AudioTrackList>("AudioTrackList")
        .property("_value", &AudioTrackList::getValue)
        .function("onAddTrackCallback", &AudioTrackList::onAddTrackCallback)
        .function("onChangeCallback", &AudioTrackList::onChangeCallback)
        .function("onRemoveTrackCallback", &AudioTrackList::onRemoveTrackCallback);
    emscripten::class_<TextTrackList>("TextTrackList")
        .property("_value", &TextTrackList::getValue)
        .function("onAddTrackCallback", &TextTrackList::onAddTrackCallback)
        .function("onChangeCallback", &TextTrackList::onChangeCallback)
        .function("onRemoveTrackCallback", &TextTrackList::onRemoveTrackCallback);
    emscripten::class_<VideoTrackList>("VideoTrackList")
        .property("_value", &VideoTrackList::getValue)
        .function("onAddTrackCallback", &VideoTrackList::onAddTrackCallback)
        .function("onChangeCallback", &VideoTrackList::onChangeCallback)
        .function("onRemoveTrackCallback", &VideoTrackList::onRemoveTrackCallback);
    emscripten::class_<TextTrack>("TextTrack")
        .property("_value", &TextTrack::getValue)
        .function("onCueChangeCallback", &TextTrack::onCueChangeCallback);
    emscripten::class_<TextTrackCue>("TextTrackCue")
        .property("_value", &TextTrackCue::getValue)
        .function("onEnterCallback", &TextTrackCue::onEnterCallback)
        .function("onExitCallback", &TextTrackCue::onExitCallback);
    emscripten::class_<MediaController>("MediaController")
        .property("_value", &MediaController::getValue)
        .function("onCanplayCallback", &MediaController::onCanplayCallback)
        .function("onCanplayThroughCallback", &MediaController::onCanplayThroughCallback)
        .function("onDurationChangeCallback", &MediaController::onDurationChangeCallback)
        .function("onEmptiedCallback", &MediaController::onEmptiedCallback)
        .function("onEndedCallback", &MediaController::onEndedCallback)
        .function("onLoadedDataCallback", &MediaController::onLoadedDataCallback)
        .function("onLoadedMetaDataCallback", &MediaController::onLoadedMetaDataCallback)
        .function("onPauseCallback", &MediaController::onPauseCallback)
        .function("onPlayCallback", &MediaController::onPlayCallback)
        .function("onPlayingCallback", &MediaController::onPlayingCallback)
        .function("onRateChangeCallback", &MediaController::onRateChangeCallback)
        .function("onTimeUpdateCallback", &MediaController::onTimeUpdateCallback)
        .function("onVolumeChangeCallback", &MediaController::onVolumeChangeCallback)
        .function("onWaitingCallback", &MediaController::onWaitingCallback);
    emscripten::class_<HTMLElement>("HTMLElement")
        .property("_value", &HTMLElement::getValue)
        .function("callback_onabort", &HTMLElement::callback_onabort)
        .function("callback_onautocomplete", &HTMLElement::callback_onautocomplete)
        .function("callback_onautocompleteerror", &HTMLElement::callback_onautocompleteerror)
        .function("callback_onblur", &HTMLElement::callback_onblur)
        .function("callback_oncancel", &HTMLElement::callback_oncancel)
        .function("callback_oncanplay", &HTMLElement::callback_oncanplay)
        .function("callback_oncanplaythrough", &HTMLElement::callback_oncanplaythrough)
        .function("callback_onchange", &HTMLElement::callback_onchange)
        .function("callback_onclick", &HTMLElement::callback_onclick)
        .function("callback_onclose", &HTMLElement::callback_onclose)
        .function("callback_oncontextmenu", &HTMLElement::callback_oncontextmenu)
        .function("callback_oncuechange", &HTMLElement::callback_oncuechange)
        .function("callback_ondblclick", &HTMLElement::callback_ondblclick)
        .function("callback_ondrag", &HTMLElement::callback_ondrag)
        .function("callback_ondragend", &HTMLElement::callback_ondragend)
        .function("callback_ondragenter", &HTMLElement::callback_ondragenter)
        .function("callback_ondrageExit", &HTMLElement::callback_ondragexit)
        .function("callback_ondragleave", &HTMLElement::callback_ondragleave)
        .function("callback_ondragover", &HTMLElement::callback_ondragover)
        .function("callback_ondragstart", &HTMLElement::callback_ondragstart)
        .function("callback_ondrop", &HTMLElement::callback_ondrop)
        .function("callback_ondurationchange", &HTMLElement::callback_ondurationchange)
        .function("callback_onemptied", &HTMLElement::callback_onemptied)
        .function("callback_onended", &HTMLElement::callback_onended)
        .function("callback_onerror", &HTMLElement::callback_onerror)
        .function("callback_onfocus", &HTMLElement::callback_onfocus)
        .function("callback_oninput", &HTMLElement::callback_oninput)
        .function("callback_oninvalid", &HTMLElement::callback_oninvalid)
        .function("callback_onkeydown", &HTMLElement::callback_onkeydown)
        .function("callback_onkeypress", &HTMLElement::callback_onkeypress)
        .function("callback_onkeyup", &HTMLElement::callback_onkeyup)
        .function("callback_onload", &HTMLElement::callback_onload)
        .function("callback_onloadeddata", &HTMLElement::callback_onloadeddata)
        .function("callback_onloadedmetadata", &HTMLElement::callback_onloadedmetadata)
        .function("callback_onloadstart", &HTMLElement::callback_onloadstart)
        .function("callback_onmousedown", &HTMLElement::callback_onmousedown)
        .function("callback_onmouseenter", &HTMLElement::callback_onmouseenter)
        .function("callback_onmouseleave", &HTMLElement::callback_onmouseleave)
        .function("callback_onmousemove", &HTMLElement::callback_onmousemove)
        .function("callback_onmouseout", &HTMLElement::callback_onmouseout)
        .function("callback_onmouseover", &HTMLElement::callback_onmouseover)
        .function("callback_onmouseup", &HTMLElement::callback_onmouseup)
        .function("callback_onmousewheel", &HTMLElement::callback_onmousewheel)
        .function("callback_onpause", &HTMLElement::callback_onpause)
        .function("callback_onplay", &HTMLElement::callback_onplay)
        .function("callback_onplaying", &HTMLElement::callback_onplaying)
        .function("callback_onprogress", &HTMLElement::callback_onprogress)
        .function("callback_onratechange", &HTMLElement::callback_onratechange)
        .function("callback_onreset", &HTMLElement::callback_onreset)
        .function("callback_onresize", &HTMLElement::callback_onresize)
        .function("callback_onscroll", &HTMLElement::callback_onscroll)
        .function("callback_onseeked", &HTMLElement::callback_onseeked)
        .function("callback_onseeking", &HTMLElement::callback_onseeking)
        .function("callback_onselect", &HTMLElement::callback_onselect)
        .function("callback_onshow", &HTMLElement::callback_onshow)
        .function("callback_onsort", &HTMLElement::callback_onsort)
        .function("callback_onstalled", &HTMLElement::callback_onstalled)
        .function("callback_onsubmit", &HTMLElement::callback_onsubmit)
        .function("callback_onsuspend", &HTMLElement::callback_onsuspend)
        .function("callback_ontimeupdate", &HTMLElement::callback_ontimeupdate)
        .function("callback_ontoggle", &HTMLElement::callback_ontoggle)
        .function("callback_onvolumechange", &HTMLElement::callback_onvolumechange)
        .function("callback_onwaiting", &HTMLElement::callback_onwaiting);
    emscripten::class_<Window>("Window")
        .function("requestAnimationFrameCallback", &Window::requestAnimationFrameCallback)
        .function("setIntervalCallback", &Window::setIntervalCallback)
        .function("setTimeoutCallback", &Window::setTimeoutCallback);
    emscripten::function("createVideo", &createVideo);
    emscripten::function("createImage", &createImage);
    function("toEventTarget", &toEventTarget, emscripten::allow_raw_pointers());
    function("toHTMLElement", &toHTMLElement, emscripten::allow_raw_pointers());
    function("toWindow", &toWindow, emscripten::allow_raw_pointers());
    function("toString", &toString, emscripten::allow_raw_pointers());
}
