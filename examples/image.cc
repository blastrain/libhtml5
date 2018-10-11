#include "libhtml5.h"
#include "class.h"
#include <iostream>

static void createImage(std::string url)
{
    HTML5_INIT();
    for (html5::StyleSheet *sheet : *html5::window->document->styleSheets) {
        html5::window->console->log(sheet);
    }
    html5::HTMLImageElement *image = html5::HTMLImageElement::create();
    static html5::EventHandler onload = [image](html5::Event *e){
        html5::window->console->trace();
        std::cout << "callback. onload" << std::endl;
        std::cout << "width = " << image->width << std::endl;
        std::cout << "height = " << image->height << std::endl;
        std::cout << "naturalWidth = " << image->naturalWidth << std::endl;
        std::cout << "naturalHeight = " << image->naturalHeight << std::endl;
    };
    html5::Console *console = html5::window->console;
    image->onload = &onload;
    image->src = url;
    html5::Document *document = html5::window->document;
    document->body->appendChild(image);
    console->log("image = ", image);
}
