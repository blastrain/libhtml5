#include "application_cache.h"
#include "document.h"
#include "external.h"
#include "element.h"
#include "history.h"
#include "bar_prop.h"
#include "window.h"

Window::Window(emscripten::val v) :
    EventTarget(v)
{

}

Window::~Window()
{

}

HTML5_PROPERTY_OBJECT_IMPL(Window, ApplicationCache, applicationCache);
HTML5_PROPERTY_IMPL(Window, bool, closed);
HTML5_PROPERTY_OBJECT_IMPL(Window, Document, document);
HTML5_PROPERTY_OBJECT_IMPL(Window, External, external);
HTML5_PROPERTY_OBJECT_IMPL(Window, Element, frameElement);
HTML5_PROPERTY_OBJECT_IMPL(Window, WindowProxy, frames);
HTML5_PROPERTY_OBJECT_IMPL(Window, History, history);
//HTML5_PROPERTY_OBJECT_IMPL(Window, IDBFactory, indexedDB);
HTML5_PROPERTY_IMPL(Window, unsigned long, length);
//HTML5_PROPERTY_OBJECT_IMPL(Window, Storage, localStorage);
//HTML5_PROPERTY_OBJECT_IMPL(Window, Location, location);
HTML5_PROPERTY_OBJECT_IMPL(Window, BarProp, locationbar);
HTML5_PROPERTY_OBJECT_IMPL(Window, BarProp, menubar);
HTML5_PROPERTY_IMPL(Window, std::string, name);
//HTML5_PROPERTY_OBJECT_IMPL(Window, Navigator, navigator);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, onabort);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, onafterprint);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, onautocomplete);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, onautocompleteerror);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, onbeforeprint);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, onbeforeunload);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, onblur);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, oncancel);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, oncanplay);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, oncanplaythrough);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, onchange);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, onclick);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, onclose);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, oncontextmenu);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, oncuechange);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, ondblclick);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, ondrag);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, ondragend);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, ondragenter);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, ondragexit);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, ondragleave);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, ondragover);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, ondragstart);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, ondrop);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, ondurationchange);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, onemptied);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, onended);
HTML5_ERROR_HANDLER_PROPERTY_IMPL(Window, OnErrorEventHandler *, onerror);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, onfocus);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, oninput);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, oninvalid);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, onkeydown);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, onkeypress);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, onkeyup);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, onlanguagechange);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, onload);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, onloadeddata);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, onloadedmetadata);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, onloadstart);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, onmessage);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, onmousedown);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, onmouseenter);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, onmouseleave);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, onmousemove);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, onmouseout);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, onmouseover);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, onmouseup);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, onmousewheel);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, onoffline);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, ononline);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, onpagehide);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, onpageshow);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, onpause);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, onplay);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, onplaying);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, onpopstate);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, onratechange);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, onreset);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, onresize);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, onscroll);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, onseeked);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, onseeking);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, onselect);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, onshow);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, onsort);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, onstalled);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, onstorage);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, onsubmit);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, onsuspend);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, ontimeupdate);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, ontoggle);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, onunload);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, onvolumechange);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Window, EventHandler *, onwaiting);
HTML5_PROPERTY_OBJECT_IMPL(Window, WindowProxy, opener);
HTML5_PROPERTY_OBJECT_IMPL(Window, WindowProxy, parent);
HTML5_PROPERTY_OBJECT_IMPL(Window, BarProp, personalbar);
HTML5_PROPERTY_OBJECT_IMPL(Window, BarProp, scrollbars);
HTML5_PROPERTY_OBJECT_IMPL(Window, WindowProxy, self);
//HTML5_PROPERTY_OBJECT_IMPL(Window, Storage, sessionStorage);
HTML5_PROPERTY_IMPL(Window, std::string, status);
HTML5_PROPERTY_OBJECT_IMPL(Window, BarProp, statusbar);
HTML5_PROPERTY_OBJECT_IMPL(Window, BarProp, toolbar);
HTML5_PROPERTY_OBJECT_IMPL(Window, WindowProxy, top);
HTML5_PROPERTY_OBJECT_IMPL(Window, WindowProxy, window);
//HTML5_PROPERTY_OBJECT_IMPL(Window, Performance, performance);
