#include "application_cache.h"
#include "navigator.h"
#include "storage.h"
#include "performance.h"
#include "idb_factory.h"
#include "location.h"
#include "document.h"
#include "external.h"
#include "element.h"
#include "history.h"
#include "bar_prop.h"
#include "promise.h"
#include "html_image_element.h"
#include "html_video_element.h"
#include "html_canvas_element.h"
#include "image_data.h"
#include "image_bitmap.h"
#include "css_style_declaration.h"
#include "blob.h"
#include "canvas_rendering_context_2d.h"
#include "console.h"
#include "window.h"

USING_NAMESPACE_HTML5;

HTML5_BIND_CLASS(Window);
HTML5_BIND_METHOD(Window, requestAnimationFrameCallback);
HTML5_BIND_METHOD(Window, setIntervalCallback);
HTML5_BIND_METHOD(Window, setTimeoutCallback);

Window::Window(emscripten::val v) :
    EventTarget(v),
    _requestAnimationFrameFn(NULL),
    _setIntervalFn(NULL),
    _setTimeoutFn(NULL)
{

}

Window::~Window()
{

}

Window *Window::create()
{
    return create(HTML5_STATIC_PRIMITIVE_INSTANCE(window));
}

Window *Window::create(emscripten::val v)
{
    auto window = new Window(v);
    window->autorelease();
    return window;
}

void Window::alert(std::string message)
{
    HTML5_CALL(this->v, alert, message);
}

std::string Window::atob(std::string atob)
{
    return HTML5_CALLs(this->v, atob, atob);
}
    
void Window::blur()
{
    HTML5_CALL(this->v, blur);
}

std::string Window::btoa(std::string btoa)
{
    return HTML5_CALLs(this->v, btoa, btoa);
}

void Window::cancelAnimationFrame(long handle)
{
    HTML5_CALL(this->v, cancelAnimationFrame, handle);
}

void Window::clearInterval(long handle)
{
    HTML5_CALL(this->v, clearInterval, handle);
}

void Window::clearTimeout(long handle)
{
    HTML5_CALL(this->v, clearTimeout, handle);
}

void Window::close()
{
    HTML5_CALL(this->v, close);
}

bool Window::confirm(std::string message)
{
    return HTML5_CALLb(this->v, confirm, message);
}

Promise *Window::createImageBitmap(HTMLImageElement *image, long sx, long sy, long sw, long sh)
{
    return Promise::create(HTML5_CALLv(this->v, createImageBitmap, image->v, sx, sy, sw, sh));
}

Promise *Window::createImageBitmap(HTMLVideoElement *image, long sx, long sy, long sw, long sh)
{
    return Promise::create(HTML5_CALLv(this->v, createImageBitmap, image->v, sx, sy, sw, sh));
}

Promise *Window::createImageBitmap(HTMLCanvasElement *image, long sx, long sy, long sw, long sh)
{
    return Promise::create(HTML5_CALLv(this->v, createImageBitmap, image->v, sx, sy, sw, sh));
}

Promise *Window::createImageBitmap(Blob *image, long sx, long sy, long sw, long sh)
{
    return Promise::create(HTML5_CALLv(this->v, createImageBitmap, image->v, sx, sy, sw, sh));
}
    
Promise *Window::createImageBitmap(ImageData *image, long sx, long sy, long sw, long sh)
{
    return Promise::create(HTML5_CALLv(this->v, createImageBitmap, image->v, sx, sy, sw, sh));
}

Promise *Window::createImageBitmap(CanvasRenderingContext2D *image, long sx, long sy, long sw, long sh)
{
    return Promise::create(HTML5_CALLv(this->v, createImageBitmap, image->v, sx, sy, sw, sh));
}

Promise *Window::createImageBitmap(ImageBitmap *image, long sx, long sy, long sw, long sh)
{
    return Promise::create(HTML5_CALLv(this->v, createImageBitmap, image->v, sx, sy, sw, sh));
}

void Window::focus()
{
    HTML5_CALL(this->v, focus);
}

CSSStyleDeclaration *Window::getComputedStyle(Element *elt, std::string pseudoElt)
{
    return CSSStyleDeclaration::create(HTML5_CALLv(this->v, getComputedStyle, elt->v, pseudoElt));
}

WindowProxy *Window::getter(void *indexName)
{
    return WindowProxy::create(HTML5_CALLv(this->v, getter, indexName));
}

WindowProxy *Window::open(std::string url, std::string target, std::string features, bool replace)
{
    return WindowProxy::create(HTML5_CALLv(this->v, open, url, target, features, replace));
}

void Window::postMessage(void *message, std::string targetOrigin, std::vector<Transferable *> transfer)
{
}

void Window::print()
{
    HTML5_CALL(this->v, print);
}

std::string Window::prompt(std::string message, std::string _default)
{
    return HTML5_CALLs(this->v, prompt, message, _default);
}

long Window::requestAnimationFrame(std::function<void(double)> *callback)
{
    this->_requestAnimationFrameFn = callback;
    return EM_ASM_INT({
        const w = Module.toWindow($0);
        return window.requestAnimationFrame(function(time) {
            w.requestAnimationFrameCallback(time);
        });
    }, this);
}

void Window::requestAnimationFrameCallback(double time)
{
    if (!this->_requestAnimationFrameFn) return;

    (*this->_requestAnimationFrameFn)(time);
}

long Window::setInterval(std::function<void(void)> *handler, long timeout)
{
    this->_setIntervalFn = handler;
    return EM_ASM_INT({
        const w = Module.toWindow($0);
        return window.setInterval(function() {
            w.setIntervalCallback();
        }, timeout);
    }, this);
}

void Window::setIntervalCallback()
{
    if (!this->_setIntervalFn) return;

    (*this->_setIntervalFn)();
}

long Window::setTimeout(std::function<void(void)> *handler, long timeout)
{
    this->_setTimeoutFn = handler;
    return EM_ASM_INT({
        const w = Module.toWindow($0);
        return window.setTimeout(function() {
            w.setTimeoutCallback();
        }, timeout);
    }, this);
}

void Window::setTimeoutCallback()
{
    if (!this->_setTimeoutFn) return;

    (*this->_setTimeoutFn)();
}

void Window::stop()
{
    HTML5_CALL(this->v, stop);
}

HTML5_PROPERTY_OBJECT_IMPL(Window, ApplicationCache, applicationCache);
HTML5_READONLY_PROPERTY_IMPL(Window, bool, closed);
HTML5_READONLY_PROPERTY_OBJECT_IMPL(Window, Console, console);
HTML5_PROPERTY_OBJECT_IMPL(Window, Document, document);
HTML5_PROPERTY_OBJECT_IMPL(Window, External, external);
HTML5_PROPERTY_OBJECT_IMPL(Window, Element, frameElement);
HTML5_PROPERTY_OBJECT_IMPL(Window, WindowProxy, frames);
HTML5_PROPERTY_OBJECT_IMPL(Window, History, history);
HTML5_PROPERTY_OBJECT_IMPL(Window, IDBFactory, indexedDB);
HTML5_PROPERTY_IMPL(Window, unsigned long, length);
HTML5_PROPERTY_OBJECT_IMPL(Window, Storage, localStorage);
HTML5_PROPERTY_OBJECT_IMPL(Window, Location, location);
HTML5_PROPERTY_OBJECT_IMPL(Window, BarProp, locationbar);
HTML5_PROPERTY_OBJECT_IMPL(Window, BarProp, menubar);
HTML5_PROPERTY_IMPL(Window, std::string, name);
HTML5_PROPERTY_OBJECT_IMPL(Window, Navigator, navigator);
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
HTML5_PROPERTY_OBJECT_IMPL(Window, Storage, sessionStorage);
HTML5_PROPERTY_IMPL(Window, std::string, status);
HTML5_PROPERTY_OBJECT_IMPL(Window, BarProp, statusbar);
HTML5_PROPERTY_OBJECT_IMPL(Window, BarProp, toolbar);
HTML5_PROPERTY_OBJECT_IMPL(Window, WindowProxy, top);
HTML5_PROPERTY_OBJECT_IMPL(Window, WindowProxy, window);
HTML5_PROPERTY_OBJECT_IMPL(Window, Performance, performance);
