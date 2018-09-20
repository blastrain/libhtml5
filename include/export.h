#pragma once

// this is included by libhtml5.h

NAMESPACE_HTML5_BEGIN;

class Window;
class Document;
class ApplicationCache;
class Document;
class External;
class Element;
class History;
class IDBFactory;
class Storage;
class Location;
class BarProp;
class Navigator;
class Promise;
class CSSStyleDeclaration;
class HTMLImageElement;
class HTMLVideoElement;
class HTMLCanvasElement;
class Blob;
class ImageData;
class CanvasRenderingContext2D;
class ImageBitmap;
class Transferable;
class Performance;
class WindowProxy;

extern Window *window;
extern Document *document;

extern void alert(std::string message);
extern std::string atob(std::string atob);
extern void blur();
extern std::string btoa(std::string btoa);
extern void cancelAnimationFrame(long handle);
extern void clearInterval(long handle);
extern void clearTimeout(long handle);
extern void close();
extern bool confirm(std::string message);
extern Promise *createImageBitmap(HTMLImageElement *image, long sx, long sy, long sw, long sh);
extern Promise *createImageBitmap(HTMLVideoElement *image, long sx, long sy, long sw, long sh);
extern Promise *createImageBitmap(HTMLCanvasElement *image, long sx, long sy, long sw, long sh);
extern Promise *createImageBitmap(Blob *image, long sx, long sy, long sw, long sh);
extern Promise *createImageBitmap(ImageData *image, long sx, long sy, long sw, long sh);
extern Promise *createImageBitmap(CanvasRenderingContext2D *image, long sx, long sy, long sw, long sh);
extern Promise *createImageBitmap(ImageBitmap *image, long sx, long sy, long sw, long sh);
extern void focus();
extern CSSStyleDeclaration *getComputedStyle(Element *elt, std::string pseudoElt);
extern WindowProxy *getter(void *indexName);
extern WindowProxy *open(std::string url, std::string target, std::string features, bool replace);
extern void postMessage(void *message, std::string targetOrigin, std::vector<Transferable *> transfer);
extern void print();
extern std::string prompt(std::string message, std::string _default);
extern long requestAnimationFrame(std::function<void(double)> *callback);
extern long setInterval(std::function<void(void)> *handler, long timeout);
extern long setTimeout(std::function<void(void)> *handler, long timeout);
extern void stop();

NAMESPACE_HTML5_END;

extern void HTML5_INIT();
