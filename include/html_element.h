#pragma once

#include "libhtml5.h"
#include "element.h"
#include "event_handler.h"
#include <functional>

NAMESPACE_HTML5_BEGIN;

class HTMLMenuElement;
class DOMStringMap;
class DOMSettableTokenList;
class Event;
class HTMLPropertiesCollection;
class CSSStyleDeclaration;

class HTMLElement : public Element {
public:

    HTML5_PROPERTY(HTMLElement, std::string, accessKey);
    HTML5_PROPERTY(HTMLElement, std::string, accessKeyLabel);
    HTML5_PROPERTY(HTMLElement, bool, commandChecked);
    HTML5_PROPERTY(HTMLElement, bool, commandDisabled);
    HTML5_PROPERTY(HTMLElement, bool, commandHidden);
    HTML5_PROPERTY(HTMLElement, std::string, commandIcon);
    HTML5_PROPERTY(HTMLElement, std::string, commandLabel);
    HTML5_PROPERTY(HTMLElement, std::string, commandType);
    HTML5_PROPERTY(HTMLElement, std::string, contentEditable);
    HTML5_PROPERTY(HTMLElement, HTMLMenuElement *, contextMenu);
    HTML5_PROPERTY(HTMLElement, DOMStringMap *, dataset);
    HTML5_PROPERTY(HTMLElement, std::string, dir);
    HTML5_PROPERTY(HTMLElement, bool, draggable);
    HTML5_PROPERTY(HTMLElement, DOMSettableTokenList *, dropzone);
    HTML5_PROPERTY(HTMLElement, bool, hidden);
    HTML5_PROPERTY(HTMLElement, bool, isContentEditable);
    HTML5_PROPERTY(HTMLElement, std::string, itemId);
    HTML5_PROPERTY(HTMLElement, DOMSettableTokenList *, itemProp);
    HTML5_PROPERTY(HTMLElement, DOMSettableTokenList *, itemRef);
    HTML5_PROPERTY(HTMLElement, bool, itemScope);
    HTML5_PROPERTY(HTMLElement, DOMSettableTokenList *, itemType);
    HTML5_PROPERTY(HTMLElement, void *, itemValue);
    HTML5_PROPERTY(HTMLElement, std::string, lang);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLElement, EventHandler *, onabort);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLElement, EventHandler *, onautocomplete);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLElement, EventHandler *, onautocompleteerror);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLElement, EventHandler *, onblur);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLElement, EventHandler *, oncancel);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLElement, EventHandler *, oncanplay);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLElement, EventHandler *, oncanplaythrough);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLElement, EventHandler *, onchange);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLElement, EventHandler *, onclick);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLElement, EventHandler *, onclose);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLElement, EventHandler *, oncontextmenu);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLElement, EventHandler *, oncuechange);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLElement, EventHandler *, ondblclick);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLElement, EventHandler *, ondrag);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLElement, EventHandler *, ondragend);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLElement, EventHandler *, ondragenter);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLElement, EventHandler *, ondragexit);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLElement, EventHandler *, ondragleave);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLElement, EventHandler *, ondragover);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLElement, EventHandler *, ondragstart);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLElement, EventHandler *, ondrop);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLElement, EventHandler *, ondurationchange);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLElement, EventHandler *, onemptied);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLElement, EventHandler *, onended);
    HTML5_ERROR_HANDLER_PROPERTY(HTMLElement, OnErrorEventHandler *, onerror);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLElement, EventHandler *, onfocus);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLElement, EventHandler *, oninput);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLElement, EventHandler *, oninvalid);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLElement, EventHandler *, onkeydown);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLElement, EventHandler *, onkeypress);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLElement, EventHandler *, onkeyup);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLElement, EventHandler *, onload);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLElement, EventHandler *, onloadeddata);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLElement, EventHandler *, onloadedmetadata);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLElement, EventHandler *, onloadstart);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLElement, EventHandler *, onmousedown);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLElement, EventHandler *, onmouseenter);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLElement, EventHandler *, onmouseleave);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLElement, EventHandler *, onmousemove);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLElement, EventHandler *, onmouseout);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLElement, EventHandler *, onmouseover);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLElement, EventHandler *, onmouseup);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLElement, EventHandler *, onmousewheel);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLElement, EventHandler *, onpause);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLElement, EventHandler *, onplay);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLElement, EventHandler *, onplaying);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLElement, EventHandler *, onprogress);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLElement, EventHandler *, onratechange);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLElement, EventHandler *, onreset);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLElement, EventHandler *, onresize);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLElement, EventHandler *, onscroll);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLElement, EventHandler *, onseeked);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLElement, EventHandler *, onseeking);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLElement, EventHandler *, onselect);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLElement, EventHandler *, onshow);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLElement, EventHandler *, onsort);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLElement, EventHandler *, onstalled);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLElement, EventHandler *, onsubmit);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLElement, EventHandler *, onsuspend);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLElement, EventHandler *, ontimeupdate);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLElement, EventHandler *, ontoggle);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLElement, EventHandler *, onvolumechange);
    HTML5_EVENT_HANDLER_PROPERTY(HTMLElement, EventHandler *, onwaiting);
    HTML5_PROPERTY(HTMLElement, HTMLPropertiesCollection *, properties);
    HTML5_PROPERTY(HTMLElement, bool, spellcheck);
    HTML5_PROPERTY(HTMLElement, CSSStyleDeclaration *, style);
    HTML5_PROPERTY(HTMLElement, long, tabIndex);
    HTML5_PROPERTY(HTMLElement, std::string, title);
    HTML5_PROPERTY(HTMLElement, bool, translate);

    HTMLElement(emscripten::val v);
    virtual ~HTMLElement();
    static HTMLElement *create(emscripten::val v);
    void blur();
    void click();
    void focus();
    void forceSpellCheck();
    emscripten::val getValue() const;
};

NAMESPACE_HTML5_END;
