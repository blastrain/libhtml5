#include "mime_type_array.h"
#include "plugin_array.h"
#include "navigator.h"

USING_NAMESPACE_HTML5;

Navigator::Navigator(emscripten::val v) :
    Object(v)
{

}

Navigator::~Navigator()
{

}

Navigator *Navigator::create(emscripten::val v)
{
    auto navigator = new Navigator(v);
    navigator->autorelease();
    return navigator;
}

std::string Navigator::isContentHandlerRegistered(std::string mimeType, std::string url)
{
    return HTML5_CALLs(this->v, isContentHandlerRegistered, mimeType, url);
}

std::string Navigator::isProtocolHandlerRegistered(std::string scheme, std::string url)
{
    return HTML5_CALLs(this->v, isProtocolHandlerRegistered, scheme, url);
}

void Navigator::registerContentHandler(std::string mimeType, std::string url, std::string title)
{
    HTML5_CALL(this->v, registerContentHandler, mimeType, url, title);
}

void Navigator::registerProtocolHandler(std::string scheme, std::string url, std::string title)
{
    HTML5_CALL(this->v, registerProtocolHandler, scheme, url, title);
}

bool Navigator::taintEnabled()
{
    return HTML5_CALLb(this->v, taintEnabled);
}

void Navigator::unregisterContentHandler(std::string mimeType, std::string url)
{
    HTML5_CALL(this->v, unregisterContentHandler, mimeType, url);
}

void Navigator::unregisterProtocolHandler(std::string scheme, std::string url)
{
    HTML5_CALL(this->v, unregisterProtocolHandler, scheme, url);
}

void Navigator::yieldForStorageUpdates()
{
    HTML5_CALL(this->v, yieldForStorageUpdates);
}

HTML5_PROPERTY_IMPL(Navigator, std::string, appCodeName);
HTML5_PROPERTY_IMPL(Navigator, std::string, appName);
HTML5_PROPERTY_IMPL(Navigator, std::string, appVersion);
HTML5_PROPERTY_IMPL(Navigator, bool, cookieEnabled);
HTML5_PROPERTY_IMPL(Navigator, bool, javaEnabled);
HTML5_PROPERTY_IMPL(Navigator, std::string, language);
HTML5_PROPERTY_OBJECT_IMPL(Navigator, MimeTypeArray, mimeTypes);
HTML5_PROPERTY_IMPL(Navigator, bool, onLine);
HTML5_PROPERTY_IMPL(Navigator, std::string, platform);
HTML5_PROPERTY_OBJECT_IMPL(Navigator, PluginArray, plugins);
HTML5_PROPERTY_IMPL(Navigator, std::string, product);
HTML5_PROPERTY_IMPL(Navigator, std::string, userAgent);
