#include "libhtml5.h"
#include "class.h"
#include <iostream>

using namespace html5;

static void addStyleSheet() {
    HTML5_INIT();

    auto document = window->document;
    auto sheets = window->document->styleSheets;
    if (sheets->length == 0) {
        auto elem = document->createElement("style");
        elem->setAttribute("type","text/css");
        elem->innerText = "body { background-color: yellow; }";
        window->console->log(elem);
        document->head->appendChild(elem);

        auto style = dynamic_cast<HTMLStyleElement *>(elem);
        std::cout << (std::string)style->media << std::endl;
        std::cout << (std::string)style->type << std::endl;
        std::cout << std::boolalpha << style->scoped << std::endl;
        window->console->log((StyleSheet *)style->sheet);
        return;
    }

    for (auto sheet : *sheets) {
        window->console->log(sheet);
        auto cssSheet = dynamic_cast<CSSStyleSheet *>(sheet);
        for (auto i = 0; i < cssSheet->cssRules->length; i++) {
            auto rule = cssSheet->cssRules->item(i);
            window->console->log(rule);
            cssSheet->deleteRule(i);
        }
        cssSheet->insertRule("body { background-color: aqua; }", 0);

    }
}

EMSCRIPTEN_BINDINGS(module) {
    emscripten::function("addStyleSheet", &addStyleSheet);
}
