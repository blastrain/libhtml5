#pragma once

#include "event_target.h"
#include <assert.h>

NAMESPACE_HTML5_BEGIN;

class Document;
class Blob;
class ArrayBufferView;

enum class XMLHttpResponseType {
    NONE,
    ARRAY_BUFFER,
    BLOB,
    DOCUMENT,
    JSON,
    TEXT,
};

inline std::string toXMLHttpResponseTypeString(XMLHttpResponseType type)
{
    switch (type) {
    case XMLHttpResponseType::NONE:
        return "text";
        break;
    case XMLHttpResponseType::ARRAY_BUFFER:
        return "arraybuffer";
        break;
    case XMLHttpResponseType::BLOB:
        return "blob";
        break;
    case XMLHttpResponseType::DOCUMENT:
        return "document";
        break;
    case XMLHttpResponseType::JSON:
        return "json";
        break;
    case XMLHttpResponseType::TEXT:
        return "text";
        break;
    }
    return "";
}

inline XMLHttpResponseType toXMLHttpResponseType(std::string type)
{
    if (type == "text") {
        return XMLHttpResponseType::TEXT;
    } else if (type == "arraybuffer") {
        return XMLHttpResponseType::ARRAY_BUFFER;
    } else if (type == "blob") {
        return XMLHttpResponseType::BLOB;
    } else if (type == "document") {
        return XMLHttpResponseType::DOCUMENT;
    } else if (type == "json") {
        return XMLHttpResponseType::JSON;
    }
    assert(false && "cannot convert to XMLHttpResponseType");
    return XMLHttpResponseType::NONE;
}


class XMLHttpResponse : public Object {
public:

    XMLHttpResponse(emscripten::val v);
    virtual ~XMLHttpResponse();
    static XMLHttpResponse *create(emscripten::val v);
};

class XMLHttpRequestUpload : public Object {
public:

    XMLHttpRequestUpload(emscripten::val v);
    virtual ~XMLHttpRequestUpload();
    static XMLHttpRequestUpload *create(emscripten::val v);
};

class XMLHttpRequest : public EventTarget {
public:
    enum {
        UNSENT = 0,
        OPENED = 1,
        HEADERS_RECEIVED = 2,
        LOADING = 3,
        DONE    = 4,
    };

    HTML5_EVENT_HANDLER_PROPERTY(XMLHttpRequest, EventHandler *, onabort);
    HTML5_ERROR_HANDLER_PROPERTY(XMLHttpRequest, OnErrorEventHandler *, onerror);
    HTML5_EVENT_HANDLER_PROPERTY(XMLHttpRequest, EventHandler *, onload);
    HTML5_EVENT_HANDLER_PROPERTY(XMLHttpRequest, EventHandler *, onloadend);
    HTML5_EVENT_HANDLER_PROPERTY(XMLHttpRequest, EventHandler *, onloadstart);
    HTML5_EVENT_HANDLER_PROPERTY(XMLHttpRequest, EventHandler *, onprogress);
    HTML5_EVENT_HANDLER_PROPERTY(XMLHttpRequest, EventHandler *, onreadystatechange);
    HTML5_EVENT_HANDLER_PROPERTY(XMLHttpRequest, EventHandler *, ontimeout);
    HTML5_PROPERTY(XMLHttpRequest, unsigned short, readyState);
    HTML5_PROPERTY(XMLHttpRequest, XMLHttpResponse *, response);
    HTML5_PROPERTY(XMLHttpRequest, std::string, responseText);
    HTML5_PROPERTY(XMLHttpRequest, std::string, responseURL);
    HTML5_PROPERTY(XMLHttpRequest, Document *, responseXML);
    HTML5_PROPERTY(XMLHttpRequest, unsigned short, status);
    HTML5_PROPERTY(XMLHttpRequest, std::string, statusText);
    HTML5_PROPERTY(XMLHttpRequest, unsigned long, timeout);
    HTML5_READONLY_PROPERTY(XMLHttpRequest, XMLHttpRequestUpload *, upload);
    HTML5_PROPERTY(XMLHttpRequest, bool, withCredentials);
    XMLHttpResponseType _responseType;
    
    XMLHttpRequest(emscripten::val v);
    virtual ~XMLHttpRequest();
    static XMLHttpRequest *create(emscripten::val v);
    void abort();
    std::string getAllResponseHeaders();
    void open(std::string method, std::string url);
    void open(std::string method, std::string url, bool async);
    void open(std::string method, std::string url, bool async, std::string user);
    void open(std::string method, std::string url, bool async, std::string user, std::string password);
    void overrideMimeType(std::string mimeType);
    void send(Document *body);
    void send(Blob *body);
    void send(std::string body);
    void send(ArrayBufferView *body);
    void setRequestHeader(std::string header, std::string value);
    
    struct {
        XMLHttpRequest &self;
        void operator=(XMLHttpResponseType value) { self.setResponseType(value); };
        operator std::string() { return self.getResponseType(); };
    } responseType{*this};

    std::string getResponseType() const;
    void setResponseType(XMLHttpResponseType value);
};

NAMESPACE_HTML5_END;
