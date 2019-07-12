#pragma once

#include "html5.h"

NAMESPACE_HTML5_BEGIN;

class Headers;
class ReadableStream;

class Response : public Object {
public:

    HTML5_READONLY_PROPERTY_OBJECT(Response, Headers, headers);
    HTML5_READONLY_PROPERTY(Response, bool, ok);
    HTML5_READONLY_PROPERTY(Response, bool, redirected);
    HTML5_READONLY_PROPERTY(Response, int, status);
    HTML5_READONLY_PROPERTY(Response, std::string, type);
    HTML5_READONLY_PROPERTY(Response, std::string, url);
    HTML5_PROPERTY(Response, bool, useFinalURL);
    HTML5_READONLY_PROPERTY_OBJECT(Response, ReadableStream, body);
    HTML5_READONLY_PROPERTY(Response, bool, bodyUsed);

    Response(emscripten::val v);
    virtual ~Response();
    static Response *create(emscripten::val v);
    Response *clone();
    Response *error();
    Response *redirect(const std::string &url, int status = 0);
    Promise *arrayBuffer();
    Promise *blob();
    Promise *formData();
    Promise *json();
    Promise *text();
};

NAMESPACE_HTML5_END;
