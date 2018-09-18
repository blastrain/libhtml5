#pragma once

#include "libhtml5.h"
#include "node.h"

class Element;
class HTMLElement;
class HTMLCollection;
class HTMLScriptElement;
class WindowProxy;
class DocumentType;
class HTMLHeadElement;
class DOMImplementation;
class Location;
class StyleSheetList;
class Comment;
class DocumentFragment;
class NodeIterator;
class ProcessingInstruction;
class Range;
class Text;
class TreeWalker;
class NodeList;
class Event;
class NodeFilter;

enum class DocumentReadyState {
    LOADING,
    INTERACTIVE,
    COMPLETE,
};

class Document : public Node {
public:

    HTML5_PROPERTY_OBJECT(Document, HTMLElement, body);
    HTML5_PROPERTY(Document, std::string, characterSet);
    HTML5_PROPERTY(Document, unsigned long, childElementCount);
    HTML5_PROPERTY_OBJECT(Document, HTMLCollection, children);
    HTML5_PROPERTY_OBJECT(Document, HTMLCollection, commands);
    HTML5_PROPERTY(Document, std::string, compatMode);
    HTML5_PROPERTY(Document, std::string, contentType);
    HTML5_PROPERTY(Document, std::string, cookie);
    HTML5_PROPERTY_OBJECT(Document, HTMLScriptElement, currentScript);
    HTML5_PROPERTY_OBJECT(Document, WindowProxy, defaultView);
    HTML5_PROPERTY(Document, std::string, designMode);
    HTML5_PROPERTY(Document, std::string, dir)
    HTML5_PROPERTY_OBJECT(Document, DocumentType, doctype);
    HTML5_PROPERTY_OBJECT(Document, Element, documentElement);
    HTML5_PROPERTY(Document, std::string, documentURI);
    HTML5_PROPERTY(Document, std::string, domain);
    HTML5_PROPERTY_OBJECT(Document, HTMLCollection, embeds);
    HTML5_PROPERTY_OBJECT(Document, Element, firstElementChild);
    HTML5_PROPERTY_OBJECT(Document, HTMLCollection, forms);
    HTML5_PROPERTY_OBJECT(Document, Element, fullScreenElement);
    HTML5_PROPERTY(Document, bool, fullScreenEnabled);
    HTML5_PROPERTY_OBJECT(Document, HTMLHeadElement, head);
    HTML5_PROPERTY_OBJECT(Document, HTMLCollection, images);
    HTML5_PROPERTY_OBJECT(Document, DOMImplementation, implementation);
    HTML5_PROPERTY_OBJECT(Document, Element, lastElementChild);
    HTML5_PROPERTY(Document, std::string, lastModified);
    HTML5_PROPERTY(Document, std::string, lastStyleSheetSet);
    HTML5_PROPERTY_OBJECT(Document, HTMLCollection, links);
    HTML5_PROPERTY_OBJECT(Document, Location, location);
    HTML5_EVENT_HANDLER_PROPERTY(Document, EventHandler *, onabort);
    HTML5_EVENT_HANDLER_PROPERTY(Document, EventHandler *, onautocomplete);
    HTML5_EVENT_HANDLER_PROPERTY(Document, EventHandler *, onautocompleteerror);
    HTML5_EVENT_HANDLER_PROPERTY(Document, EventHandler *, onblur);
    HTML5_EVENT_HANDLER_PROPERTY(Document, EventHandler *, oncancel);
    HTML5_EVENT_HANDLER_PROPERTY(Document, EventHandler *, oncanplay);
    HTML5_EVENT_HANDLER_PROPERTY(Document, EventHandler *, oncanplaythrough);
    HTML5_EVENT_HANDLER_PROPERTY(Document, EventHandler *, onchange);
    HTML5_EVENT_HANDLER_PROPERTY(Document, EventHandler *, onclick);
    HTML5_EVENT_HANDLER_PROPERTY(Document, EventHandler *, onclose);
    HTML5_EVENT_HANDLER_PROPERTY(Document, EventHandler *, oncontextmenu);
    HTML5_EVENT_HANDLER_PROPERTY(Document, EventHandler *, oncuechange);
    HTML5_EVENT_HANDLER_PROPERTY(Document, EventHandler *, ondblclick);
    HTML5_EVENT_HANDLER_PROPERTY(Document, EventHandler *, ondrag);
    HTML5_EVENT_HANDLER_PROPERTY(Document, EventHandler *, ondragend);
    HTML5_EVENT_HANDLER_PROPERTY(Document, EventHandler *, ondragenter);
    HTML5_EVENT_HANDLER_PROPERTY(Document, EventHandler *, ondragexit);
    HTML5_EVENT_HANDLER_PROPERTY(Document, EventHandler *, ondragleave);
    HTML5_EVENT_HANDLER_PROPERTY(Document, EventHandler *, ondragover);
    HTML5_EVENT_HANDLER_PROPERTY(Document, EventHandler *, ondragstart);
    HTML5_EVENT_HANDLER_PROPERTY(Document, EventHandler *, ondrop);
    HTML5_EVENT_HANDLER_PROPERTY(Document, EventHandler *, ondurationchange);
    HTML5_EVENT_HANDLER_PROPERTY(Document, EventHandler *, onemptied);
    HTML5_EVENT_HANDLER_PROPERTY(Document, EventHandler *, onended);
    HTML5_ERROR_HANDLER_PROPERTY(Document, OnErrorEventHandler *, onerror);
    HTML5_EVENT_HANDLER_PROPERTY(Document, EventHandler *, onfocus);
    HTML5_EVENT_HANDLER_PROPERTY(Document, EventHandler *, oninput);
    HTML5_EVENT_HANDLER_PROPERTY(Document, EventHandler *, oninvalid);
    HTML5_EVENT_HANDLER_PROPERTY(Document, EventHandler *, onkeydown);
    HTML5_EVENT_HANDLER_PROPERTY(Document, EventHandler *, onkeypress);
    HTML5_EVENT_HANDLER_PROPERTY(Document, EventHandler *, onkeyup);
    HTML5_EVENT_HANDLER_PROPERTY(Document, EventHandler *, onload);
    HTML5_EVENT_HANDLER_PROPERTY(Document, EventHandler *, onloadeddata);
    HTML5_EVENT_HANDLER_PROPERTY(Document, EventHandler *, onloadedmetadata);
    HTML5_EVENT_HANDLER_PROPERTY(Document, EventHandler *, onloadstart);
    HTML5_EVENT_HANDLER_PROPERTY(Document, EventHandler *, onmousedown);
    HTML5_EVENT_HANDLER_PROPERTY(Document, EventHandler *, onmouseenter);
    HTML5_EVENT_HANDLER_PROPERTY(Document, EventHandler *, onmouseleave);
    HTML5_EVENT_HANDLER_PROPERTY(Document, EventHandler *, onmousemove);
    HTML5_EVENT_HANDLER_PROPERTY(Document, EventHandler *, onmouseout);
    HTML5_EVENT_HANDLER_PROPERTY(Document, EventHandler *, onmouseover);
    HTML5_EVENT_HANDLER_PROPERTY(Document, EventHandler *, onmouseup);
    HTML5_EVENT_HANDLER_PROPERTY(Document, EventHandler *, onmousewheel);
    HTML5_EVENT_HANDLER_PROPERTY(Document, EventHandler *, onpause);
    HTML5_EVENT_HANDLER_PROPERTY(Document, EventHandler *, onplay);
    HTML5_EVENT_HANDLER_PROPERTY(Document, EventHandler *, onplaying);
    HTML5_EVENT_HANDLER_PROPERTY(Document, EventHandler *, onpointerlockchange);
    HTML5_EVENT_HANDLER_PROPERTY(Document, EventHandler *, onpointerlockerror);
    HTML5_EVENT_HANDLER_PROPERTY(Document, EventHandler *, onprogress);
    HTML5_EVENT_HANDLER_PROPERTY(Document, EventHandler *, onratechange);
    HTML5_EVENT_HANDLER_PROPERTY(Document, EventHandler *, onreadystatechange);
    HTML5_EVENT_HANDLER_PROPERTY(Document, EventHandler *, onreset);
    HTML5_EVENT_HANDLER_PROPERTY(Document, EventHandler *, onresize);
    HTML5_EVENT_HANDLER_PROPERTY(Document, EventHandler *, onscroll);
    HTML5_EVENT_HANDLER_PROPERTY(Document, EventHandler *, onseeked);
    HTML5_EVENT_HANDLER_PROPERTY(Document, EventHandler *, onseeking);
    HTML5_EVENT_HANDLER_PROPERTY(Document, EventHandler *, onselect);
    HTML5_EVENT_HANDLER_PROPERTY(Document, EventHandler *, onshow);
    HTML5_EVENT_HANDLER_PROPERTY(Document, EventHandler *, onsort);
    HTML5_EVENT_HANDLER_PROPERTY(Document, EventHandler *, onstalled);
    HTML5_EVENT_HANDLER_PROPERTY(Document, EventHandler *, onsubmit);
    HTML5_EVENT_HANDLER_PROPERTY(Document, EventHandler *, onsuspend);
    HTML5_EVENT_HANDLER_PROPERTY(Document, EventHandler *, ontimeupdate);
    HTML5_EVENT_HANDLER_PROPERTY(Document, EventHandler *, ontoggle);
    HTML5_EVENT_HANDLER_PROPERTY(Document, EventHandler *, onvolumechange);
    HTML5_EVENT_HANDLER_PROPERTY(Document, EventHandler *, onwaiting);
    HTML5_PROPERTY(Document, std::string, origin);
    HTML5_PROPERTY_OBJECT(Document, HTMLCollection, plugins);
    HTML5_PROPERTY_OBJECT(Document, Element, pointerLockElement);
    HTML5_PROPERTY(Document, std::string, preferredStyleSheetSet);
    HTML5_PROPERTY(Document, std::string, referrer);
    HTML5_PROPERTY(Document, std::string, selectedStyleSheetSet);
    HTML5_PROPERTY(Document, std::string, title);
    HTML5_PROPERTY(Document, std::string, URL);
    HTML5_PROPERTY_OBJECT(Document, HTMLCollection, scripts);
    HTML5_PROPERTY_OBJECT(Document, StyleSheetList, styleSheets);
    DocumentReadyState _readyState;
    std::vector<std::string> _styleSheetSets;

    Document(emscripten::val v);
    ~Document();
    static Document *create();
    static Document *create(emscripten::val v);
    Node *adoptNode(Node *node);
    template<typename... Args> void append(Node *node, Args ...args) {
        std::vector<Node *> nodes = { args... };
        nodes.insert(nodes.begin(), node);
        append(nodes);
    };
    void append(std::vector<Node *> nodes);
    void close();
    Comment *createComment(std::string data);
    DocumentFragment *createDocumentFragment();
    Element *createElement(std::string localName);
    Element *createElementNS(std::string _namespace, std::string qualifiedName);
    Event *createEvent(std::string interface);
    NodeIterator *createNodeIterator(Node *root, unsigned long whatToShow, NodeFilter *filter);
    ProcessingInstruction *createProcessingInstruction(std::string target, std::string data);
    Range *createRange();
    Text *createTextNode(std::string data);
    TreeWalker *createTreeWalker(Node *root, unsigned long whatToShow, NodeFilter *filter);
    void enableStyleSheetsForSet(std::string name);
    bool execCommand(std::string commandId, bool showUI, std::string value);
    void exitFullscreen();
    void exitPointerLock();
    Element *getElementById(std::string elementId);
    HTMLCollection *getElementsByClassName(std::string classNames);
    NodeList *getElementsByName(std::string elementName);
    HTMLCollection *getElementsByTagName(std::string localName);
    HTMLCollection *getElementsByTagNameNS(std::string _namespace, std::string localName);
    NodeList *getItems(std::string typeNames);
    void *getter(std::string name);
    bool hasFocus();
    Node *importNode(Node *node, bool deep);
    Document *open(std::string typeURL, std::string replaceName, std::string features, bool replace);
    template<typename... Args> void prepend(Node *node, Args ...args) {
        std::vector<Node *> nodes = { args... };
        nodes.insert(nodes.begin(), node);
        prepend(nodes);
    };
    void prepend(std::vector<Node *> nodes);
    Element *query(std::string relativeSelectors);
    std::vector<Element *> queryAll(std::string relativeSelectors);
    bool queryCommandEnabled(std::string commandId);
    bool queryCommandIndeterm(std::string commandId);
    bool queryCommandState(std::string commandId);
    bool queryCommandSupported(std::string commandId);
    std::string queryCommandValue(std::string commandId);
    Element *querySelector(std::string selectors);
    NodeList *querySelectorAll(std::string selectors);
    template<typename... Args> void write(std::string text, Args ...args) {
        std::vector<std::string> texts = { args... };
        texts.insert(texts.begin(), text);
        write(texts);
    };
    void write(std::vector<std::string> texts);
    template<typename... Args> void writeln(std::string text, Args ...args) {
        std::vector<std::string> texts = { args... };
        texts.insert(texts.begin(), text);
        writeln(texts);
    };
    void writeln(std::vector<std::string> texts);
};
