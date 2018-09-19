#include "blob.h"
#include "html_canvas_element.h"

USING_NAMESPACE_HTML5;

HTML5_BIND_CLASS(HTMLCanvasElement);
HTML5_BIND_METHOD(HTMLCanvasElement, toBlobCallback);

HTMLCanvasElement::HTMLCanvasElement(emscripten::val v) :
    HTMLElement(v)
{

}

HTMLCanvasElement::~HTMLCanvasElement()
{

}

HTMLCanvasElement *HTMLCanvasElement::create(emscripten::val v)
{
    auto canvas = new HTMLCanvasElement(v);
    canvas->autorelease();
    return canvas;
}

RenderingContext *HTMLCanvasElement::getContext(std::string contextId)
{
    return RenderingContext::create(HTML5_CALLv(this->v, getContext, contextId));
}

void HTMLCanvasElement::toBlob(std::function<void(Blob*)> *callback, std::string mimeType, double qualityArgument)
{
    this->_toBlobFn = callback;
    EM_ASM_({
        const elem = Module.toHTMLCanvasElement($0);
        const mimeType = Module.toString($1);
        const quality  = $2;
        elem._value.toBlob(function(blob) { elem.toBlobCallback(blob); }, mimeType, quality);
    }, this, mimeType.c_str(), qualityArgument);
}

void HTMLCanvasElement::toBlobCallback(emscripten::val blob)
{
    if (!this->_toBlobFn) return;

    (*this->_toBlobFn)(Blob::create(blob));
}

std::string HTMLCanvasElement::toDataURL(std::string type, double encoderOptions)
{
    return HTML5_CALLs(this->v, toDataURL, type, encoderOptions);
}

HTML5_PROPERTY_IMPL(HTMLCanvasElement, unsigned long, height);
HTML5_PROPERTY_IMPL(HTMLCanvasElement, unsigned long, width);
