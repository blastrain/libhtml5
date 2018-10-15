#include "libhtml5.h"
#include "class.h"

#include "image.cc"
#include "style_sheet.cc"
#include "video.cc"

static void executeTest()
{
    addStyleSheet();
    createImage("https://www.google.com/images/branding/googlelogo/2x/googlelogo_color_272x92dp.png");
    createVideo("http://clips.vorwaerts-gmbh.de/VfE_html5.mp4");
}

EMSCRIPTEN_BINDINGS(html5example) {
    emscripten::function("executeTest", &executeTest);
}



