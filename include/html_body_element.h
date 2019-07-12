#pragma once

#include "html5.h"
#include "event_handler.h"
#include "html_element.h"

NAMESPACE_HTML5_BEGIN;

class HTMLBodyElement : public HTMLElement {
public:

    HTML5_EVENT_HANDLER_PROPERTY(HTMLBodyElement, EventHandler *, onafterprint);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLBodyElement, EventHandler *, onbeforeprint);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLBodyElement, EventHandler *, onbeforeunload);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLBodyElement, EventHandler *, onhashchange);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLBodyElement, EventHandler *, onlanguagechange);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLBodyElement, EventHandler *, onmessage);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLBodyElement, EventHandler *, onoffline);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLBodyElement, EventHandler *, ononline);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLBodyElement, EventHandler *, onpagehide);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLBodyElement, EventHandler *, onpageshow);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLBodyElement, EventHandler *, onpopstate);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLBodyElement, EventHandler *, onstorage);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLBodyElement, EventHandler *, onunload);

    HTMLBodyElement(emscripten::val v);
    virtual ~HTMLBodyElement();
    static HTMLBodyElement *create(emscripten::val v);
};

NAMESPACE_HTML5_END;
