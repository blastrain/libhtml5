#include "audio_track.h"
#include "audio_track_list.h"
#include "event.h"
#include "event_handler.h"

HTML5_BIND_CLASS(AudioTrackList);

AudioTrackList::AudioTrackList(emscripten::val v) :
    EventTarget(v)
{

}

AudioTrackList::~AudioTrackList()
{

}

AudioTrackList *AudioTrackList::create(emscripten::val v)
{
    AudioTrackList *trackList = new AudioTrackList(v);
    trackList->autorelease();
    return trackList;
}

AudioTrack *AudioTrackList::getter(unsigned long index)
{
    return AudioTrack::create(HTML5_CALLv(this->v, getter, index));
}

AudioTrack *AudioTrackList::getTrackById(std::string id)
{
    return AudioTrack::create(HTML5_CALLv(this->v, getTrackById, id));
}

HTML5_PROPERTY_IMPL(AudioTrackList, unsigned long, length);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(AudioTrackList, EventHandler *, onaddtrack);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(AudioTrackList, EventHandler *, onchange);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(AudioTrackList, EventHandler *, onremovetrack);
