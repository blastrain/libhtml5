#include "event.h"
#include "html_properties_collection.h"
#include "html_menu_element.h"
#include "html_element.h"
#include "css_style_declaration.h"

HTML5_BIND_CLASS(HTMLElement);


HTMLElement::HTMLElement(emscripten::val v) :
    Element(v)
{

}

HTMLElement::~HTMLElement()
{

}

HTMLElement *HTMLElement::create(emscripten::val v)
{
    HTMLElement *e = new HTMLElement(v);
    e->autorelease();
    return e;
}

void HTMLElement::blur()
{
    HTML5_CALL(this->v, blur);
}

void HTMLElement::click()
{
    HTML5_CALL(this->v, click);
}

void HTMLElement::focus()
{
    HTML5_CALL(this->v, focus);
}

void HTMLElement::forceSpellCheck()
{
    HTML5_CALL(this->v, forceSpellCheck);
}

emscripten::val HTMLElement::getValue() const
{
    return this->v;
}

HTML5_PROPERTY_IMPL(HTMLElement, std::string, accessKey);
HTML5_PROPERTY_IMPL(HTMLElement, std::string, accessKeyLabel);
HTML5_PROPERTY_IMPL(HTMLElement, bool, commandChecked);
HTML5_PROPERTY_IMPL(HTMLElement, bool, commandDisabled);
HTML5_PROPERTY_IMPL(HTMLElement, bool, commandHidden);
HTML5_PROPERTY_IMPL(HTMLElement, std::string, commandIcon);
HTML5_PROPERTY_IMPL(HTMLElement, std::string, commandLabel);
HTML5_PROPERTY_IMPL(HTMLElement, std::string, commandType);
HTML5_PROPERTY_IMPL(HTMLElement, std::string, contentEditable);
HTML5_PROPERTY_OBJECT_IMPL(HTMLElement, HTMLMenuElement, contextMenu);
//HTML5_PROPERTY_OBJECT_IMPL(HTMLElement, DOMStringMap, dataset);
HTML5_PROPERTY_IMPL(HTMLElement, std::string, dir);
HTML5_PROPERTY_IMPL(HTMLElement, bool, draggable);
//HTML5_PROPERTY_OBJECT_IMPL(HTMLElement, DOMSettableTokenList, dropzone);
HTML5_PROPERTY_IMPL(HTMLElement, bool, hidden);
HTML5_PROPERTY_IMPL(HTMLElement, bool, isContentEditable);
HTML5_PROPERTY_IMPL(HTMLElement, std::string, itemId);
//HTML5_PROPERTY_OBJECT_IMPL(HTMLElement, DOMSettableTokenList, itemProp);
//HTML5_PROPERTY_OBJECT_IMPL(HTMLElement, DOMSettableTokenList, itemRef);
HTML5_PROPERTY_IMPL(HTMLElement, bool, itemScope);
//HTML5_PROPERTY_OBJECT_IMPL(HTMLElement, DOMSettableTokenList, itemType);
//HTML5_PROPERTY_IMPL(HTMLElement, void *, itemValue);
HTML5_PROPERTY_IMPL(HTMLElement, std::string, lang);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLElement, EventHandler *, onabort);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLElement, EventHandler *, onautocomplete);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLElement, EventHandler *, onautocompleteerror);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLElement, EventHandler *, onblur);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLElement, EventHandler *, oncancel);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLElement, EventHandler *, oncanplay);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLElement, EventHandler *, oncanplaythrough);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLElement, EventHandler *, onchange);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLElement, EventHandler *, onclick);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLElement, EventHandler *, onclose);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLElement, EventHandler *, oncontextmenu);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLElement, EventHandler *, oncuechange);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLElement, EventHandler *, ondblclick);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLElement, EventHandler *, ondrag);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLElement, EventHandler *, ondragend);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLElement, EventHandler *, ondragenter);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLElement, EventHandler *, ondragexit);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLElement, EventHandler *, ondragleave);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLElement, EventHandler *, ondragover);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLElement, EventHandler *, ondragstart);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLElement, EventHandler *, ondrop);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLElement, EventHandler *, ondurationchange);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLElement, EventHandler *, onemptied);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLElement, EventHandler *, onended);
HTML5_ERROR_HANDLER_PROPERTY_IMPL(HTMLElement, OnErrorEventHandler *, onerror);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLElement, EventHandler *, onfocus);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLElement, EventHandler *, oninput);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLElement, EventHandler *, oninvalid);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLElement, EventHandler *, onkeydown);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLElement, EventHandler *, onkeypress);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLElement, EventHandler *, onkeyup);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLElement, EventHandler *, onload);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLElement, EventHandler *, onloadeddata);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLElement, EventHandler *, onloadedmetadata);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLElement, EventHandler *, onloadstart);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLElement, EventHandler *, onmousedown);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLElement, EventHandler *, onmouseenter);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLElement, EventHandler *, onmouseleave);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLElement, EventHandler *, onmousemove);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLElement, EventHandler *, onmouseout);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLElement, EventHandler *, onmouseover);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLElement, EventHandler *, onmouseup);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLElement, EventHandler *, onmousewheel);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLElement, EventHandler *, onpause);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLElement, EventHandler *, onplay);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLElement, EventHandler *, onplaying);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLElement, EventHandler *, onprogress);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLElement, EventHandler *, onratechange);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLElement, EventHandler *, onreset);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLElement, EventHandler *, onresize);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLElement, EventHandler *, onscroll);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLElement, EventHandler *, onseeked);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLElement, EventHandler *, onseeking);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLElement, EventHandler *, onselect);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLElement, EventHandler *, onshow);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLElement, EventHandler *, onsort);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLElement, EventHandler *, onstalled);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLElement, EventHandler *, onsubmit);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLElement, EventHandler *, onsuspend);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLElement, EventHandler *, ontimeupdate);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLElement, EventHandler *, ontoggle);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLElement, EventHandler *, onvolumechange);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(HTMLElement, EventHandler *, onwaiting);
HTML5_PROPERTY_OBJECT_IMPL(HTMLElement, HTMLPropertiesCollection, properties);
HTML5_PROPERTY_IMPL(HTMLElement, bool, spellcheck);
HTML5_PROPERTY_OBJECT_IMPL(HTMLElement, CSSStyleDeclaration, style);
HTML5_PROPERTY_IMPL(HTMLElement, long, tabIndex);
HTML5_PROPERTY_IMPL(HTMLElement, std::string, title);
HTML5_PROPERTY_IMPL(HTMLElement, bool, translate);
