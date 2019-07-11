#include "response.h"
#include "promise.h"

USING_NAMESPACE_HTML5;

Response::Response(emscripten::val v) :
    Object(v)
{
}

Response::~Response()
{
}

Response *Response::create(emscripten::val v)
{
    auto response = new Response(v);
    response->autorelease();
    return response;
}

Response *Response::clone()
{
    return Response::create(HTML5_CALLv(this->v, clone));
}

Response *Response::error()
{
    return Response::create(HTML5_CALLv(this->v, error));
}

Response *Response::redirect(const std::string &url, int status)
{
    return Response::create(HTML5_CALLv(this->v, redirect, url, status));
}

Promise *Response::arrayBuffer()
{
    return Promise::create(HTML5_CALLv(this->v, arrayBuffer));
}

Promise *Response::blob()
{
    return Promise::create(HTML5_CALLv(this->v, blob));
}

Promise *Response::formData()
{
    return Promise::create(HTML5_CALLv(this->v, formData));
}

Promise *Response::json()
{
    return Promise::create(HTML5_CALLv(this->v, json));
}

Promise *Response::text()
{
    return Promise::create(HTML5_CALLv(this->v, text));
}

//HTML5_READONLY_PROPERTY_OBJECT_IMPL(Response, Headers, headers);
HTML5_READONLY_PROPERTY_IMPL(Response, bool, ok);
HTML5_READONLY_PROPERTY_IMPL(Response, bool, redirected);
HTML5_READONLY_PROPERTY_IMPL(Response, int, status);
HTML5_READONLY_PROPERTY_IMPL(Response, std::string, type);
HTML5_READONLY_PROPERTY_IMPL(Response, std::string, url);
HTML5_PROPERTY_IMPL(Response, bool, useFinalURL);
//HTML5_READONLY_PROPERTY_OBJECT_IMPL(Response, ReadableStream, body);
HTML5_READONLY_PROPERTY_IMPL(Response, bool, bodyUsed);