#pragma once

#include "libhtml5.h"

NAMESPACE_HTML5_BEGIN;

class MimeTypeArray;
class PluginArray;

class Navigator : public Object {
public:
    emscripten::val v;

    HTML5_PROPERTY(Navigator, std::string, appCodeName);
    HTML5_PROPERTY(Navigator, std::string, appName);
    HTML5_PROPERTY(Navigator, std::string, appVersion);
    HTML5_PROPERTY(Navigator, bool, cookieEnabled);
    HTML5_PROPERTY(Navigator, bool, javaEnabled);
    HTML5_PROPERTY(Navigator, std::string, language);
    HTML5_PROPERTY(Navigator, MimeTypeArray *, mimeTypes);
    HTML5_PROPERTY(Navigator, bool, onLine);
    HTML5_PROPERTY(Navigator, std::string, platform);
    HTML5_PROPERTY(Navigator, PluginArray *, plugins);
    HTML5_PROPERTY(Navigator, std::string, product);
    HTML5_PROPERTY(Navigator, std::string, userAgent);
    
    Navigator(emscripten::val v);
    virtual ~Navigator();
    static Navigator *create(emscripten::val v);
    std::string isContentHandlerRegistered(std::string mimeType, std::string url);
    std::string isProtocolHandlerRegistered(std::string scheme, std::string url);
    void registerContentHandler(std::string mimeType, std::string url, std::string title);
    void registerProtocolHandler(std::string scheme, std::string url, std::string title);
    bool taintEnabled();
    void unregisterContentHandler(std::string mimeType, std::string url);
    void unregisterProtocolHandler(std::string scheme, std::string url);
    void yieldForStorageUpdates();
};

NAMESPACE_HTML5_END;
