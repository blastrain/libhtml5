#pragma once

#include "libhtml5.h"
#include "element.h"
#include "event_handler.h"
#include <functional>

class HTMLMenuElement;
class DOMStringMap;
class DOMSettableTokenList;
class Event;
class HTMLPropertiesCollection;
class CSSStyleDeclaration;

class HTMLElement : public Element {
public:
    std::string _accessKey;
    std::string _accessKeyLabel;
    bool _commandChecked;
    bool _commandDisabled;
    bool _commandHidden;
    std::string _commandIcon;
    std::string _commandLabel;
    std::string _commandType;
    std::string _contentEditable;
    HTMLMenuElement *_contextMenu;
    DOMStringMap *_dataset;
    std::string _dir;
    bool _draggable;
    DOMSettableTokenList *_dropzone;
    bool _hidden;
    bool _isContentEditable;
    std::string _itemId;
    DOMSettableTokenList *_itemProp;
    DOMSettableTokenList *_itemRef;
    bool _itemScope;
    DOMSettableTokenList *_itemType;
    void *_itemValue;
    std::string _lang;
    EventHandler *_onabort;
    EventHandler *_onautocomplete;
    EventHandler *_onautocompleteerror;
    EventHandler *_onblur;
    EventHandler *_oncancel;
    EventHandler *_oncanplay;
    EventHandler *_oncanplaythrough;
    EventHandler *_onchange;
    EventHandler *_onclick;
    EventHandler *_onclose;
    EventHandler *_oncontextmenu;
    EventHandler *_oncuechange;
    EventHandler *_ondblclick;
    EventHandler *_ondrag;
    EventHandler *_ondragend;
    EventHandler *_ondragenter;
    EventHandler *_ondragexit;
    EventHandler *_ondragleave;
    EventHandler *_ondragover;
    EventHandler *_ondragstart;
    EventHandler *_ondrop;
    EventHandler *_ondurationchange;
    EventHandler *_onemptied;
    EventHandler *_onended;
    OnErrorEventHandler *_onerror;
    EventHandler *_onfocus;
    EventHandler *_oninput;
    EventHandler *_oninvalid;
    EventHandler *_onkeydown;
    EventHandler *_onkeypress;
    EventHandler *_onkeyup;
    EventHandler *_onload;
    EventHandler *_onloadeddata;
    EventHandler *_onloadedmetadata;
    EventHandler *_onloadstart;
    EventHandler *_onmousedown;
    EventHandler *_onmouseenter;
    EventHandler *_onmouseleave;
    EventHandler *_onmousemove;
    EventHandler *_onmouseout;
    EventHandler *_onmouseover;
    EventHandler *_onmouseup;
    EventHandler *_onmousewheel;
    EventHandler *_onpause;
    EventHandler *_onplay;
    EventHandler *_onplaying;
    EventHandler *_onprogress;
    EventHandler *_onratechange;
    EventHandler *_onreset;
    EventHandler *_onresize;
    EventHandler *_onscroll;
    EventHandler *_onseeked;
    EventHandler *_onseeking;
    EventHandler *_onselect;
    EventHandler *_onshow;
    EventHandler *_onsort;
    EventHandler *_onstalled;
    EventHandler *_onsubmit;
    EventHandler *_onsuspend;
    EventHandler *_ontimeupdate;
    EventHandler *_ontoggle;
    EventHandler *_onvolumechange;
    EventHandler *_onwaiting;
    HTMLPropertiesCollection *_properties;
    bool _spellcheck;
    CSSStyleDeclaration *_style;
    long _tabIndex;
    std::string _title;
    bool _translate;

    HTMLElement(emscripten::val v);
    virtual ~HTMLElement();
    static HTMLElement *create(emscripten::val v);
    void blur();
    void click();
    void focus();
    void forceSpellCheck();
    emscripten::val getValue() const;

    struct {
        HTMLElement &self;
        void operator=(std::string value) { self.setAccessKey(value); };
        operator std::string() { return self.getAccessKey(); };
    } accessKey{*this};

    struct {
        HTMLElement &self;
        void operator=(std::string value) { self.setAccessKeyLabel(value); };
        operator std::string() { return self.getAccessKeyLabel(); };
    } accessKeyLabel{*this};

    struct {
        HTMLElement &self;
        void operator=(bool value) { self.setCommandChecked(value); };
        operator bool() { return self.getCommandChecked(); };
    } commandChecked{*this};

    struct {
        HTMLElement &self;
        void operator=(bool value) { self.setCommandDisabled(value); };
        operator bool() { return self.getCommandDisabled(); };
    } commandDisabled{*this};

    struct {
        HTMLElement &self;
        void operator=(bool value) { self.setCommandHidden(value); };
        operator bool() { return self.getCommandHidden(); };
    } commandHidden{*this};

    struct {
        HTMLElement &self;
        void operator=(std::string value) { self.setCommandIcon(value); };
        operator std::string() { return self.getCommandIcon(); };
    } commandIcon{*this};

    struct {
        HTMLElement &self;
        void operator=(std::string value) { self.setCommandLabel(value); };
        operator std::string() { return self.getCommandLabel(); };
    } commandLabel{*this};

    struct {
        HTMLElement &self;
        void operator=(std::string value) { self.setCommandType(value); };
        operator std::string() { return self.getCommandType(); };
    } commandType{*this};

    struct {
        HTMLElement &self;
        void operator=(std::string value) { self.setContentEditable(value); };
        operator std::string() { return self.getContentEditable(); };
    } contentEditable{*this};

    struct {
        HTMLElement &self;
        void operator=(HTMLMenuElement *value) { self.setContextMenu(value); };
        operator HTMLMenuElement *() { return self.getContextMenu(); };
    } contextMenu{*this};

    struct {
        HTMLElement &self;
        void operator=(DOMStringMap *value) { self.setDataSet(value); };
        operator DOMStringMap *() { return self.getDataSet(); };
    } dataset{*this};

    struct {
        HTMLElement &self;
        void operator=(std::string value) { self.setDir(value); };
        operator std::string() { return self.getDir(); };
    } dir{*this};

    struct {
        HTMLElement &self;
        void operator=(bool value) { self.setDraggable(value); };
        operator bool() { return self.getDraggable(); };
    } draggable{*this};

    struct {
        HTMLElement &self;
        void operator=(DOMSettableTokenList *value) { self.setDropzone(value); };
        operator DOMSettableTokenList *() { return self.getDropzone(); };
    } dropzone{*this};

    struct {
        HTMLElement &self;
        void operator=(bool value) { self.setHidden(value); };
        operator bool() { return self.getHidden(); };
    } hidden{*this};

    struct {
        HTMLElement &self;
        void operator=(bool value) { self.setIsContentEditable(value); };
        operator bool() { return self.getIsContentEditable(); };
    } isContentEditable{*this};

    struct {
        HTMLElement &self;
        void operator=(std::string value) { self.setItemId(value); };
        operator std::string() { return self.getItemId(); };
    } itemId{*this};

    struct {
        HTMLElement &self;
        void operator=(DOMSettableTokenList *value) { self.setItemProp(value); };
        operator DOMSettableTokenList *() { return self.getItemProp(); };
    } itemProp{*this};

    struct {
        HTMLElement &self;
        void operator=(DOMSettableTokenList *value) { self.setItemRef(value); };
        operator DOMSettableTokenList *() { return self.getItemRef(); };
    } itemRef{*this};

    struct {
        HTMLElement &self;
        void operator=(bool value) { self.setItemScope(value); };
        operator bool() { return self.getItemScope(); };
    } itemScope{*this};

    struct {
        HTMLElement &self;
        void operator=(DOMSettableTokenList *value) { self.setItemType(value); };
        operator DOMSettableTokenList *() { return self.getItemType(); };
    } itemType{*this};

    struct {
        HTMLElement &self;
        void operator=(void *value) { self.setItemValue(value); };
        operator void *() { return self.getItemValue(); };
    } itemValue{*this};

    struct {
        HTMLElement &self;
        void operator=(std::string value) { self.setLang(value); };
        operator std::string() { return self.getLang(); };
    } lang{*this};

    struct {
        HTMLElement &self;
        void operator=(EventHandler *value) { self.setOnAbort(value); };
        operator EventHandler *() { return self.getOnAbort(); };
    } onabort{*this};

    struct {
        HTMLElement &self;
        void operator=(EventHandler *value) { self.setOnAutoComplete(value); };
        operator EventHandler *() { return self.getOnAutoComplete(); };
    } onautocomplete{*this};

    struct {
        HTMLElement &self;
        void operator=(EventHandler *value) { self.setOnAutoCompleteError(value); };
        operator EventHandler *() { return self.getOnAutoCompleteError(); };
    } onautocompleteerror{*this};

    struct {
        HTMLElement &self;
        void operator=(EventHandler *value) { self.setOnBlur(value); };
        operator EventHandler *() { return self.getOnBlur(); };
    } onblur{*this};

    struct {
        HTMLElement &self;
        void operator=(EventHandler *value) { self.setOnCancel(value); };
        operator EventHandler *() { return self.getOnCancel(); };
    } oncancel{*this};

    struct {
        HTMLElement &self;
        void operator=(EventHandler *value) { self.setOnCanplay(value); };
        operator EventHandler *() { return self.getOnCanplay(); };
    } oncanplay{*this};

    struct {
        HTMLElement &self;
        void operator=(EventHandler *value) { self.setOnCanplayThrough(value); };
        operator EventHandler *() { return self.getOnCanplayThrough(); };
    } oncanplaythrough{*this};

    struct {
        HTMLElement &self;
        void operator=(EventHandler *value) { self.setOnChange(value); };
        operator EventHandler *() { return self.getOnChange(); };
    } onchange{*this};

    struct {
        HTMLElement &self;
        void operator=(EventHandler *value) { self.setOnClick(value); };
        operator EventHandler *() { return self.getOnClick(); };
    } onclick{*this};

    struct {
        HTMLElement &self;
        void operator=(EventHandler *value) { self.setOnClose(value); };
        operator EventHandler *() { return self.getOnClose(); };
    } onclose{*this};

    struct {
        HTMLElement &self;
        void operator=(EventHandler *value) { self.setOnContextMenu(value); };
        operator EventHandler *() { return self.getOnContextMenu(); };
    } oncontextmenu{*this};

    struct {
        HTMLElement &self;
        void operator=(EventHandler *value) { self.setOnCueChange(value); };
        operator EventHandler *() { return self.getOnCueChange(); };
    } oncuechange{*this};

    struct {
        HTMLElement &self;
        void operator=(EventHandler *value) { self.setOnDoubleClick(value); };
        operator EventHandler *() { return self.getOnDoubleClick(); };
    } ondblclick{*this};

    struct {
        HTMLElement &self;
        void operator=(EventHandler *value) { self.setOnDrag(value); };
        operator EventHandler *() { return self.getOnDrag(); };
    } ondrag{*this};

    struct {
        HTMLElement &self;
        void operator=(EventHandler *value) { self.setOnDragEnd(value); };
        operator EventHandler *() { return self.getOnDragEnd(); };
    } ondragend{*this};

    struct {
        HTMLElement &self;
        void operator=(EventHandler *value) { self.setOnDragEnter(value); };
        operator EventHandler *() { return self.getOnDragEnter(); };
    } ondragendter{*this};

    struct {
        HTMLElement &self;
        void operator=(EventHandler *value) { self.setOnDragExit(value); };
        operator EventHandler *() { return self.getOnDragExit(); };
    } ondragexit{*this};

    struct {
        HTMLElement &self;
        void operator=(EventHandler *value) { self.setOnDragLeave(value); };
        operator EventHandler *() { return self.getOnDragLeave(); };
    } ondragleave{*this};

    struct {
        HTMLElement &self;
        void operator=(EventHandler *value) { self.setOnDragOver(value); };
        operator EventHandler *() { return self.getOnDragOver(); };
    } ondragover{*this};

    struct {
        HTMLElement &self;
        void operator=(EventHandler *value) { self.setOnDragStart(value); };
        operator EventHandler *() { return self.getOnDragStart(); };
    } ondragstart{*this};

    struct {
        HTMLElement &self;
        void operator=(EventHandler *value) { self.setOnDrop(value); };
        operator EventHandler *() { return self.getOnDrop(); };
    } ondrop{*this};

    struct {
        HTMLElement &self;
        void operator=(EventHandler *value) { self.setOnDurationChange(value); };
        operator EventHandler *() { return self.getOnDurationChange(); };
    } ondurationchange{*this};

    struct {
        HTMLElement &self;
        void operator=(EventHandler *value) { self.setOnEmptied(value); };
        operator EventHandler *() { return self.getOnEmptied(); };
    } onemptied{*this};

    struct {
        HTMLElement &self;
        void operator=(EventHandler *value) { self.setOnEnded(value); };
        operator EventHandler *() { return self.getOnEnded(); };
    } onended{*this};

    struct {
        HTMLElement &self;
        void operator=(OnErrorEventHandler *value) { self.setOnError(value); };
        operator OnErrorEventHandler *() { return self.getOnError(); };
    } onerror{*this};

    struct {
        HTMLElement &self;
        void operator=(EventHandler *value) { self.setOnFocus(value); };
        operator EventHandler *() { return self.getOnFocus(); };
    } onfocus{*this};

    struct {
        HTMLElement &self;
        void operator=(EventHandler *value) { self.setOnInput(value); };
        operator EventHandler *() { return self.getOnInput(); };
    } oninput{*this};

    struct {
        HTMLElement &self;
        void operator=(EventHandler *value) { self.setOnInvalid(value); };
        operator EventHandler *() { return self.getOnInvalid(); };
    } oninvalid{*this};

    struct {
        HTMLElement &self;
        void operator=(EventHandler *value) { self.setOnKeyDown(value); };
        operator EventHandler *() { return self.getOnKeyDown(); };
    } onkeydown{*this};

    struct {
        HTMLElement &self;
        void operator=(EventHandler *value) { self.setOnKeyPress(value); };
        operator EventHandler *() { return self.getOnKeyPress(); };
    } onkeypress{*this};

    struct {
        HTMLElement &self;
        void operator=(EventHandler *value) { self.setOnKeyUp(value); };
        operator EventHandler *() { return self.getOnKeyUp(); };
    } onkeyup{*this};

    struct {
        HTMLElement &self;
        void operator=(EventHandler *value) { self.setOnLoad(value); };
        operator EventHandler *() { return self.getOnLoad(); };
    } onload{*this};

    struct {
        HTMLElement &self;
        void operator=(EventHandler *value) { self.setOnLoadedData(value); };
        operator EventHandler *() { return self.getOnLoadedData(); };
    } onloadeddata{*this};

    struct {
        HTMLElement &self;
        void operator=(EventHandler *value) { self.setOnLoadedMetaData(value); };
        operator EventHandler *() { return self.getOnLoadedMetaData(); };
    } onloadedmetadata{*this};

    struct {
        HTMLElement &self;
        void operator=(EventHandler *value) { self.setOnLoadStart(value); };
        operator EventHandler *() { return self.getOnLoadStart(); };
    } onloadstart{*this};

    struct {
        HTMLElement &self;
        void operator=(EventHandler *value) { self.setOnMouseDown(value); };
        operator EventHandler *() { return self.getOnMouseDown(); };
    } onmousedown{*this};

    struct {
        HTMLElement &self;
        void operator=(EventHandler *value) { self.setOnMouseEnter(value); };
        operator EventHandler *() { return self.getOnMouseEnter(); };
    } onmouseenter{*this};

    struct {
        HTMLElement &self;
        void operator=(EventHandler *value) { self.setOnMouseLeave(value); };
        operator EventHandler *() { return self.getOnMouseLeave(); };
    } onmouseleave{*this};

    struct {
        HTMLElement &self;
        void operator=(EventHandler *value) { self.setOnMouseMove(value); };
        operator EventHandler *() { return self.getOnMouseMove(); };
    } onmousemove{*this};

    struct {
        HTMLElement &self;
        void operator=(EventHandler *value) { self.setOnMouseOut(value); };
        operator EventHandler *() { return self.getOnMouseOut(); };
    } onmouseout{*this};

    struct {
        HTMLElement &self;
        void operator=(EventHandler *value) { self.setOnMouseOver(value); };
        operator EventHandler *() { return self.getOnMouseOver(); };
    } onmouseover{*this};

    struct {
        HTMLElement &self;
        void operator=(EventHandler *value) { self.setOnMouseUp(value); };
        operator EventHandler *() { return self.getOnMouseUp(); };
    } onmouseup{*this};

    struct {
        HTMLElement &self;
        void operator=(EventHandler *value) { self.setOnMouseWheel(value); };
        operator EventHandler *() { return self.getOnMouseWheel(); };
    } onmousewheel{*this};

    struct {
        HTMLElement &self;
        void operator=(EventHandler *value) { self.setOnPause(value); };
        operator EventHandler *() { return self.getOnPause(); };
    } onpause{*this};

    struct {
        HTMLElement &self;
        void operator=(EventHandler *value) { self.setOnPlay(value); };
        operator EventHandler *() { return self.getOnPlay(); };
    } onplay{*this};

    struct {
        HTMLElement &self;
        void operator=(EventHandler *value) { self.setOnPlaying(value); };
        operator EventHandler *() { return self.getOnPlaying(); };
    } onplaying{*this};

    struct {
        HTMLElement &self;
        void operator=(EventHandler *value) { self.setOnProgress(value); };
        operator EventHandler *() { return self.getOnProgress(); };
    } onprogress{*this};

    struct {
        HTMLElement &self;
        void operator=(EventHandler *value) { self.setOnRateChange(value); };
        operator EventHandler *() { return self.getOnRateChange(); };
    } onratechange{*this};

    struct {
        HTMLElement &self;
        void operator=(EventHandler *value) { self.setOnReset(value); };
        operator EventHandler *() { return self.getOnReset(); };
    } onreset{*this};

    struct {
        HTMLElement &self;
        void operator=(EventHandler *value) { self.setOnResize(value); };
        operator EventHandler *() { return self.getOnResize(); };
    } onresize{*this};

    struct {
        HTMLElement &self;
        void operator=(EventHandler *value) { self.setOnScroll(value); };
        operator EventHandler *() { return self.getOnScroll(); };
    } onscroll{*this};

    struct {
        HTMLElement &self;
        void operator=(EventHandler *value) { self.setOnSeeked(value); };
        operator EventHandler *() { return self.getOnSeeked(); };
    } onseeked{*this};

    struct {
        HTMLElement &self;
        void operator=(EventHandler *value) { self.setOnSeeking(value); };
        operator EventHandler *() { return self.getOnSeeking(); };
    } onseeking{*this};

    struct {
        HTMLElement &self;
        void operator=(EventHandler *value) { self.setOnSelect(value); };
        operator EventHandler *() { return self.getOnSelect(); };
    } onselect{*this};

    struct {
        HTMLElement &self;
        void operator=(EventHandler *value) { self.setOnShow(value); };
        operator EventHandler *() { return self.getOnShow(); };
    } onshow{*this};

    struct {
        HTMLElement &self;
        void operator=(EventHandler *value) { self.setOnSort(value); };
        operator EventHandler *() { return self.getOnSort(); };
    } onsort{*this};

    struct {
        HTMLElement &self;
        void operator=(EventHandler *value) { self.setOnStalled(value); };
        operator EventHandler *() { return self.getOnStalled(); };
    } onstalled{*this};

    struct {
        HTMLElement &self;
        void operator=(EventHandler *value) { self.setOnSubmit(value); };
        operator EventHandler *() { return self.getOnSubmit(); };
    } onsubmit{*this};

    struct {
        HTMLElement &self;
        void operator=(EventHandler *value) { self.setOnSuspend(value); };
        operator EventHandler *() { return self.getOnSuspend(); };
    } onsuspend{*this};

    struct {
        HTMLElement &self;
        void operator=(EventHandler *value) { self.setOnTimeUpdate(value); };
        operator EventHandler *() { return self.getOnTimeUpdate(); };
    } ontimeupdate{*this};

    struct {
        HTMLElement &self;
        void operator=(EventHandler *value) { self.setOnToggle(value); };
        operator EventHandler *() { return self.getOnToggle(); };
    } ontoggle{*this};

    struct {
        HTMLElement &self;
        void operator=(EventHandler *value) { self.setOnVolumeChange(value); };
        operator EventHandler *() { return self.getOnVolumeChange(); };
    } onvolumechange{*this};

    struct {
        HTMLElement &self;
        void operator=(EventHandler *value) { self.setOnWaiting(value); };
        operator EventHandler *() { return self.getOnWaiting(); };
    } onwaiting{*this};

    struct {
        HTMLElement &self;
        void operator=(HTMLPropertiesCollection *value) { self.setProperties(value); };
        operator HTMLPropertiesCollection *() { return self.getProperties(); };
    } properties{*this};

    struct {
        HTMLElement &self;
        void operator=(bool value) { self.setSpellCheck(value); };
        operator bool() { return self.getSpellCheck(); };
    } spellcheck{*this};

    struct {
        HTMLElement &self;
        void operator=(CSSStyleDeclaration *value) { self.setStyle(value); };
        operator CSSStyleDeclaration *() { return self.getStyle(); };
    } style{*this};

    struct {
        HTMLElement &self;
        void operator=(long value) { self.setTabIndex(value); };
        operator long() { return self.getTabIndex(); };
    } tabIndex{*this};

    struct {
        HTMLElement &self;
        void operator=(std::string value) { self.setTitle(value); };
        operator std::string() { return self.getTitle(); };
    } title{*this};

    struct {
        HTMLElement &self;
        void operator=(bool value) { self.setTranslate(value); };
        operator bool() { return self.getTranslate(); };
    } translate{*this};

    std::string getAccessKey() const;
    void setAccessKey(std::string value);
    std::string getAccessKeyLabel() const;
    void setAccessKeyLabel(std::string value);
    bool getCommandChecked() const;
    void setCommandChecked(bool value);
    bool getCommandDisabled() const;
    void setCommandDisabled(bool value);
    bool getCommandHidden() const;
    void setCommandHidden(bool value);
    std::string getCommandIcon() const;
    void setCommandIcon(std::string value);
    std::string getCommandLabel() const;
    void setCommandLabel(std::string value);
    std::string getCommandType() const;
    void setCommandType(std::string value);
    std::string getContentEditable() const;
    void setContentEditable(std::string value);
    HTMLMenuElement *getContextMenu() const;
    void setContextMenu(HTMLMenuElement *value);
    DOMStringMap *getDataSet() const;
    void setDataSet(DOMStringMap *value);
    std::string getDir() const;
    void setDir(std::string value);
    bool getDraggable() const;
    void setDraggable(bool value);
    DOMSettableTokenList *getDropzone() const;
    void setDropzone(DOMSettableTokenList *value);
    bool getHidden() const;
    void setHidden(bool value);
    bool getIsContentEditable() const;
    void setIsContentEditable(bool value);
    std::string getItemId() const;
    void setItemId(std::string value);
    DOMSettableTokenList *getItemProp() const;
    void setItemProp(DOMSettableTokenList *value);
    DOMSettableTokenList *getItemRef() const;
    void setItemRef(DOMSettableTokenList *value);
    bool getItemScope() const;
    void setItemScope(bool value);
    DOMSettableTokenList *getItemType() const;
    void setItemType(DOMSettableTokenList *value);
    void *getItemValue() const;
    void setItemValue(void *value);
    std::string getLang() const;
    void setLang(std::string value);
    EventHandler *getOnAbort() const;
    void setOnAbort(EventHandler *value);
    void onAbortCallback(emscripten::val e);
    EventHandler *getOnAutoComplete() const;
    void setOnAutoComplete(EventHandler *value);
    void onAutoCompleteCallback(emscripten::val e);
    EventHandler *getOnAutoCompleteError() const;
    void setOnAutoCompleteError(EventHandler *value);
    void onAutoCompleteErrorCallback(emscripten::val e);
    EventHandler *getOnBlur() const;
    void setOnBlur(EventHandler *value);
    void onBlurCallback(emscripten::val e);
    EventHandler *getOnCancel() const;
    void setOnCancel(EventHandler *value);
    void onCancelCallback(emscripten::val e);
    EventHandler *getOnCanplay() const;
    void setOnCanplay(EventHandler *value);
    void onCanplayCallback(emscripten::val e);
    EventHandler *getOnCanplayThrough() const;
    void setOnCanplayThrough(EventHandler *value);
    void onCanplayThroughCallback(emscripten::val e);
    EventHandler *getOnChange() const;
    void setOnChange(EventHandler *value);
    void onChangeCallback(emscripten::val e);
    EventHandler *getOnClick() const;
    void setOnClick(EventHandler *value);
    void onClickCallback(emscripten::val e);
    EventHandler *getOnClose() const;
    void setOnClose(EventHandler *value);
    void onCloseCallback(emscripten::val e);
    EventHandler *getOnContextMenu() const;
    void setOnContextMenu(EventHandler *value);
    void onContextMenuCallback(emscripten::val e);
    EventHandler *getOnCueChange() const;
    void setOnCueChange(EventHandler *value);
    void onCueChangeCallback(emscripten::val e);
    EventHandler *getOnDoubleClick() const;
    void setOnDoubleClick(EventHandler *value);
    void onDoubleClickCallback(emscripten::val e);
    EventHandler *getOnDrag() const;
    void setOnDrag(EventHandler *value);
    void onDragCallback(emscripten::val e);
    EventHandler *getOnDragEnd() const;
    void setOnDragEnd(EventHandler *value);
    void onDragEndCallback(emscripten::val e);
    EventHandler *getOnDragEnter() const;
    void setOnDragEnter(EventHandler *value);
    void onDragEnterCallback(emscripten::val e);
    EventHandler *getOnDragExit() const;
    void setOnDragExit(EventHandler *value);
    void onDragExitCallback(emscripten::val e);
    EventHandler *getOnDragLeave() const;
    void setOnDragLeave(EventHandler *value);
    void onDragLeaveCallback(emscripten::val e);
    EventHandler *getOnDragOver() const;
    void setOnDragOver(EventHandler *value);
    void onDragOverCallback(emscripten::val e);
    EventHandler *getOnDragStart() const;
    void setOnDragStart(EventHandler *value);
    void onDragStartCallback(emscripten::val e);
    EventHandler *getOnDrop() const;
    void setOnDrop(EventHandler *value);
    void onDropCallback(emscripten::val e);
    EventHandler *getOnDurationChange() const;
    void setOnDurationChange(EventHandler *value);
    void onDurationChangeCallback(emscripten::val e);
    EventHandler *getOnEmptied() const;
    void setOnEmptied(EventHandler *value);
    void onEmptiedCallback(emscripten::val e);
    EventHandler *getOnEnded() const;
    void setOnEnded(EventHandler *value);
    void onEndedCallback(emscripten::val e);
    OnErrorEventHandler *getOnError() const;
    void setOnError(OnErrorEventHandler *value);
    void onErrorCallback(emscripten::val e, std::string source, unsigned long lineno, unsigned long colno, emscripten::val error);
    EventHandler *getOnFocus() const;
    void setOnFocus(EventHandler *value);
    void onFocusCallback(emscripten::val e);
    EventHandler *getOnInput() const;
    void setOnInput(EventHandler *value);
    void onInputCallback(emscripten::val e);
    EventHandler *getOnInvalid() const;
    void setOnInvalid(EventHandler *value);
    void onInvalidCallback(emscripten::val e);
    EventHandler *getOnKeyDown() const;
    void setOnKeyDown(EventHandler *value);
    void onKeyDownCallback(emscripten::val e);
    EventHandler *getOnKeyPress() const;
    void setOnKeyPress(EventHandler *value);
    void onKeyPressCallback(emscripten::val e);
    EventHandler *getOnKeyUp() const;
    void setOnKeyUp(EventHandler *value);
    void onKeyUpCallback(emscripten::val e);
    EventHandler *getOnLoad() const;
    void setOnLoad(EventHandler *value);
    void onLoadCallback(emscripten::val e);
    EventHandler *getOnLoadedData() const;
    void setOnLoadedData(EventHandler *value);
    void onLoadedDataCallback(emscripten::val e);
    EventHandler *getOnLoadedMetaData() const;
    void setOnLoadedMetaData(EventHandler *value);
    void onLoadedMetaDataCallback(emscripten::val e);
    EventHandler *getOnLoadStart() const;
    void setOnLoadStart(EventHandler *value);
    void onLoadStartCallback(emscripten::val e);
    EventHandler *getOnMouseDown() const;
    void setOnMouseDown(EventHandler *value);
    void onMouseDownCallback(emscripten::val e);
    EventHandler *getOnMouseEnter() const;
    void setOnMouseEnter(EventHandler *value);
    void onMouseEnterCallback(emscripten::val e);
    EventHandler *getOnMouseLeave() const;
    void setOnMouseLeave(EventHandler *value);
    void onMouseLeaveCallback(emscripten::val e);
    EventHandler *getOnMouseMove() const;
    void setOnMouseMove(EventHandler *value);
    void onMouseMoveCallback(emscripten::val e);
    EventHandler *getOnMouseOut() const;
    void setOnMouseOut(EventHandler *value);
    void onMouseOutCallback(emscripten::val e);
    EventHandler *getOnMouseOver() const;
    void setOnMouseOver(EventHandler *value);
    void onMouseOverCallback(emscripten::val e);
    EventHandler *getOnMouseUp() const;
    void setOnMouseUp(EventHandler *value);
    void onMouseUpCallback(emscripten::val e);
    EventHandler *getOnMouseWheel() const;
    void setOnMouseWheel(EventHandler *value);
    void onMouseWheelCallback(emscripten::val e);
    EventHandler *getOnPause() const;
    void setOnPause(EventHandler *value);
    void onPauseCallback(emscripten::val e);
    EventHandler *getOnPlay() const;
    void setOnPlay(EventHandler *value);
    void onPlayCallback(emscripten::val e);
    EventHandler *getOnPlaying() const;
    void setOnPlaying(EventHandler *value);
    void onPlayingCallback(emscripten::val e);
    EventHandler *getOnProgress() const;
    void setOnProgress(EventHandler *value);
    void onProgressCallback(emscripten::val e);
    EventHandler *getOnRateChange() const;    
    void setOnRateChange(EventHandler *value);
    void onRateChangeCallback(emscripten::val e);
    EventHandler *getOnReset() const;
    void setOnReset(EventHandler *value);
    void onResetCallback(emscripten::val e);
    EventHandler *getOnResize() const;
    void setOnResize(EventHandler *value);
    void onResizeCallback(emscripten::val e);
    EventHandler *getOnScroll() const;
    void setOnScroll(EventHandler *value);
    void onScrollCallback(emscripten::val e);
    EventHandler *getOnSeeked() const;
    void setOnSeeked(EventHandler *value);
    void onSeekedCallback(emscripten::val e);
    EventHandler *getOnSeeking() const;
    void setOnSeeking(EventHandler *value);
    void onSeekingCallback(emscripten::val e);
    EventHandler *getOnSelect() const;
    void setOnSelect(EventHandler *value);
    void onSelectCallback(emscripten::val e);
    EventHandler *getOnShow() const;
    void setOnShow(EventHandler *value);
    void onShowCallback(emscripten::val e);
    EventHandler *getOnSort() const;
    void setOnSort(EventHandler *value);
    void onSortCallback(emscripten::val e);
    EventHandler *getOnStalled() const;
    void setOnStalled(EventHandler *value);
    void onStalledCallback(emscripten::val e);
    EventHandler *getOnSubmit() const;
    void setOnSubmit(EventHandler *value);
    void onSubmitCallback(emscripten::val e);
    EventHandler *getOnSuspend() const;
    void setOnSuspend(EventHandler *value);
    void onSuspendCallback(emscripten::val e);
    EventHandler *getOnTimeUpdate() const;
    void setOnTimeUpdate(EventHandler *value);
    void onTimeUpdateCallback(emscripten::val e);
    EventHandler *getOnToggle() const;
    void setOnToggle(EventHandler *value);
    void onToggleCallback(emscripten::val e);
    EventHandler *getOnVolumeChange() const;
    void setOnVolumeChange(EventHandler *value);
    void onVolumeChangeCallback(emscripten::val e);
    EventHandler *getOnWaiting() const;
    void setOnWaiting(EventHandler *value);
    void onWaitingCallback(emscripten::val e);
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
};
