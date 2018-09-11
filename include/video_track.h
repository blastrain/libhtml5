#pragma once

#include "libhtml5.h"

class VideoTrack : public Object {
public:
    emscripten::val v;
    std::string _id;
    std::string _kind;
    std::string _label;
    std::string _language;
    bool _selected;

    VideoTrack(emscripten::val v);
    virtual ~VideoTrack();
    static VideoTrack *create(emscripten::val v);
    std::string getId() const;
    void setId(std::string value);
    std::string getKind() const;
    void setKind(std::string value);
    std::string getLabel() const;
    void setLabel(std::string value);
    std::string getLanguage() const;
    void setLanguage(std::string value);
    bool getSelected() const;
    void setSelected(bool value);

    struct {
        VideoTrack &self;
        void operator=(std::string value) { self.setId(value); };
        operator std::string() { return self.getId(); };
    } id{*this};

    struct {
        VideoTrack &self;
        void operator=(std::string value) { self.setKind(value); };
        operator std::string() { return self.getKind(); };
    } kind{*this};

    struct {
        VideoTrack &self;
        void operator=(std::string value) { self.setLabel(value); };
        operator std::string() { return self.getLabel(); };
    } label{*this};

    struct {
        VideoTrack &self;
        void operator=(std::string value) { self.setLanguage(value); };
        operator std::string() { return self.getLanguage(); };
    } language{*this};

    struct {
        VideoTrack &self;
        void operator=(bool value) { self.setSelected(value); };
        operator bool() { return self.getSelected(); };
    } selected{*this};
};
