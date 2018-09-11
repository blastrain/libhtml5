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
    Document::create()->body()->appendChild(video);
    Event *event = Event::create("demo");
    video->dispatchEvent(event);
}

static void createImage()
{
    HTMLImageElement *image = HTMLImageElement::create();
    static EventHandler onload = [image](Event *e){
        std::cout << "callback. onload" << std::endl;
        std::cout << "width = " << image->width << std::endl;
        std::cout << "height = " << image->height << std::endl;
    };
    image->onload = &onload;
    image->src = "";
    Document::create()->body()->appendChild(image);
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
        .function("onAbortCallback", &HTMLElement::onAbortCallback)
        .function("onAutoCompleteCallback", &HTMLElement::onAutoCompleteCallback)
        .function("onAutoCompleteErrorCallback", &HTMLElement::onAutoCompleteErrorCallback)
        .function("onBlurCallback", &HTMLElement::onBlurCallback)
        .function("onCancelCallback", &HTMLElement::onCancelCallback)
        .function("onCanplayCallback", &HTMLElement::onCanplayCallback)
        .function("onCanplayThroughCallback", &HTMLElement::onCanplayThroughCallback)
        .function("onChangeCallback", &HTMLElement::onChangeCallback)
        .function("onClickCallback", &HTMLElement::onClickCallback)
        .function("onCloseCallback", &HTMLElement::onCloseCallback)
        .function("onContextMenuCallback", &HTMLElement::onContextMenuCallback)
        .function("onCueChangeCallback", &HTMLElement::onCueChangeCallback)
        .function("onDoubleClickCallback", &HTMLElement::onDoubleClickCallback)
        .function("onDragCallback", &HTMLElement::onDragCallback)
        .function("onDragEndCallback", &HTMLElement::onDragEndCallback)
        .function("onDragEnterCallback", &HTMLElement::onDragEnterCallback)
        .function("onDragExitCallback", &HTMLElement::onDragExitCallback)
        .function("onDragLeaveCallback", &HTMLElement::onDragLeaveCallback)
        .function("onDragOverCallback", &HTMLElement::onDragOverCallback)
        .function("onDragStartCallback", &HTMLElement::onDragStartCallback)
        .function("onDropCallback", &HTMLElement::onDropCallback)
        .function("onDurationChangeCallback", &HTMLElement::onDurationChangeCallback)
        .function("onEmptiedCallback", &HTMLElement::onEmptiedCallback)
        .function("onEndedCallback", &HTMLElement::onEndedCallback)
        .function("onErrorCallback", &HTMLElement::onErrorCallback)
        .function("onFocusCallback", &HTMLElement::onFocusCallback)
        .function("onInputCallback", &HTMLElement::onInputCallback)
        .function("onInvalidCallback", &HTMLElement::onInvalidCallback)
        .function("onKeyDownCallback", &HTMLElement::onKeyDownCallback)
        .function("onKeyPressCallback", &HTMLElement::onKeyPressCallback)
        .function("onKeyUpCallback", &HTMLElement::onKeyUpCallback)
        .function("onLoadCallback", &HTMLElement::onLoadCallback)
        .function("onLoadedDataCallback", &HTMLElement::onLoadedDataCallback)
        .function("onLoadedMetaDataCallback", &HTMLElement::onLoadedMetaDataCallback)
        .function("onLoadStartCallback", &HTMLElement::onLoadStartCallback)
        .function("onMouseDownCallback", &HTMLElement::onMouseDownCallback)
        .function("onMouseEnterCallback", &HTMLElement::onMouseEnterCallback)
        .function("onMouseLeaveCallback", &HTMLElement::onMouseLeaveCallback)
        .function("onMouseMoveCallback", &HTMLElement::onMouseMoveCallback)
        .function("onMouseOutCallback", &HTMLElement::onMouseOutCallback)
        .function("onMouseOverCallback", &HTMLElement::onMouseOverCallback)
        .function("onMouseUpCallback", &HTMLElement::onMouseUpCallback)
        .function("onMouseWheelCallback", &HTMLElement::onMouseWheelCallback)
        .function("onPauseCallback", &HTMLElement::onPauseCallback)
        .function("onPlayCallback", &HTMLElement::onPlayCallback)
        .function("onPlayingCallback", &HTMLElement::onPlayingCallback)
        .function("onProgressCallback", &HTMLElement::onProgressCallback)
        .function("onRateChangeCallback", &HTMLElement::onRateChangeCallback)
        .function("onResetCallback", &HTMLElement::onResetCallback)
        .function("onResizeCallback", &HTMLElement::onResizeCallback)
        .function("onScrollCallback", &HTMLElement::onScrollCallback)
        .function("onSeekedCallback", &HTMLElement::onSeekedCallback)
        .function("onSeekingCallback", &HTMLElement::onSeekingCallback)
        .function("onSelectCallback", &HTMLElement::onSelectCallback)
        .function("onShowCallback", &HTMLElement::onShowCallback)
        .function("onSortCallback", &HTMLElement::onSortCallback)
        .function("onStalledCallback", &HTMLElement::onStalledCallback)
        .function("onSubmitCallback", &HTMLElement::onSubmitCallback)
        .function("onSuspendCallback", &HTMLElement::onSuspendCallback)
        .function("onTimeUpdateCallback", &HTMLElement::onTimeUpdateCallback)
        .function("onToggleCallback", &HTMLElement::onToggleCallback)
        .function("onVolumeChangeCallback", &HTMLElement::onVolumeChangeCallback)
        .function("onWaitingCallback", &HTMLElement::onWaitingCallback);
    emscripten::function("createVideo", &createVideo);
    emscripten::function("createImage", &createImage);
    function("toEventTarget", &toEventTarget, emscripten::allow_raw_pointers());
    function("toHTMLElement", &toHTMLElement, emscripten::allow_raw_pointers());
    function("toString", &toString, emscripten::allow_raw_pointers());
}
