#pragma once

#include "object.h"
#include <emscripten/val.h>
#include <string>

class AudioTrack : public Object {
public:
    emscripten::val v;
    bool _enabled;
    std::string _id;
    std::string _kind;
    std::string _label;
    std::string _language;

    AudioTrack(emscripten::val v);
    virtual ~AudioTrack();
    static AudioTrack *create(emscripten::val v);
    bool getEnabled() const;
    void setEnabled(bool value);
    std::string getId() const;
    void setId(std::string value);
    std::string getKind() const;
    void setKind(std::string value);
    std::string getLabel() const;
    void setLabel(std::string value);
    std::string getLanguage() const;
    void setLanguage(std::string value);

    struct {
        AudioTrack &self;
        void operator=(bool value) { self.setEnabled(value); };
        operator bool() { return self.getEnabled(); };
    } enabled{*this};

    struct {
        AudioTrack &self;
        void operator=(std::string value) { self.setId(value); };
        operator std::string() { return self.getId(); };
    } id{*this};

    struct {
        AudioTrack &self;
        void operator=(std::string value) { self.setKind(value); };
        operator std::string() { return self.getKind(); };
    } kind{*this};

    struct {
        AudioTrack &self;
        void operator=(std::string value) { self.setLabel(value); };
        operator std::string() { return self.getLabel(); };
    } label{*this};

    struct {
        AudioTrack &self;
        void operator=(std::string value) { self.setLanguage(value); };
        operator std::string() { return self.getLanguage(); };
    } language{*this};

};
