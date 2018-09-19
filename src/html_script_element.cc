#include "html_script_element.h"

USING_NAMESPACE_HTML5;

HTMLScriptElement::HTMLScriptElement(emscripten::val v) :
    HTMLElement(v)
{

}

HTMLScriptElement::~HTMLScriptElement()
{

}

HTMLScriptElement *HTMLScriptElement::create(emscripten::val v)
{
    auto elem = new HTMLScriptElement(v);
    elem->autorelease();
    return elem;
}

HTML5_PROPERTY_IMPL(HTMLScriptElement, bool, async);
HTML5_PROPERTY_IMPL(HTMLScriptElement, std::string, charset);
HTML5_PROPERTY_IMPL(HTMLScriptElement, std::string, crossOrigin);
HTML5_PROPERTY_IMPL(HTMLScriptElement, bool, defer);
HTML5_PROPERTY_IMPL(HTMLScriptElement, std::string, src);
HTML5_PROPERTY_IMPL(HTMLScriptElement, std::string, text);
HTML5_PROPERTY_IMPL(HTMLScriptElement, std::string, type);
