#include "html_element.h"
#include "html_video_element.h"
#include "html_source_element.h"
#include "document.h"

Document::Document(emscripten::val v) :
    Node(v)
{

}

Document::~Document()
{

}

emscripten::val Document::_document()
{
    return emscripten::val::global("document");
}

Element *Document::createElement(std::string localName)
{
    emscripten::val v = _document().call<emscripten::val>("createElement", emscripten::val(localName));
    if (localName == "video") {
        return HTMLVideoElement::create(v);
    } else if (localName == "source") {
        return HTMLSourceElement::create(v);
    }
    return NULL;
}

HTMLElement *Document::body()
{
    return HTMLElement::create(_document()["body"]);
}

Document *Document::create(emscripten::val v)
{
    return new Document(v);
}
