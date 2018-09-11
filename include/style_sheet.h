#pragma once

#include "libhtml5.h"

class MediaList;
class Element;

class StyleSheet : public Object {
public:
    emscripten::val v;
    bool _disabled;
    std::string _href;
    MediaList *_media;
    Element *_ownerNode;
    StyleSheet *_parentStyleSheet;
    std::string _title;
    std::string _type;

    StyleSheet(emscripten::val v);
    virtual ~StyleSheet();
    static StyleSheet *create(emscripten::val v);

    bool getDisabled() const;
    void setDisabled(bool value);
    std::string getHref() const;
    void setHref(std::string value);
    MediaList *getMedia() const;
    void setMedia(MediaList *value);
    Element *getOwnerNode() const;
    void setOwnerNode(Element *value);
    StyleSheet *getParentStyleSheet() const;
    void setParentStyleSheet(StyleSheet *value);
    std::string getTitle() const;
    void setTitle(std::string value);
    std::string getType() const;
    void setType(std::string value);

    struct {
        StyleSheet &self;
        void operator=(bool value) { self.setDisabled(value); };
        operator bool() { return self.getDisabled(); };
    } disabled{*this};

    struct {
        StyleSheet &self;
        void operator=(std::string value) { self.setHref(value); };
        operator std::string() { return self.getHref(); };
    } href{*this};

    struct {
        StyleSheet &self;
        void operator=(MediaList *value) { self.setMedia(value); };
        operator MediaList *() { return self.getMedia(); };
    } media{*this};

    struct {
        StyleSheet &self;
        void operator=(Element *value) { self.setOwnerNode(value); };
        operator Element *() { return self.getOwnerNode(); };
    } ownerNode{*this};

    struct {
        StyleSheet &self;
        void operator=(StyleSheet *value) { self.setParentStyleSheet(value); };
        operator StyleSheet *() { return self.getParentStyleSheet(); };
    } parentStyleSheet{*this};

    struct {
        StyleSheet &self;
        void operator=(std::string value) { self.setTitle(value); };
        operator std::string() { return self.getTitle(); };
    } title{*this};

    struct {
        StyleSheet &self;
        void operator=(std::string value) { self.setType(value); };
        operator std::string() { return self.getType(); };
    } type{*this};

};
