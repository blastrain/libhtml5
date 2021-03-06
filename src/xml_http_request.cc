#include "array_buffer_view.h"
#include "array_buffer.h"
#include "blob.h"
#include "document.h"
#include "xml_http_request.h"

USING_NAMESPACE_HTML5;

HTML5_BIND_CLASS(XMLHttpRequest);

XMLHttpRequestUpload::XMLHttpRequestUpload(emscripten::val v) :
    Object(v)
{

}

XMLHttpRequestUpload::~XMLHttpRequestUpload()
{

}

XMLHttpRequestUpload *XMLHttpRequestUpload::create(emscripten::val v)
{
    auto upload = new XMLHttpRequestUpload(v);
    upload->autorelease();
    return upload;
}

XMLHttpRequest::XMLHttpRequest(emscripten::val v) :
    EventTarget(v)
{

}

XMLHttpRequest::~XMLHttpRequest()
{

}

XMLHttpRequest *XMLHttpRequest::create(emscripten::val v)
{
    auto request = new XMLHttpRequest(v);
    request->autorelease();
    return request;
}

XMLHttpRequest *XMLHttpRequest::create()
{
    return create(HTML5_NEW_PRIMITIVE_INSTANCE(XMLHttpRequest));
}

void XMLHttpRequest::abort()
{
    HTML5_CALL(this->v, abort);
}

std::string XMLHttpRequest::getAllResponseHeaders()
{
    return HTML5_CALLs(this->v, getAllResponseHeaders);
}

void XMLHttpRequest::open(std::string method, std::string url)
{
    HTML5_CALL(this->v, open, method, url);
}

void XMLHttpRequest::open(std::string method, std::string url, bool async)
{
    HTML5_CALL(this->v, open, method, url, async);
}

void XMLHttpRequest::open(std::string method, std::string url, bool async, std::string user)
{
    HTML5_CALL(this->v, open, method, url, async, user);
}

void XMLHttpRequest::open(std::string method, std::string url, bool async, std::string user, std::string password)
{
    HTML5_CALL(this->v, open, method, url, async, user, password);
}

void XMLHttpRequest::overrideMimeType(std::string mimeType)
{
    HTML5_CALL(this->v, overrideMimeType, mimeType);
}

void XMLHttpRequest::send()
{
    HTML5_CALL(this->v, send);
}

void XMLHttpRequest::send(Document *body)
{
    HTML5_CALL(this->v, send, body->v);
}

void XMLHttpRequest::send(Blob *body)
{
    HTML5_CALL(this->v, send, body->v);
}

void XMLHttpRequest::send(std::string body)
{
    HTML5_CALL(this->v, send, body);
}

void XMLHttpRequest::send(ArrayBufferView *body)
{
    HTML5_CALL(this->v, send, body->v);
}

void XMLHttpRequest::setRequestHeader(std::string header, std::string value)
{
    HTML5_CALL(this->v, setRequestHeader, header, value);
}

std::string XMLHttpRequest::getResponseType() const
{
#if ENABLE_EMSCRIPTEN
    return this->v["responseType"].as<std::string>();
#else
    return "";
#endif
}

void XMLHttpRequest::setResponseType(XMLHttpResponseType value)
{
    this->_responseType = value;
    this->v.set("responseType", toXMLHttpResponseTypeString(value));
}

ArrayBuffer *XMLHttpRequest::responseArrayBuffer() const
{
    return ArrayBuffer::create(this->v["response"].as<emscripten::val>());
}

Blob *XMLHttpRequest::responseBlob() const
{
    return Blob::create(this->v["response"].as<emscripten::val>());
}

std::string XMLHttpRequest::responseString() const
{
    return this->v["response"].as<std::string>();
}

HTML5_EVENT_HANDLER_PROPERTY_IMPL(XMLHttpRequest, EventHandler *, onabort);
HTML5_ERROR_HANDLER_PROPERTY_IMPL(XMLHttpRequest, OnErrorEventHandler *, onerror);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(XMLHttpRequest, EventHandler *, onload);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(XMLHttpRequest, EventHandler *, onloadend);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(XMLHttpRequest, EventHandler *, onloadstart);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(XMLHttpRequest, EventHandler *, onprogress);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(XMLHttpRequest, EventHandler *, onreadystatechange);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(XMLHttpRequest, EventHandler *, ontimeout);
HTML5_PROPERTY_IMPL(XMLHttpRequest, unsigned short, readyState);
HTML5_PROPERTY_IMPL(XMLHttpRequest, std::string, responseText);
HTML5_PROPERTY_IMPL(XMLHttpRequest, std::string, responseURL);
HTML5_PROPERTY_OBJECT_IMPL(XMLHttpRequest, Document, responseXML);
HTML5_PROPERTY_IMPL(XMLHttpRequest, unsigned short, status);
HTML5_PROPERTY_IMPL(XMLHttpRequest, std::string, statusText);
HTML5_PROPERTY_IMPL(XMLHttpRequest, unsigned long, timeout);
HTML5_READONLY_PROPERTY_OBJECT_IMPL(XMLHttpRequest, XMLHttpRequestUpload, upload);
HTML5_PROPERTY_IMPL(XMLHttpRequest, bool, withCredentials);
