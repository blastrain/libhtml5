#include "event.h"
#include "html_menu_element.h"
#include "html_element.h"
#include <emscripten/emscripten.h>

HTMLElement::HTMLElement(emscripten::val v) :
    Element(v)
{

}

HTMLElement::~HTMLElement()
{

}

HTMLElement *HTMLElement::create(emscripten::val v)
{
    return new HTMLElement(v);
}

void HTMLElement::blur()
{
    this->v.call<void>("blur");
}

void HTMLElement::click()
{
    this->v.call<void>("click");
}

void HTMLElement::focus()
{
    this->v.call<void>("focus");
}

void HTMLElement::forceSpellCheck()
{
    this->v.call<void>("forceSpellCheck");
}

emscripten::val HTMLElement::getValue() const
{
    return this->v;
}

std::string HTMLElement::getAccessKey() const
{
    return this->v["accessKey"].as<std::string>();
}

void HTMLElement::setAccessKey(std::string value)
{
    this->_accessKey = value;
    this->v.set("accessKey", value);
}

std::string HTMLElement::getAccessKeyLabel() const
{
    return this->v["accessKeyLabel"].as<std::string>();
}

void HTMLElement::setAccessKeyLabel(std::string value)
{
    this->_accessKeyLabel = value;
    this->v.set("accessKeyLabel", value);
}

bool HTMLElement::getCommandChecked() const
{
    return this->v["commandChecked"].as<bool>();
}

void HTMLElement::setCommandChecked(bool value)
{
    this->_commandChecked = value;
    this->v.set("commandChecked", value);
}

bool HTMLElement::getCommandDisabled() const
{
    return this->v["commandDisabled"].as<bool>();
}

void HTMLElement::setCommandDisabled(bool value)
{
    this->_commandDisabled = value;
    this->v.set("commandDisabled", value);
}

bool HTMLElement::getCommandHidden() const
{
    return this->v["commandHidden"].as<bool>();
}

void HTMLElement::setCommandHidden(bool value)
{
    this->_commandHidden = value;
    this->v.set("commandHidden", value);
}

std::string HTMLElement::getCommandIcon() const
{
    return this->v["commandIcon"].as<std::string>();
}

void HTMLElement::setCommandIcon(std::string value)
{
    this->_commandIcon = value;
    this->v.set("commandIcon", value);
}

std::string HTMLElement::getCommandLabel() const
{
    return this->v["commandLabel"].as<std::string>();
}

void HTMLElement::setCommandLabel(std::string value)
{
    this->_commandLabel = value;
    this->v.set("commandLabel", value);
}

std::string HTMLElement::getCommandType() const
{
    return this->v["commandType"].as<std::string>();
}

void HTMLElement::setCommandType(std::string value)
{
    this->_commandType = value;
    this->v.set("commandType", value);
}

std::string HTMLElement::getContentEditable() const
{
    return this->v["contentEditable"].as<std::string>();
}

void HTMLElement::setContentEditable(std::string value)
{
    this->_contentEditable = value;
    this->v.set("contentEditable", value);
}

HTMLMenuElement *HTMLElement::getContextMenu() const
{
    return HTMLMenuElement::create(this->v["contentMenu"]);
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
    return this->v["dir"].as<std::string>();
}

void HTMLElement::setDir(std::string value)
{
    this->_dir = value;
    this->v.set("dir", value);
}

bool HTMLElement::getDraggable() const
{
    return this->v["draggable"].as<bool>();
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
    return this->v["hidden"].as<bool>();
}

void HTMLElement::setHidden(bool value)
{
    this->_hidden = value;
    this->v.set("hidden", value);
}

bool HTMLElement::getIsContentEditable() const
{
    return this->v["isContentEditable"].as<bool>();
}

void HTMLElement::setIsContentEditable(bool value)
{
    this->_isContentEditable = value;
    this->v.set("isContentEditable", value);
}

std::string HTMLElement::getItemId() const
{
    return this->v["itemId"].as<std::string>();
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
    return this->v["itemScope"].as<bool>();
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
    return this->v["lang"].as<std::string>();
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

/*
EventHandler *getOnLoadedData() const;
void setOnLoadedData(EventHandler *value);
EventHandler *getOnLoadedMetaData() const;
void setOnLoadedMetaData(EventHandler *value);
EventHandler *getOnLoadStart() const;
void setOnLoadStart(EventHandler *value);
EventHandler *getOnMouseDown() const;
void setOnMouseDown(EventHandler *value);
EventHandler *getOnMouseEnter() const;
void setOnMouseEnter(EventHandler *value);
EventHandler *getOnMouseLeave() const;
void setOnMouseLeave(EventHandler *value);
EventHandler *getOnMouseMove() const;
void setOnMouseMove(EventHandler *value);
EventHandler *getOnMouseOut() const;
void setOnMouseOut(EventHandler *value);
EventHandler *getOnMouseOver() const;
void setOnMouseOver(EventHandler *value);
EventHandler *getOnMouseUp() const;
void setOnMouseUp(EventHandler *value);
EventHandler *getOnMouseWheel() const;
void setOnMouseWheel(EventHandler *value);
EventHandler *getOnPause() const;
void setOnPause(EventHandler *value);
EventHandler *getOnPlay() const;
void setOnPlay(EventHandler *value);
EventHandler *getOnPlaying() const;
void setOnPlaying(EventHandler *value);
EventHandler *getOnProgress() const;
void setOnProgress(EventHandler *value);
EventHandler *getOnRateChange() const;
void setOnRateChange(EventHandler *value);
EventHandler *getOnReset() const;
void setOnReset(EventHandler *value);
EventHandler *getOnResize() const;
void setOnResize(EventHandler *value);
EventHandler *getOnScroll() const;
void setOnScroll(EventHandler *value);
EventHandler *getOnSeeked() const;
void setOnSeeked(EventHandler *value);
EventHandler *getOnSeeking() const;
void setOnSeeking(EventHandler *value);
EventHandler *getOnSelect() const;
void setOnSelect(EventHandler *value);
EventHandler *getOnShow() const;
void setOnShow(EventHandler *value);
EventHandler *getOnSort() const;
void setOnSort(EventHandler *value);
EventHandler *getOnStalled() const;
void setOnStalled(EventHandler *value);
EventHandler *getOnSubmit() const;
void setOnSubmit(EventHandler *value);
EventHandler *getOnSuspend() const;
void setOnSuspend(EventHandler *value);
EventHandler *getOnTimeUpdate() const;
void setOnTimeUpdate(EventHandler *value);
EventHandler *getOnToggle() const;
void setOnToggle(EventHandler *value);
EventHandler *getOnVolumeChange() const;
void setOnVolumeChange(EventHandler *value);
EventHandler *getOnWaiting() const;
void setOnWaiting(EventHandler *value);
HTMLPropertiesCollection *getProperties() const;
void setProperties(HTMLPropertiesCollection *value);
bool getSpellCheck() const;
void setSpellCheck(bool value);
CSSStyleDeclaration *getStyle() const;
void setStyle(CSSStyleDeclaration *value);
long getTabIndex() const;
void setTabIndex(long value);
std::string getTitle() const;
void setTitle(std::string value);
bool getTranslate() const;
void setTranslate(bool value);
*/
