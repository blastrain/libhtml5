#include "libhtml5.h"
#include <iostream>

static void createImage(std::string url)
{
    for (html5::StyleSheet *sheet : *html5::document->styleSheets) {
        html5::console->log(sheet);
    }
    html5::HTMLImageElement *image = html5::HTMLImageElement::create();
    static html5::EventHandler onload = [image](html5::Event *e){
        std::cout << "callback. onload" << std::endl;
        html5::console->trace();
        std::cout << "width = " << image->width << std::endl;
        std::cout << "height = " << image->height << std::endl;
        std::cout << "naturalWidth = " << image->naturalWidth << std::endl;
        std::cout << "naturalHeight = " << image->naturalHeight << std::endl;
    };
    image->onload = &onload;
    image->src = url;
    html5::document->body->appendChild(image);
    html5::console->log("image = ", image);
}
