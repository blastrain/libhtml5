#include "html_element.h"
#include "html_collection.h"
#include "html_script_element.h"
#include "window.h"
#include "document_type.h"
#include "html_head_element.h"
#include "dom_implementation.h"
#include "location.h"
#include "style_sheet_list.h"
#include "comment.h"
#include "document_fragment.h"
#include "node_iterator.h"
#include "processing_instruction.h"
#include "range.h"
#include "text.h"
#include "tree_walker.h"
#include "node_list.h"
#include "event.h"
#include "node_filter.h"
#include "document.h"
#include <iostream>

Document::Document(emscripten::val v) :
    Node(v)
{

}

Document::~Document()
{

}

Document *Document::create(emscripten::val v)
{
    Document *doc = new Document(v);
    doc->autorelease();
    return doc;
}

Document *Document::create()
{
    return create(HTML5_STATIC_PRIMITIVE_INSTANCE(document));
}

Node *Document::adoptNode(Node *node)
{
    return Node::create(HTML5_CALLv(this->v, adoptNode, node->v));
}

void Document::append(std::vector<Node *> nodes)
{
    for (Node *node : nodes) {
        HTML5_CALL(this->v, append, node->v);
    }
}

void Document::close()
{
    HTML5_CALL(this->v, close);
}

Comment *Document::createComment(std::string data)
{
    return Comment::create(HTML5_CALLv(this->v, createComment, data));
}

DocumentFragment *Document::createDocumentFragment()
{
    return DocumentFragment::create(HTML5_CALLv(this->v, createDocumentFragment));
}

Element *Document::createElement(std::string localName)
{
    return Element::create(HTML5_CALLv(this->v, createElement, localName));
}

Element *Document::createElementNS(std::string _namespace, std::string qualifiedName)
{
    return Element::create(HTML5_CALLv(this->v, createElementNS, _namespace, qualifiedName));
}

Event *Document::createEvent(std::string interface)
{
    return Event::create(HTML5_CALLv(this->v, createEvent, interface));
}

NodeIterator *Document::createNodeIterator(Node *root, unsigned long whatToShow, NodeFilter *filter)
{
    return NodeIterator::create(HTML5_CALLv(this->v, createNodeIterator, root->v, whatToShow, filter->v));
}

ProcessingInstruction *Document::createProcessingInstruction(std::string target, std::string data)
{
    return ProcessingInstruction::create(HTML5_CALLv(this->v, createProcessingInstruction, target, data));
}

Range *Document::createRange()
{
    return Range::create(HTML5_CALLv(this->v, createRange));
}

Text *Document::createTextNode(std::string data)
{
    return Text::create(HTML5_CALLv(this->v, createTextNode, data));
}

TreeWalker *Document::createTreeWalker(Node *root, unsigned long whatToShow, NodeFilter *filter)
{
    return TreeWalker::create(HTML5_CALLv(this->v, createTreeWalker, root->v, whatToShow, filter->v));
}

void Document::enableStyleSheetsForSet(std::string name)
{
    HTML5_CALL(this->v, enableStyleSheetsForSet, name);
}

bool Document::execCommand(std::string commandId, bool showUI, std::string value)
{
    return HTML5_CALLb(this->v, execCommand, commandId, showUI, value);
}

void Document::exitFullscreen()
{
    HTML5_CALL(this->v, exitFullscreen);
}

void Document::exitPointerLock()
{
    HTML5_CALL(this->v, exitPointerLock);
}
    
Element *Document::getElementById(std::string elementId)
{
    return Element::create(HTML5_CALLv(this->v, getElementById, elementId));
}

HTMLCollection *Document::getElementsByClassName(std::string classNames)
{
    return HTMLCollection::create(HTML5_CALLv(this->v, getElementsByClassName, classNames));
}

NodeList *Document::getElementsByName(std::string elementName)
{
    return NodeList::create(HTML5_CALLv(this->v, getElementsByName, elementName));
}

HTMLCollection *Document::getElementsByTagName(std::string localName)
{
    return HTMLCollection::create(HTML5_CALLv(this->v, getElementsByTagName, localName));
}

HTMLCollection *Document::getElementsByTagNameNS(std::string _namespace, std::string localName)
{
    return HTMLCollection::create(HTML5_CALLv(this->v, getElementsByTagNameNS, _namespace, localName));
}

NodeList *Document::getItems(std::string typeNames)
{
    return NodeList::create(HTML5_CALLv(this->v, getItems, typeNames));
}

void *Document::getter(std::string name)
{
    HTML5_CALLv(this->v, getter, name);
    return NULL;
}

bool Document::hasFocus()
{
    return HTML5_CALLb(this->v, hasFocus);
}

Node *Document::importNode(Node *node, bool deep)
{
    return Node::create(HTML5_CALLv(this->v, importNode, node->v, deep));
}

Document *Document::open(std::string typeURL, std::string replaceName, std::string features, bool replace)
{
    return Document::create(HTML5_CALLv(this->v, typeURL, replaceName, features, replace));
}

void Document::prepend(std::vector<Node *> nodes)
{
    for (Node *node : nodes) {
        HTML5_CALL(this->v, prepend, node->v);
    }
}
    
Element *Document::query(std::string relativeSelectors)
{
    return Element::create(HTML5_CALLv(this->v, query, relativeSelectors));
}

std::vector<Element *> Document::queryAll(std::string relativeSelectors)
{
    return toObjectArray<Element>(HTML5_CALLv(this->v, queryAll, relativeSelectors));
}

bool Document::queryCommandEnabled(std::string commandId)
{
    return HTML5_CALLb(this->v, queryCommandEnabled, commandId);
}

bool Document::queryCommandIndeterm(std::string commandId)
{
    return HTML5_CALLb(this->v, queryCommandIndeterm, commandId);
}

bool Document::queryCommandState(std::string commandId)
{
    return HTML5_CALLb(this->v, queryCommandState, commandId);
}

bool Document::queryCommandSupported(std::string commandId)
{
    return HTML5_CALLb(this->v, queryCommandSupported, commandId);
}

std::string Document::queryCommandValue(std::string commandId)
{
    return HTML5_CALLs(this->v, queryCommandValue, commandId);
}

Element *Document::querySelector(std::string selectors)
{
    return Element::create(HTML5_CALLv(this->v, querySelector, selectors));
}

NodeList *Document::querySelectorAll(std::string selectors)
{
    return NodeList::create(HTML5_CALLv(this->v, querySelectorAll, selectors));
}

void Document::write(std::vector<std::string> texts)
{
    HTML5_CALL(this->v, write, toJSArray<std::string>(texts));
}

void Document::writeln(std::vector<std::string> texts)
{
    HTML5_CALL(this->v, writeln, toJSArray<std::string>(texts));
}

HTML5_PROPERTY_OBJECT_IMPL(Document, HTMLElement, body);
HTML5_PROPERTY_IMPL(Document, std::string, characterSet);
HTML5_PROPERTY_IMPL(Document, unsigned long, childElementCount);
HTML5_PROPERTY_OBJECT_IMPL(Document, HTMLCollection, children);
HTML5_PROPERTY_OBJECT_IMPL(Document, HTMLCollection, commands);
HTML5_PROPERTY_IMPL(Document, std::string, compatMode);
HTML5_PROPERTY_IMPL(Document, std::string, contentType);
HTML5_PROPERTY_IMPL(Document, std::string, cookie);
HTML5_PROPERTY_OBJECT_IMPL(Document, HTMLScriptElement, currentScript);
HTML5_PROPERTY_OBJECT_IMPL(Document, WindowProxy, defaultView);
HTML5_PROPERTY_IMPL(Document, std::string, designMode);
HTML5_PROPERTY_IMPL(Document, std::string, dir)
HTML5_PROPERTY_OBJECT_IMPL(Document, DocumentType, doctype);
HTML5_PROPERTY_OBJECT_IMPL(Document, Element, documentElement);
HTML5_PROPERTY_IMPL(Document, std::string, documentURI);
HTML5_PROPERTY_IMPL(Document, std::string, domain);
HTML5_PROPERTY_OBJECT_IMPL(Document, HTMLCollection, embeds);
HTML5_PROPERTY_OBJECT_IMPL(Document, Element, firstElementChild);
HTML5_PROPERTY_OBJECT_IMPL(Document, HTMLCollection, forms);
HTML5_PROPERTY_OBJECT_IMPL(Document, Element, fullScreenElement);
HTML5_PROPERTY_IMPL(Document, bool, fullScreenEnabled);
HTML5_PROPERTY_OBJECT_IMPL(Document, HTMLHeadElement, head);
HTML5_PROPERTY_OBJECT_IMPL(Document, HTMLCollection, images);
HTML5_PROPERTY_OBJECT_IMPL(Document, DOMImplementation, implementation);
HTML5_PROPERTY_OBJECT_IMPL(Document, Element, lastElementChild);
HTML5_PROPERTY_IMPL(Document, std::string, lastModified);
HTML5_PROPERTY_IMPL(Document, std::string, lastStyleSheetSet);
HTML5_PROPERTY_OBJECT_IMPL(Document, HTMLCollection, links);
HTML5_PROPERTY_OBJECT_IMPL(Document, Location, location);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Document, EventHandler *, onabort);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Document, EventHandler *, onautocomplete);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Document, EventHandler *, onautocompleteerror);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Document, EventHandler *, onblur);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Document, EventHandler *, oncancel);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Document, EventHandler *, oncanplay);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Document, EventHandler *, oncanplaythrough);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Document, EventHandler *, onchange);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Document, EventHandler *, onclick);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Document, EventHandler *, onclose);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Document, EventHandler *, oncontextmenu);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Document, EventHandler *, oncuechange);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Document, EventHandler *, ondblclick);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Document, EventHandler *, ondrag);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Document, EventHandler *, ondragend);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Document, EventHandler *, ondragenter);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Document, EventHandler *, ondragexit);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Document, EventHandler *, ondragleave);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Document, EventHandler *, ondragover);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Document, EventHandler *, ondragstart);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Document, EventHandler *, ondrop);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Document, EventHandler *, ondurationchange);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Document, EventHandler *, onemptied);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Document, EventHandler *, onended);
HTML5_ERROR_HANDLER_PROPERTY_IMPL(Document, OnErrorEventHandler *, onerror);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Document, EventHandler *, onfocus);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Document, EventHandler *, oninput);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Document, EventHandler *, oninvalid);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Document, EventHandler *, onkeydown);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Document, EventHandler *, onkeypress);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Document, EventHandler *, onkeyup);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Document, EventHandler *, onload);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Document, EventHandler *, onloadeddata);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Document, EventHandler *, onloadedmetadata);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Document, EventHandler *, onloadstart);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Document, EventHandler *, onmousedown);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Document, EventHandler *, onmouseenter);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Document, EventHandler *, onmouseleave);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Document, EventHandler *, onmousemove);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Document, EventHandler *, onmouseout);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Document, EventHandler *, onmouseover);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Document, EventHandler *, onmouseup);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Document, EventHandler *, onmousewheel);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Document, EventHandler *, onpause);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Document, EventHandler *, onplay);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Document, EventHandler *, onplaying);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Document, EventHandler *, onpointerlockchange);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Document, EventHandler *, onpointerlockerror);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Document, EventHandler *, onprogress);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Document, EventHandler *, onratechange);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Document, EventHandler *, onreadystatechange);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Document, EventHandler *, onreset);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Document, EventHandler *, onresize);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Document, EventHandler *, onscroll);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Document, EventHandler *, onseeked);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Document, EventHandler *, onseeking);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Document, EventHandler *, onselect);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Document, EventHandler *, onshow);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Document, EventHandler *, onsort);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Document, EventHandler *, onstalled);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Document, EventHandler *, onsubmit);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Document, EventHandler *, onsuspend);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Document, EventHandler *, ontimeupdate);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Document, EventHandler *, ontoggle);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Document, EventHandler *, onvolumechange);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Document, EventHandler *, onwaiting);
HTML5_PROPERTY_IMPL(Document, std::string, origin);
HTML5_PROPERTY_OBJECT_IMPL(Document, HTMLCollection, plugins);
HTML5_PROPERTY_OBJECT_IMPL(Document, Element, pointerLockElement);
HTML5_PROPERTY_IMPL(Document, std::string, preferredStyleSheetSet);
HTML5_PROPERTY_IMPL(Document, std::string, referrer);
HTML5_PROPERTY_IMPL(Document, std::string, selectedStyleSheetSet);
HTML5_PROPERTY_IMPL(Document, std::string, title);
HTML5_PROPERTY_IMPL(Document, std::string, URL);
HTML5_PROPERTY_OBJECT_IMPL(Document, HTMLCollection, scripts);
HTML5_PROPERTY_OBJECT_IMPL(Document, StyleSheetList, styleSheets);
