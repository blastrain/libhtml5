#pragma once

#include <emscripten/val.h>
#include <string>

class MediaList {
public:
    emscripten::val v;
    unsigned long _length;
    std::string _mediaText;

    MediaList(emscripten::val v);
    virtual ~MediaList();
    static MediaList *create(emscripten::val v);
    void appendMedium(std::string medium);
    void deleteMedium(std::string medium);
    std::string item(unsigned long index);

    unsigned long getLength() const;
    void setLength(unsigned long value);
    std::string getMediaText() const;
    void setMediaText(std::string value);

    struct {
        MediaList &self;
        void operator=(unsigned long value) { self.setLength(value); };
        operator unsigned long() { return self.getLength(); };
    } length{*this};

    struct {
        MediaList &self;
        void operator=(std::string value) { self.setMediaText(value); };
        operator std::string() { return self.getMediaText(); };
    } mediaText{*this};
};
