#pragma once

#include "html_media_element.h"

class HTMLVideoElement : public HTMLMediaElement {
public:
    double _height;
    std::string _poster;
    double _videoHeight;
    double _videoWidth;
    double _width;
    
    HTMLVideoElement(emscripten::val v);
    ~HTMLVideoElement();
    static HTMLVideoElement *create();
    static HTMLVideoElement *create(emscripten::val v);
    double getHeight() const;
    void setHeight(double value);
    std::string getPoster() const;
    void setPoster(std::string value);
    double getVideoHeight() const;
    void setVideoHeight(double value);
    double getVideoWidth() const;
    void setVideoWidth(double value);
    double getWidth() const;
    void setWidth(double value);

    struct {
        HTMLVideoElement &self;
        void operator=(double value) { self.setHeight(value); };
        operator double() { return self.getHeight(); };
    } height{*this};

    struct {
        HTMLVideoElement &self;
        void operator=(std::string value) { self.setPoster(value); };
        operator std::string() { return self.getPoster(); };
    } poster{*this};

    struct {
        HTMLVideoElement &self;
        void operator=(double value) { self.setVideoHeight(value); };
        operator double() { return self.getVideoHeight(); };
    } videoHeight{*this};

    struct {
        HTMLVideoElement &self;
        void operator=(double value) { self.setVideoWidth(value); };
        operator double() { return self.getVideoWidth(); };
    } videoWidth{*this};

    struct {
        HTMLVideoElement &self;
        void operator=(double value) { self.setWidth(value); };
        operator double() { return self.getWidth(); };
    } width{*this};

};
