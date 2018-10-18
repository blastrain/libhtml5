#include "html_body_element.h"

USING_NAMESPACE_HTML5;

HTML5_BIND_CLASS(HTMLBodyElement);

HTMLBodyElement::HTMLBodyElement(emscripten::val v) :
    HTMLElement(v)
{

}

HTMLBodyElement::~HTMLBodyElement()
{

}

HTMLBodyElement *HTMLBodyElement::create(emscripten::val v)
{
    HTMLBodyElement *e = new HTMLBodyElement(v);
    e->autorelease();
    return e;
}


HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLBodyElement, EventHandler *, onafterprint);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLBodyElement, EventHandler *, onbeforeprint);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLBodyElement, EventHandler *, onbeforeunload);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLBodyElement, EventHandler *, onhashchange);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLBodyElement, EventHandler *, onlanguagechange);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLBodyElement, EventHandler *, onmessage);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLBodyElement, EventHandler *, onoffline);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLBodyElement, EventHandler *, ononline);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLBodyElement, EventHandler *, onpagehide);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLBodyElement, EventHandler *, onpageshow);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLBodyElement, EventHandler *, onpopstate);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLBodyElement, EventHandler *, onstorage);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLBodyElement, EventHandler *, onunload);