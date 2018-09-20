#include "libhtml5.h"
#include "class.h"

USING_NAMESPACE_HTML5;

static emscripten::val toString(intptr_t ptr)
{
    return emscripten::val(std::string((char *)ptr));
}

static bool g_initialized = false;

void HTML5_INIT()
{
    if (g_initialized) return;

    window = Window::create();
    window->retain();
    g_initialized = true;
}

EMSCRIPTEN_BINDINGS(html5) {
    function("toString", &toString, emscripten::allow_raw_pointers());
}
