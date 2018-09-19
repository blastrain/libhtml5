#include "libhtml5.h"
#include "class.h"

static emscripten::val toString(intptr_t ptr)
{
    return emscripten::val(std::string((char *)ptr));
}

static void init()
{
    window   = Window::create();
    window->retain();
    document = Document::create();
    document->retain();
}

EMSCRIPTEN_BINDINGS(html5) {
    function("toString", &toString, emscripten::allow_raw_pointers());
    emscripten::function("init", &init);
}
