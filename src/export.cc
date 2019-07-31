#include "libhtml5.h"
#include "window.h"
#include "console.h"

NAMESPACE_HTML5_BEGIN;

Window *window;
Console *console;
Document *document;
Navigator *navigator;

static bool g_initialized = false;

class __runtime__ {
public:
    __runtime__() {
        if (g_initialized) return;

        window = Window::create();
        window->retain();
        console = window->console;
        console->retain();
        document = window->document;
        document->retain();
        navigator = window->navigator;
        navigator->retain();
        g_initialized = true;
    }
};

static __runtime__ r;

void alert(std::string message)
{
    return window->alert(message);
}

std::string atob(std::string atob)
{
    return window->atob(atob);
}

void blur()
{
    return window->blur();
}

std::string btoa(std::string btoa)
{
    return window->btoa(btoa);
}
    
void cancelAnimationFrame(long handle)
{
    return window->cancelAnimationFrame(handle);
}

void clearInterval(long handle)
{
    return window->clearInterval(handle);
}

void clearTimeout(long handle)
{
    return window->clearTimeout(handle);
}

void close()
{
    return window->close();
}

bool confirm(std::string message)
{
    return window->confirm(message);
}

Promise *createImageBitmap(HTMLImageElement *image, long sx, long sy, long sw, long sh)
{
    return window->createImageBitmap(image, sx, sy, sw, sh);
}

Promise *createImageBitmap(HTMLVideoElement *image, long sx, long sy, long sw, long sh)
{
    return window->createImageBitmap(image, sx, sy, sw, sh);
}

Promise *createImageBitmap(HTMLCanvasElement *image, long sx, long sy, long sw, long sh)
{
    return window->createImageBitmap(image, sx, sy, sw, sh);
}

Promise *createImageBitmap(Blob *image, long sx, long sy, long sw, long sh)
{
    return window->createImageBitmap(image, sx, sy, sw, sh);
}

Promise *createImageBitmap(ImageData *image, long sx, long sy, long sw, long sh)
{
    return window->createImageBitmap(image, sx, sy, sw, sh);
}

Promise *createImageBitmap(CanvasRenderingContext2D *image, long sx, long sy, long sw, long sh)
{
    return window->createImageBitmap(image, sx, sy, sw, sh);
}

Promise *createImageBitmap(ImageBitmap *image, long sx, long sy, long sw, long sh)
{
    return window->createImageBitmap(image, sx, sy, sw, sh);
}

Promise *fetch(const std::string &url)
{
    return window->fetch(url);
}

void focus()
{
    window->focus();
}

CSSStyleDeclaration *getComputedStyle(Element *elt, std::string pseudoElt)
{
    return window->getComputedStyle(elt, pseudoElt);
}

WindowProxy *getter(void *indexName)
{
    return window->getter(indexName);
}

WindowProxy *open(std::string url, std::string target, std::string features, bool replace)
{
    return window->open(url, target, features, replace);
}

void postMessage(void *message, std::string targetOrigin, std::vector<Transferable *> transfer)
{
    window->postMessage(message, targetOrigin, transfer);
}

void print()
{
    window->print();
}

std::string prompt(std::string message, std::string _default)
{
    return window->prompt(message, _default);
}

long requestAnimationFrame(const std::function<void(double)> &callback)
{
    return window->requestAnimationFrame(callback);
}

long setInterval(const std::function<void(void)> &handler, long timeout)
{
    return window->setInterval(handler, timeout);
}

long setTimeout(const std::function<void(void)> &handler, long timeout)
{
    return window->setTimeout(handler, timeout);
}

void stop()
{
    window->stop();
}

NAMESPACE_HTML5_END;
