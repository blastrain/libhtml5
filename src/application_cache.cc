#include "application_cache.h"

USING_NAMESPACE_HTML5;

HTML5_BIND_CLASS(ApplicationCache);

ApplicationCache::ApplicationCache(emscripten::val v) :
    EventTarget(v)
{

}

ApplicationCache::~ApplicationCache()
{

}

std::unique_ptr<ApplicationCache> ApplicationCache::create(emscripten::val v)
{
    return std::unique_ptr<ApplicationCache>(new ApplicationCache(v));
}

void ApplicationCache::abort()
{
    HTML5_CALL(this->v, abort);
}

void ApplicationCache::swapCache()
{
    HTML5_CALL(this->v, swapCache);
}

void ApplicationCache::update()
{
    HTML5_CALL(this->v, update);
}

HTML5_EVENT_HANDLER_PROPERTY_IMPL(ApplicationCache, EventHandler, oncached);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(ApplicationCache, EventHandler, onchecking);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(ApplicationCache, EventHandler, ondownloading);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(ApplicationCache, EventHandler, onerror);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(ApplicationCache, EventHandler, onnoupdate);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(ApplicationCache, EventHandler, onobsolete);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(ApplicationCache, EventHandler, onprogress);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(ApplicationCache, EventHandler, onupdateready);
HTML5_PROPERTY_IMPL(ApplicationCache, unsigned short, status);
