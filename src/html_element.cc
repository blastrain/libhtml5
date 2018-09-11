#include "event.h"
#include "html_properties_collection.h"
#include "html_menu_element.h"
#include "html_element.h"
#include "css_style_declaration.h"

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

std::string HTMLElement::getAccessKey() const
{
    return HTML5_PROPERTY_GET(accessKey, std::string);
}

void HTMLElement::setAccessKey(std::string value)
{
    this->_accessKey = value;
    this->v.set("accessKey", value);
}

std::string HTMLElement::getAccessKeyLabel() const
{
    return HTML5_PROPERTY_GET(accessKeyLabel, std::string);
}

void HTMLElement::setAccessKeyLabel(std::string value)
{
    this->_accessKeyLabel = value;
    this->v.set("accessKeyLabel", value);
}

bool HTMLElement::getCommandChecked() const
{
    return HTML5_PROPERTY_GET(commandChecked, bool);
}

void HTMLElement::setCommandChecked(bool value)
{
    this->_commandChecked = value;
    this->v.set("commandChecked", value);
}

bool HTMLElement::getCommandDisabled() const
{
    return HTML5_PROPERTY_GET(commandDisabled, bool);
}

void HTMLElement::setCommandDisabled(bool value)
{
    this->_commandDisabled = value;
    this->v.set("commandDisabled", value);
}

bool HTMLElement::getCommandHidden() const
{
    return HTML5_PROPERTY_GET(commandHidden, bool);
}

void HTMLElement::setCommandHidden(bool value)
{
    this->_commandHidden = value;
    this->v.set("commandHidden", value);
}

std::string HTMLElement::getCommandIcon() const
{
    return HTML5_PROPERTY_GET(commandIcon, std::string);
}

void HTMLElement::setCommandIcon(std::string value)
{
    this->_commandIcon = value;
    this->v.set("commandIcon", value);
}

std::string HTMLElement::getCommandLabel() const
{
    return HTML5_PROPERTY_GET(commandLabel, std::string);
}

void HTMLElement::setCommandLabel(std::string value)
{
    this->_commandLabel = value;
    this->v.set("commandLabel", value);
}

std::string HTMLElement::getCommandType() const
{
    return HTML5_PROPERTY_GET(commandType, std::string);
}

void HTMLElement::setCommandType(std::string value)
{
    this->_commandType = value;
    this->v.set("commandType", value);
}

std::string HTMLElement::getContentEditable() const
{
    return HTML5_PROPERTY_GET(contentEditable, std::string);
}

void HTMLElement::setContentEditable(std::string value)
{
    this->_contentEditable = value;
    this->v.set("contentEditable", value);
}

HTMLMenuElement *HTMLElement::getContextMenu() const
{
    return HTML5_PROPERTY_GET(contextMenu, HTMLMenuElement);
}

void HTMLElement::setContextMenu(HTMLMenuElement *value)
{
    this->_contextMenu = value;
    this->v.set("contextMenu", value->v);
}

//DOMStringMap *getDataSet() const;
//void setDataSet(DOMStringMap *value);

std::string HTMLElement::getDir() const
{
    return HTML5_PROPERTY_GET(dir, std::string);
}

void HTMLElement::setDir(std::string value)
{
    this->_dir = value;
    this->v.set("dir", value);
}

bool HTMLElement::getDraggable() const
{
    return HTML5_PROPERTY_GET(draggable, bool);
}

void HTMLElement::setDraggable(bool value)
{
    this->_draggable = value;
    this->v.set("draggable", value);
}

//DOMSettableTokenList *getDropzone() const;
//void setDropzone(DOMSettableTokenList *value);

bool HTMLElement::getHidden() const
{
    return HTML5_PROPERTY_GET(hidden, bool);
}

void HTMLElement::setHidden(bool value)
{
    this->_hidden = value;
    this->v.set("hidden", value);
}

bool HTMLElement::getIsContentEditable() const
{
    return HTML5_PROPERTY_GET(isContentEditable, bool);
}

void HTMLElement::setIsContentEditable(bool value)
{
    this->_isContentEditable = value;
    this->v.set("isContentEditable", value);
}

std::string HTMLElement::getItemId() const
{
    return HTML5_PROPERTY_GET(itemId, std::string);
}

void HTMLElement::setItemId(std::string value)
{
    this->_itemId = value;
    this->v.set("itemId", value);
}

//DOMSettableTokenList *getItemProp() const;
//void setItemProp(DOMSettableTokenList *value);
//DOMSettableTokenList *getItemRef() const;
//void setItemRef(DOMSettableTokenList *value);
bool HTMLElement::getItemScope() const
{
    return HTML5_PROPERTY_GET(itemScope, bool);
}

void HTMLElement::setItemScope(bool value)
{
    this->_itemScope = value;
    this->v.set("itemScope", value);
}

//DOMSettableTokenList *getItemType() const;
//void setItemType(DOMSettableTokenList *value);
/*
void *HTMLElement::getItemValue() const
{
    return this->v["itemValue"];
}

void HTMLElement::setItemValue(void *value)
{
    this->_itemValue = value;
    this->v.set("itemValue", value);
}
*/

std::string HTMLElement::getLang() const
{
    return HTML5_PROPERTY_GET(lang, std::string);
}

void HTMLElement::setLang(std::string value)
{
    this->_lang = value;
    this->v.set("lang", value);
}

EventHandler *HTMLElement::getOnAbort() const
{
    return this->_onabort;
}

void HTMLElement::setOnAbort(EventHandler *value)
{
    this->_onabort = value;
    EM_ASM_({
        const element = Module.toHTMLElement($0);
        element._value.onabort = function(e) { element.onAbortCallback(e); };
    }, this);
}

void HTMLElement::onAbortCallback(emscripten::val e)
{
    if (!this->_onabort) return;

    (*this->_onabort)(Event::create(e));
}

EventHandler *HTMLElement::getOnAutoComplete() const
{
    return this->_onautocomplete;
}

void HTMLElement::setOnAutoComplete(EventHandler *value)
{
    this->_onautocomplete = value;
    EM_ASM_({
        const element = Module.toHTMLElement($0);
        element._value.onautocomplete = function(e) { element.onAutoCompleteCallback(e); };
    }, this);
}

void HTMLElement::onAutoCompleteCallback(emscripten::val e)
{
    if (!this->_onautocomplete) return;

    (*this->_onautocomplete)(Event::create(e));
}

EventHandler *HTMLElement::getOnAutoCompleteError() const
{
    return this->_onautocompleteerror;
}

void HTMLElement::setOnAutoCompleteError(EventHandler *value)
{
    this->_onautocompleteerror = value;
    EM_ASM_({
        const element = Module.toHTMLElement($0);
        element._value.onautocompleteerror = function(e) { element.onAutoCompleteErrorCallback(e); };
    }, this);
}

void HTMLElement::onAutoCompleteErrorCallback(emscripten::val e)
{
    if (!this->_onautocompleteerror) return;

    (*this->_onautocompleteerror)(Event::create(e));
}

EventHandler *HTMLElement::getOnBlur() const
{
    return this->_onblur;
}

void HTMLElement::setOnBlur(EventHandler *value)
{
    this->_onblur = value;
    EM_ASM_({
        const element = Module.toHTMLElement($0);
        element._value.onblur = function(e) { element.onBlurCallback(e); };
    }, this);
}

void HTMLElement::onBlurCallback(emscripten::val e)
{
    if (!this->_onblur) return;

    (*this->_onblur)(Event::create(e));
}

EventHandler *HTMLElement::getOnCancel() const
{
    return this->_oncancel;
}

void HTMLElement::setOnCancel(EventHandler *value)
{
    this->_oncancel = value;
    EM_ASM_({
        const element = Module.toHTMLElement($0);
        element._value.oncancel = function(e) { element.onCancelCallback(e); };
    }, this);
}

void HTMLElement::onCancelCallback(emscripten::val e)
{
    if (!this->_oncancel) return;

    (*this->_oncancel)(Event::create(e));
}

EventHandler *HTMLElement::getOnCanplay() const
{
    return this->_oncanplay;
}

void HTMLElement::setOnCanplay(EventHandler *value)
{
    this->_oncanplay = value;
    EM_ASM_({
        const element = Module.toHTMLElement($0);
        element._value.oncanplay = function(e) { element.onCanplayCallback(e); };
    }, this);
}

void HTMLElement::onCanplayCallback(emscripten::val e)
{
    if (!this->_oncanplay) return;

    (*this->_oncanplay)(Event::create(e));
}

EventHandler *HTMLElement::getOnCanplayThrough() const
{
    return this->_oncanplaythrough;
}

void HTMLElement::setOnCanplayThrough(EventHandler *value)
{
    this->_oncanplaythrough = value;
    EM_ASM_({
        const element = Module.toHTMLElement($0);
        element._value.oncanplaythrough = function(e) { element.onCanplayThroughCallback(e); };
    }, this);
}

void HTMLElement::onCanplayThroughCallback(emscripten::val e)
{
    if (!this->_oncanplaythrough) return;

    (*this->_oncanplaythrough)(Event::create(e));
}

EventHandler *HTMLElement::getOnChange() const
{
    return this->_onchange;
}

void HTMLElement::setOnChange(EventHandler *value)
{
    this->_onchange = value;
    EM_ASM_({
        const element = Module.toHTMLElement($0);
        element._value.onchange = function(e) { element.onChangeCallback(e); };
    }, this);
}

void HTMLElement::onChangeCallback(emscripten::val e)
{
    if (!this->_onchange) return;

    (*this->_onchange)(Event::create(e));
}

EventHandler *HTMLElement::getOnClick() const
{
    return this->_onclick;
}

void HTMLElement::setOnClick(EventHandler *value)
{
    this->_onclick = value;
    EM_ASM_({
        const element = Module.toHTMLElement($0);
        element._value.onclick = function(e) { element.onClickCallback(e); };
    }, this);
}

void HTMLElement::onClickCallback(emscripten::val e)
{
    if (!this->_onclick) return;

    (*this->_onclick)(Event::create(e));
}

EventHandler *HTMLElement::getOnClose() const
{
    return this->_onclose;
}

void HTMLElement::setOnClose(EventHandler *value)
{
    this->_onclose = value;
    EM_ASM_({
        const element = Module.toHTMLElement($0);
        element._value.onclose = function(e) { element.onCloseCallback(e); };
    }, this);
}

void HTMLElement::onCloseCallback(emscripten::val e)
{
    if (!this->_onclose) return;

    (*this->_onclose)(Event::create(e));
}

EventHandler *HTMLElement::getOnContextMenu() const
{
    return this->_oncontextmenu;
}

void HTMLElement::setOnContextMenu(EventHandler *value)
{
    this->_oncontextmenu = value;
    EM_ASM_({
        const element = Module.toHTMLElement($0);
        element._value.oncontextmenu = function(e) { element.onContextMenuCallback(e); };
    }, this);
}

void HTMLElement::onContextMenuCallback(emscripten::val e)
{
    if (!this->_oncontextmenu) return;

    (*this->_oncontextmenu)(Event::create(e));
}

EventHandler *HTMLElement::getOnCueChange() const
{
    return this->_oncuechange;
}

void HTMLElement::setOnCueChange(EventHandler *value)
{
    this->_oncuechange = value;
    EM_ASM_({
        const element = Module.toHTMLElement($0);
        element._value.oncuechange = function(e) { element.onCueChangeCallback(e); };
    }, this);
}

void HTMLElement::onCueChangeCallback(emscripten::val e)
{
    if (!this->_oncuechange) return;

    (*this->_oncuechange)(Event::create(e));
}

EventHandler *HTMLElement::getOnDoubleClick() const
{
    return this->_ondblclick;
}

void HTMLElement::setOnDoubleClick(EventHandler *value)
{
    this->_ondblclick = value;
    EM_ASM_({
        const element = Module.toHTMLElement($0);
        element._value.ondblclick = function(e) { element.onDoubleClickCallback(e); };
    }, this);
}

void HTMLElement::onDoubleClickCallback(emscripten::val e)
{
    if (!this->_ondblclick) return;

    (*this->_ondblclick)(Event::create(e));
}

EventHandler *HTMLElement::getOnDrag() const
{
    return this->_ondrag;
}

void HTMLElement::setOnDrag(EventHandler *value)
{
    this->_ondrag = value;
    EM_ASM_({
        const element = Module.toHTMLElement($0);
        element._value.ondrag = function(e) { element.onDragCallback(e); };
    }, this);
}

void HTMLElement::onDragCallback(emscripten::val e)
{
    if (!this->_ondrag) return;

    (*this->_ondrag)(Event::create(e));
}

EventHandler *HTMLElement::getOnDragEnd() const
{
    return this->_ondragend;
}

void HTMLElement::setOnDragEnd(EventHandler *value)
{
    this->_ondragend = value;
    EM_ASM_({
        const element = Module.toHTMLElement($0);
        element._value.ondragend = function(e) { element.onDragEndCallback(e); };
    }, this);
}

void HTMLElement::onDragEndCallback(emscripten::val e)
{
    if (!this->_ondragend) return;

    (*this->_ondragend)(Event::create(e));
}

EventHandler *HTMLElement::getOnDragEnter() const
{
    return this->_ondragenter;
}

void HTMLElement::setOnDragEnter(EventHandler *value)
{
    this->_ondragenter = value;
    EM_ASM_({
        const element = Module.toHTMLElement($0);
        element._value.ondragenter = function(e) { element.onDragEnterCallback(e); };
    }, this);
}

void HTMLElement::onDragEnterCallback(emscripten::val e)
{
    if (!this->_ondragenter) return;

    (*this->_ondragenter)(Event::create(e));
}

EventHandler *HTMLElement::getOnDragExit() const
{
    return this->_ondragexit;
}

void HTMLElement::setOnDragExit(EventHandler *value)
{
    this->_ondragexit = value;
    EM_ASM_({
        const element = Module.toHTMLElement($0);
        element._value.ondragexit = function(e) { element.onDragExitCallback(e); };
    }, this);
}

void HTMLElement::onDragExitCallback(emscripten::val e)
{
    if (!this->_ondragexit) return;

    (*this->_ondragexit)(Event::create(e));
}

EventHandler *HTMLElement::getOnDragLeave() const
{
    return this->_ondragleave;
}

void HTMLElement::setOnDragLeave(EventHandler *value)
{
    this->_ondragleave = value;
    EM_ASM_({
        const element = Module.toHTMLElement($0);
        element._value.ondragleave = function(e) { element.onDragLeaveCallback(e); };
    }, this);
}

void HTMLElement::onDragLeaveCallback(emscripten::val e)
{
    if (!this->_ondragleave) return;

    (*this->_ondragleave)(Event::create(e));
}

EventHandler *HTMLElement::getOnDragOver() const
{
    return this->_ondragover;
}

void HTMLElement::setOnDragOver(EventHandler *value)
{
    this->_ondragover = value;
    EM_ASM_({
        const element = Module.toHTMLElement($0);
        element._value.ondragover = function(e) { element.onDragOverCallback(e); };
    }, this);
}

void HTMLElement::onDragOverCallback(emscripten::val e)
{
    if (!this->_ondragover) return;

    (*this->_ondragover)(Event::create(e));
}

EventHandler *HTMLElement::getOnDragStart() const
{
    return this->_ondragstart;
}

void HTMLElement::setOnDragStart(EventHandler *value)
{
    this->_ondragstart = value;
    EM_ASM_({
        const element = Module.toHTMLElement($0);
        element._value.ondragstart = function(e) { element.onDragStartCallback(e); };
    }, this);
}

void HTMLElement::onDragStartCallback(emscripten::val e)
{
    if (!this->_ondragstart) return;

    (*this->_ondragstart)(Event::create(e));
}

EventHandler *HTMLElement::getOnDrop() const
{
    return this->_ondrop;
}

void HTMLElement::setOnDrop(EventHandler *value)
{
    this->_ondrop = value;
    EM_ASM_({
        const element = Module.toHTMLElement($0);
        element._value.ondrop = function(e) { element.onDropCallback(e); };
    }, this);
}

void HTMLElement::onDropCallback(emscripten::val e)
{
    if (!this->_ondrop) return;

    (*this->_ondrop)(Event::create(e));
}

EventHandler *HTMLElement::getOnDurationChange() const
{
    return this->_ondurationchange;
}

void HTMLElement::setOnDurationChange(EventHandler *value)
{
    this->_ondurationchange = value;
    EM_ASM_({
        const element = Module.toHTMLElement($0);
        element._value.ondurationchange = function(e) { element.onDurationChangeCallback(e); };
    }, this);
}

void HTMLElement::onDurationChangeCallback(emscripten::val e)
{
    if (!this->_ondurationchange) return;

    (*this->_ondurationchange)(Event::create(e));
}

EventHandler *HTMLElement::getOnEmptied() const
{
    return this->_onemptied;
}

void HTMLElement::setOnEmptied(EventHandler *value)
{
    this->_onemptied = value;
    EM_ASM_({
        const element = Module.toHTMLElement($0);
        element._value.onemptied = function(e) { element.onEmptiedCallback(e); };
    }, this);
}

void HTMLElement::onEmptiedCallback(emscripten::val e)
{
    if (!this->_onemptied) return;

    (*this->_onemptied)(Event::create(e));
}

EventHandler *HTMLElement::getOnEnded() const
{
    return this->_onended;
}

void HTMLElement::setOnEnded(EventHandler *value)
{
    this->_onended = value;
    EM_ASM_({
        const element = Module.toHTMLElement($0);
        element._value.onended = function(e) { element.onEndedCallback(e); };
    }, this);
}

void HTMLElement::onEndedCallback(emscripten::val e)
{
    if (!this->_onended) return;

    (*this->_onended)(Event::create(e));
}

OnErrorEventHandler *HTMLElement::getOnError() const
{
    return this->_onerror;
}

void HTMLElement::setOnError(OnErrorEventHandler *value)
{
    this->_onerror = value;
    EM_ASM_({
        const element = Module.toHTMLElement($0);
        element._value.onerror = function(event, source, lineno, colno, error) {
            element.onErrorCallback(event, source, lineno, colno, error);
        };
    }, this);
}

void HTMLElement::onErrorCallback(emscripten::val event, std::string source, unsigned long lineno, unsigned long colno, emscripten::val error)
{
    if (!this->_onerror) return;

    (*this->_onerror)(Event::create(event), source, lineno, colno, NULL);
}

EventHandler *HTMLElement::getOnFocus() const
{
    return this->_onfocus;
}

void HTMLElement::setOnFocus(EventHandler *value)
{
    this->_onfocus = value;
    EM_ASM_({
        const element = Module.toHTMLElement($0);
        element._value.onfocus = function(e) { element.onFocusCallback(e); };
    }, this);
}

void HTMLElement::onFocusCallback(emscripten::val e)
{
    if (!this->_onfocus) return;

    (*this->_onfocus)(Event::create(e));
}

EventHandler *HTMLElement::getOnInput() const
{
    return this->_oninput;
}

void HTMLElement::setOnInput(EventHandler *value)
{
    this->_oninput = value;
    EM_ASM_({
        const element = Module.toHTMLElement($0);
        element._value.oninput = function(e) { element.onInputCallback(e); };
    }, this);
}

void HTMLElement::onInputCallback(emscripten::val e)
{
    if (!this->_oninput) return;

    (*this->_oninput)(Event::create(e));
}

EventHandler *HTMLElement::getOnInvalid() const
{
    return this->_oninvalid;
}

void HTMLElement::setOnInvalid(EventHandler *value)
{
    this->_oninvalid = value;
    EM_ASM_({
        const element = Module.toHTMLElement($0);
        element._value.oninvalid = function(e) { element.onInvalidCallback(e); };
    }, this);
}

void HTMLElement::onInvalidCallback(emscripten::val e)
{
    if (!this->_oninvalid) return;

    (*this->_oninvalid)(Event::create(e));
}

EventHandler *HTMLElement::getOnKeyDown() const
{
    return this->_onkeydown;
}

void HTMLElement::setOnKeyDown(EventHandler *value)
{
    this->_onkeydown = value;
    EM_ASM_({
        const element = Module.toHTMLElement($0);
        element._value.onkeydown = function(e) { element.onKeyDownCallback(e); };
    }, this);
}

void HTMLElement::onKeyDownCallback(emscripten::val e)
{
    if (!this->_onkeydown) return;

    (*this->_onkeydown)(Event::create(e));
}

EventHandler *HTMLElement::getOnKeyPress() const
{
    return this->_onkeypress;
}

void HTMLElement::setOnKeyPress(EventHandler *value)
{
    this->_onkeypress = value;
    EM_ASM_({
        const element = Module.toHTMLElement($0);
        element._value.onkeypress = function(e) { element.onKeyPressCallback(e); };
    }, this);
}

void HTMLElement::onKeyPressCallback(emscripten::val e)
{
    if (!this->_onkeypress) return;

    (*this->_onkeypress)(Event::create(e));
}

EventHandler *HTMLElement::getOnKeyUp() const
{
    return this->_onkeyup;
}

void HTMLElement::setOnKeyUp(EventHandler *value)
{
    this->_onkeyup = value;
    EM_ASM_({
        const element = Module.toHTMLElement($0);
        element._value.onkeyup = function(e) { element.onKeyUpCallback(e); };
    }, this);
}

void HTMLElement::onKeyUpCallback(emscripten::val e)
{
    if (!this->_onkeyup) return;

    (*this->_onkeyup)(Event::create(e));
}

EventHandler *HTMLElement::getOnLoad() const
{
    return this->_onload;
}

void HTMLElement::setOnLoad(EventHandler *value)
{
    this->_onload = value;
    EM_ASM_({
        const element = Module.toHTMLElement($0);
        element._value.onload = function(e) { element.onLoadCallback(e); };
    }, this);
}

void HTMLElement::onLoadCallback(emscripten::val e)
{
    if (!this->_onload) return;

    (*this->_onload)(Event::create(e));
}

EventHandler *HTMLElement::getOnLoadedData() const
{
    return this->_onloadeddata;
}

void HTMLElement::setOnLoadedData(EventHandler *value)
{
    this->_onloadeddata = value;
    EM_ASM_({
        const element = Module.toHTMLElement($0);
        element._value.onloadeddata = function(e) { element.onLoadedDataCallback(e); };
    }, this);
}

void HTMLElement::onLoadedDataCallback(emscripten::val e)
{
    if (!this->_onloadeddata) return;

    (*this->_onloadeddata)(Event::create(e));
}
    

EventHandler *HTMLElement::getOnLoadedMetaData() const
{
    return this->_onloadedmetadata;
}

void HTMLElement::setOnLoadedMetaData(EventHandler *value)
{
    this->_onloadedmetadata = value;
    EM_ASM_({
        const element = Module.toHTMLElement($0);
        element._value.onloadedmetadata = function(e) { element.onLoadedMetaDataCallback(e); };
    }, this);
}

void HTMLElement::onLoadedMetaDataCallback(emscripten::val e)
{
    if (!this->_onloadedmetadata) return;

    (*this->_onloadedmetadata)(Event::create(e));
}

EventHandler *HTMLElement::getOnLoadStart() const
{
    return this->_onloadstart;
}

void HTMLElement::setOnLoadStart(EventHandler *value)
{
    this->_onloadstart = value;
    EM_ASM_({
        const element = Module.toHTMLElement($0);
        element._value.onloadstart = function(e) { element.onLoadStartCallback(e); };
    }, this);
}

void HTMLElement::onLoadStartCallback(emscripten::val e)
{
    if (!this->_onloadstart) return;

    (*this->_onloadstart)(Event::create(e));
}

EventHandler *HTMLElement::getOnMouseDown() const
{
    return this->_onmousedown;
}

void HTMLElement::setOnMouseDown(EventHandler *value)
{
    this->_onmousedown = value;
    EM_ASM_({
        const element = Module.toHTMLElement($0);
        element._value.onmousedown = function(e) { element.onMouseDownCallback(e); };
    }, this);
}

void HTMLElement::onMouseDownCallback(emscripten::val e)
{
    if (!this->_onmousedown) return;

    (*this->_onmousedown)(Event::create(e));
}

EventHandler *HTMLElement::getOnMouseEnter() const
{
    return this->_onmouseenter;
}

void HTMLElement::setOnMouseEnter(EventHandler *value)
{
    this->_onmouseenter = value;
    EM_ASM_({
        const element = Module.toHTMLElement($0);
        element._value.onmouseenter = function(e) { element.onMouseEnterCallback(e); };
    }, this);
}

void HTMLElement::onMouseEnterCallback(emscripten::val e)
{
    if (!this->_onmouseenter) return;

    (*this->_onmouseenter)(Event::create(e));
}

EventHandler *HTMLElement::getOnMouseLeave() const
{
    return this->_onmouseleave;
}

void HTMLElement::setOnMouseLeave(EventHandler *value)
{
    this->_onmouseleave = value;
    EM_ASM_({
        const element = Module.toHTMLElement($0);
        element._value.onmouseleave = function(e) { element.onMouseLeaveCallback(e); };
    }, this);
}

void HTMLElement::onMouseLeaveCallback(emscripten::val e)
{
    if (!this->_onmouseleave) return;

    (*this->_onmouseleave)(Event::create(e));
}

EventHandler *HTMLElement::getOnMouseMove() const
{
    return this->_onmousemove;
}

void HTMLElement::setOnMouseMove(EventHandler *value)
{
    this->_onmousemove = value;
    EM_ASM_({
        const element = Module.toHTMLElement($0);
        element._value.onmousemove = function(e) { element.onMouseMoveCallback(e); };
    }, this);
}

void HTMLElement::onMouseMoveCallback(emscripten::val e)
{
    if (!this->_onmousemove) return;

    (*this->_onmousemove)(Event::create(e));
}

EventHandler *HTMLElement::getOnMouseOut() const
{
    return this->_onmouseout;
}

void HTMLElement::setOnMouseOut(EventHandler *value)
{
    this->_onmouseout = value;
    EM_ASM_({
        const element = Module.toHTMLElement($0);
        element._value.onmouseout = function(e) { element.onMouseOutCallback(e); };
    }, this);
}

void HTMLElement::onMouseOutCallback(emscripten::val e)
{
    if (!this->_onmouseout) return;

    (*this->_onmouseout)(Event::create(e));
}

EventHandler *HTMLElement::getOnMouseOver() const
{
    return this->_onmouseover;
}

void HTMLElement::setOnMouseOver(EventHandler *value)
{
    this->_onmouseover = value;
    EM_ASM_({
        const element = Module.toHTMLElement($0);
        element._value.onmouseover = function(e) { element.onMouseOverCallback(e); };
    }, this);
}

void HTMLElement::onMouseOverCallback(emscripten::val e)
{
    if (!this->_onmouseover) return;

    (*this->_onmouseover)(Event::create(e));
}
                                      
EventHandler *HTMLElement::getOnMouseUp() const
{
    return this->_onmouseup;
}

void HTMLElement::setOnMouseUp(EventHandler *value)
{
    this->_onmouseup = value;
    EM_ASM_({
        const element = Module.toHTMLElement($0);
        element._value.onmouseup = function(e) { element.onMouseUpCallback(e); };
    }, this);
}

void HTMLElement::onMouseUpCallback(emscripten::val e)
{
    if (!this->_onmouseup) return;

    (*this->_onmouseup)(Event::create(e));
}

EventHandler *HTMLElement::getOnMouseWheel() const
{
    return this->_onmousewheel;
}

void HTMLElement::setOnMouseWheel(EventHandler *value)
{
    this->_onmousewheel = value;
    EM_ASM_({
        const element = Module.toHTMLElement($0);
        element._value.onmousewheel = function(e) { element.onMouseWheelCallback(e); };
    }, this);
}

void HTMLElement::onMouseWheelCallback(emscripten::val e)
{
    if (!this->_onmousewheel) return;

    (*this->_onmousewheel)(Event::create(e));
}

EventHandler *HTMLElement::getOnPause() const
{
    return this->_onpause;
}

void HTMLElement::setOnPause(EventHandler *value)
{
    this->_onpause = value;
    EM_ASM_({
        const element = Module.toHTMLElement($0);
        element._value.onpause = function(e) { element.onPauseCallback(e); };
    }, this);
}

void HTMLElement::onPauseCallback(emscripten::val e)
{
    if (!this->_onpause) return;

    (*this->_onpause)(Event::create(e));
}

EventHandler *HTMLElement::getOnPlay() const
{
    return this->_onplay;
}

void HTMLElement::setOnPlay(EventHandler *value)
{
    this->_onplay = value;
    EM_ASM_({
        const element = Module.toHTMLElement($0);
        element._value.onplay = function(e) { element.onPlayCallback(e); };
    }, this);
}

void HTMLElement::onPlayCallback(emscripten::val e)
{
    if (!this->_onplay) return;

    (*this->_onplay)(Event::create(e));
}

EventHandler *HTMLElement::getOnPlaying() const
{
    return this->_onplaying;
}

void HTMLElement::setOnPlaying(EventHandler *value)
{
    this->_onplaying = value;
    EM_ASM_({
        const element = Module.toHTMLElement($0);
        element._value.onplaying = function(e) { element.onPlayingCallback(e); };
    }, this);
}

void HTMLElement::onPlayingCallback(emscripten::val e)
{
    if (!this->_onplaying) return;

    (*this->_onplaying)(Event::create(e));
}

EventHandler *HTMLElement::getOnProgress() const
{
    return this->_onprogress;
}

void HTMLElement::setOnProgress(EventHandler *value)
{
    this->_onprogress = value;
    EM_ASM_({
        const element = Module.toHTMLElement($0);
        element._value.onprogress = function(e) { element.onProgressCallback(e); };
    }, this);
}

void HTMLElement::onProgressCallback(emscripten::val e)
{
    if (!this->_onprogress) return;

    (*this->_onprogress)(Event::create(e));
}

EventHandler *HTMLElement::getOnRateChange() const
{
    return this->_onratechange;
}

void HTMLElement::setOnRateChange(EventHandler *value)
{
    this->_onratechange = value;
    EM_ASM_({
        const element = Module.toHTMLElement($0);
        element._value.onratechange = function(e) { element.onRateChangeCallback(e); };
    }, this);
}

void HTMLElement::onRateChangeCallback(emscripten::val e)
{
    if (!this->_onratechange) return;

    (*this->_onratechange)(Event::create(e));
}

EventHandler *HTMLElement::getOnReset() const
{
    return this->_onreset;
}

void HTMLElement::setOnReset(EventHandler *value)
{
    this->_onreset = value;
    EM_ASM_({
        const element = Module.toHTMLElement($0);
        element._value.onreset = function(e) { element.onResetCallback(e); };
    }, this);
}

void HTMLElement::onResetCallback(emscripten::val e)
{
    if (!this->_onreset) return;

    (*this->_onreset)(Event::create(e));
}

EventHandler *HTMLElement::getOnResize() const
{
    return this->_onresize;
}

void HTMLElement::setOnResize(EventHandler *value)
{
    this->_onresize = value;
    EM_ASM_({
        const element = Module.toHTMLElement($0);
        element._value.onresize = function(e) { element.onResizeCallback(e); };
    }, this);
}

void HTMLElement::onResizeCallback(emscripten::val e)
{
    if (!this->_onresize) return;

    (*this->_onresize)(Event::create(e));
}

EventHandler *HTMLElement::getOnScroll() const
{
    return this->_onscroll;
}

void HTMLElement::setOnScroll(EventHandler *value)
{
    this->_onscroll = value;
    EM_ASM_({
        const element = Module.toHTMLElement($0);
        element._value.onscroll = function(e) { element.onScrollCallback(e); };
    }, this);
}

void HTMLElement::onScrollCallback(emscripten::val e)
{
    if (!this->_onscroll) return;

    (*this->_onscroll)(Event::create(e));
}

EventHandler *HTMLElement::getOnSeeked() const
{
    return this->_onseeked;
}

void HTMLElement::setOnSeeked(EventHandler *value)
{
    this->_onseeked = value;
    EM_ASM_({
        const element = Module.toHTMLElement($0);
        element._value.onseeked = function(e) { element.onSeekedCallback(e); };
    }, this);
}

void HTMLElement::onSeekedCallback(emscripten::val e)
{
    if (!this->_onseeked) return;

    (*this->_onseeked)(Event::create(e));
}

EventHandler *HTMLElement::getOnSeeking() const
{
    return this->_onseeking;
}

void HTMLElement::setOnSeeking(EventHandler *value)
{
    this->_onseeking = value;
    EM_ASM_({
        const element = Module.toHTMLElement($0);
        element._value.onseeking = function(e) { element.onSeekingCallback(e); };
    }, this);
}

void HTMLElement::onSeekingCallback(emscripten::val e)
{
    if (!this->_onseeking) return;

    (*this->_onseeking)(Event::create(e));
}

EventHandler *HTMLElement::getOnSelect() const
{
    return this->_onselect;
}

void HTMLElement::setOnSelect(EventHandler *value)
{
    this->_onselect = value;
    EM_ASM_({
        const element = Module.toHTMLElement($0);
        element._value.onselect = function(e) { element.onSelectCallback(e); };
    }, this);
}

void HTMLElement::onSelectCallback(emscripten::val e)
{
    if (!this->_onselect) return;

    (*this->_onselect)(Event::create(e));
}

EventHandler *HTMLElement::getOnShow() const
{
    return this->_onshow;
}

void HTMLElement::setOnShow(EventHandler *value)
{
    this->_onshow = value;
    EM_ASM_({
        const element = Module.toHTMLElement($0);
        element._value.onshow = function(e) { element.onShowCallback(e); };
    }, this);
}

void HTMLElement::onShowCallback(emscripten::val e)
{
    if (!this->_onshow) return;

    (*this->_onshow)(Event::create(e));
}

EventHandler *HTMLElement::getOnSort() const
{
    return this->_onsort;
}

void HTMLElement::setOnSort(EventHandler *value)
{
    this->_onsort = value;
    EM_ASM_({
        const element = Module.toHTMLElement($0);
        element._value.onsort = function(e) { element.onSortCallback(e); };
    }, this);
}

void HTMLElement::onSortCallback(emscripten::val e)
{
    if (!this->_onsort) return;

    (*this->_onsort)(Event::create(e));
}

EventHandler *HTMLElement::getOnStalled() const
{
    return this->_onstalled;
}

void HTMLElement::setOnStalled(EventHandler *value)
{
    this->_onstalled = value;
    EM_ASM_({
        const element = Module.toHTMLElement($0);
        element._value.onstalled = function(e) { element.onStalledCallback(e); };
    }, this);
}

void HTMLElement::onStalledCallback(emscripten::val e)
{
    if (!this->_onstalled) return;

    (*this->_onstalled)(Event::create(e));
}

EventHandler *HTMLElement::getOnSubmit() const
{
    return this->_onsubmit;
}

void HTMLElement::setOnSubmit(EventHandler *value)
{
    this->_onsubmit = value;
    EM_ASM_({
        const element = Module.toHTMLElement($0);
        element._value.onsubmit = function(e) { element.onSubmitCallback(e); };
    }, this);
}

void HTMLElement::onSubmitCallback(emscripten::val e)
{
    if (!this->_onsubmit) return;

    (*this->_onsubmit)(Event::create(e));
}

EventHandler *HTMLElement::getOnSuspend() const
{
    return this->_onsuspend;
}

void HTMLElement::setOnSuspend(EventHandler *value)
{
    this->_onsuspend = value;
    EM_ASM_({
        const element = Module.toHTMLElement($0);
        element._value.onsuspend = function(e) { element.onSuspendCallback(e); };
    }, this);
}

void HTMLElement::onSuspendCallback(emscripten::val e)
{
    if (!this->_onsuspend) return;

    (*this->_onsuspend)(Event::create(e));
}

EventHandler *HTMLElement::getOnTimeUpdate() const
{
    return this->_ontimeupdate;
}

void HTMLElement::setOnTimeUpdate(EventHandler *value)
{
    this->_ontimeupdate = value;
    EM_ASM_({
        const element = Module.toHTMLElement($0);
        element._value.ontimeupdate = function(e) { element.onTimeUpdateCallback(e); };
    }, this);
}

void HTMLElement::onTimeUpdateCallback(emscripten::val e)
{
    if (!this->_ontimeupdate) return;

    (*this->_ontimeupdate)(Event::create(e));
}

EventHandler *HTMLElement::getOnToggle() const
{
    return this->_ontoggle;
}

void HTMLElement::setOnToggle(EventHandler *value)
{
    this->_ontoggle = value;
    EM_ASM_({
        const element = Module.toHTMLElement($0);
        element._value.ontoggle = function(e) { element.onToggleCallback(e); };
    }, this);
}

void HTMLElement::onToggleCallback(emscripten::val e)
{
    if (!this->_ontoggle) return;

    (*this->_ontoggle)(Event::create(e));
}

EventHandler *HTMLElement::getOnVolumeChange() const
{
    return this->_onvolumechange;
}

void HTMLElement::setOnVolumeChange(EventHandler *value)
{
    this->_onvolumechange = value;
    EM_ASM_({
        const element = Module.toHTMLElement($0);
        element._value.onvolumechange = function(e) { element.onVolumeChangeCallback(e); };
    }, this);
}

void HTMLElement::onVolumeChangeCallback(emscripten::val e)
{
    if (!this->_onvolumechange) return;

    (*this->_onvolumechange)(Event::create(e));
}

EventHandler *HTMLElement::getOnWaiting() const
{
    return this->_onwaiting;
}

void HTMLElement::setOnWaiting(EventHandler *value)
{
    this->_onwaiting = value;
    EM_ASM_({
        const element = Module.toHTMLElement($0);
        element._value.onwaiting = function(e) { element.onWaitingCallback(e); };
    }, this);
}

void HTMLElement::onWaitingCallback(emscripten::val e)
{
    if (!this->_onwaiting) return;

    (*this->_onwaiting)(Event::create(e));
}

HTMLPropertiesCollection *HTMLElement::getProperties() const
{
    return HTML5_PROPERTY_GET(properties, HTMLPropertiesCollection);
}

void HTMLElement::setProperties(HTMLPropertiesCollection *value)
{
    this->_properties = value;
    this->v.set("properties", value->v);
}

bool HTMLElement::getSpellCheck() const
{
    return HTML5_PROPERTY_GET(spellcheck, bool);
}

void HTMLElement::setSpellCheck(bool value)
{
    this->_spellcheck = value;
    this->v.set("spellCheck", value);
}

CSSStyleDeclaration *HTMLElement::getStyle() const
{
    return HTML5_PROPERTY_GET(style, CSSStyleDeclaration);
}

void HTMLElement::setStyle(CSSStyleDeclaration *value)
{
    this->_style = value;
    this->v.set("style", value->v);
}

long HTMLElement::getTabIndex() const
{
    return HTML5_PROPERTY_GET(tabIndex, long);
}

void HTMLElement::setTabIndex(long value)
{
    this->_tabIndex = value;
    this->v.set("tabIndex", value);
}

std::string HTMLElement::getTitle() const
{
    return HTML5_PROPERTY_GET(title, std::string);
}

void HTMLElement::setTitle(std::string value)
{
    this->_title = value;
    this->v.set("title", value);
}

bool HTMLElement::getTranslate() const
{
    return HTML5_PROPERTY_GET(translate, bool);
}

void HTMLElement::setTranslate(bool value)
{
    this->_translate = value;
    this->v.set("translate", value);
}

