#pragma once

#include "libhtml5.h"
#include "node.h"

class Element;
class HTMLElement;
class HTMLCollection;
class DOMElementMap;
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
class ProcessingIstruction;
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
    HTMLElement *_body;
    std::string _characterSet;
    unsigned long _childElementCount;
    HTMLCollection *_children;
    HTMLCollection *_commands;
    std::string _compatMode;
    std::string _contentType;
    std::string _cookie;
    DOMElementMap *_cssElementMap;
    HTMLScriptElement *_currentScript;
    WindowProxy *_defaultView;
    std::string _designMode;
    std::string _dir;
    DocumentType *_doctype;
    Element *_documentElement;
    std::string _documentURI;
    std::string _domain;
    HTMLCollection *_embeds;
    Element *_firstElementChild;
    HTMLCollection *_forms;
    Element *_fullScreenElement;
    bool _fullScreenEnabled;
    HTMLHeadElement *_head;
    HTMLCollection *_images;
    DOMImplementation *_implementation;
    Element *_lastElementChild;
    std::string _lastModified;
    std::string _lastStyleSheetSet;
    HTMLCollection *_links;
    Location *_location;
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
    EventHandler *_onpointerlockchange;
    EventHandler *_onpointerlockerror;
    EventHandler *_onprogress;
    EventHandler *_onratechange;
    EventHandler *_onreadystatechange;
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
    std::string _origin;
    HTMLCollection *_plugins;
    Element *_pointerLockElement;
    std::string _preferredStyleSheetSet;
    DocumentReadyState readyState;
    std::string _referrer;
    HTMLCollection *_scripts;
    std::string _selectedStyleSheetSet;
    StyleSheetList *_styleSheets;
    std::vector<std::string> _styleSheetSets;
    std::string _title;
    std::string _URL;

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
    ProcessingIstruction *createProcessingInstruction(std::string target, std::string data);
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

    HTMLElement *getBody() const;
    void setBody(HTMLElement *value);

    struct {
        Document &self;
        void operator=(HTMLElement *value) { self.setBody(value); };
        operator HTMLElement *() { return self.getBody(); };
        HTMLElement *operator->() { return self.getBody(); };
    } body{*this};
};
