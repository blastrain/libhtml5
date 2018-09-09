#pragma once

#include "html_element.h"

class HTMLImageElement : public HTMLElement {
public:
    std::string _alt;
    bool _complete;
    std::string _crossOrigin;
    unsigned long _height;
    bool _isMap;
    unsigned long _naturalHeight;
    unsigned long _naturalWidth;
    std::string _src;
    std::string _srcset;
    std::string _useMap;
    unsigned long _width;

    HTMLImageElement(emscripten::val v);
    virtual ~HTMLImageElement();
    static HTMLImageElement *create();
    static HTMLImageElement *create(emscripten::val v);
    static HTMLImageElement *create(unsigned long width, unsigned long height);

    struct {
        HTMLImageElement &self;
        void operator=(std::string value) { self.setAlt(value); };
        operator std::string() { return self.getAlt(); };
    } alt{*this};

    struct {
        HTMLImageElement &self;
        void operator=(bool value) { self.setComplete(value); };
        operator bool() { return self.getComplete(); };
    } complete{*this};

    struct {
        HTMLImageElement &self;
        void operator=(std::string value) { self.setCrossOrigin(value); };
        operator std::string() { return self.getCrossOrigin(); };
    } crossOrigin{*this};

    struct {
        HTMLImageElement &self;
        void operator=(unsigned long value) { self.setHeight(value); };
        operator unsigned long() { return self.getHeight(); };
    } height{*this};

    struct {
        HTMLImageElement &self;
        void operator=(bool value) { self.setIsMap(value); };
        operator bool() { return self.getIsMap(); };
    } isMap{*this};

    struct {
        HTMLImageElement &self;
        void operator=(unsigned long value) { self.setNaturalHeight(value); };
        operator unsigned long() { return self.getNaturalHeight(); };
    } naturalHeight{*this};

    struct {
        HTMLImageElement &self;
        void operator=(unsigned long value) { self.setNaturalWidth(value); };
        operator unsigned long() { return self.getNaturalWidth(); };
    } naturalWidth{*this};

    struct {
        HTMLImageElement &self;
        void operator=(std::string value) { self.setSrc(value); };
        operator std::string() { return self.getSrc(); };
    } src{*this};

    struct {
        HTMLImageElement &self;
        void operator=(std::string value) { self.setSrcSet(value); };
        operator std::string() { return self.getSrcSet(); };
    } srcset{*this};

    struct {
        HTMLImageElement &self;
        void operator=(std::string value) { self.setUseMap(value); };
        operator std::string() { return self.getUseMap(); };
    } useMap{*this};

    struct {
        HTMLImageElement &self;
        void operator=(unsigned long value) { self.setWidth(value); };
        operator unsigned long() { return self.getWidth(); };
    } width{*this};

    std::string getAlt() const;
    void setAlt(std::string value);
    bool getComplete() const;
    void setComplete(bool value);
    std::string getCrossOrigin() const;
    void setCrossOrigin(std::string value);
    unsigned long getHeight() const;
    void setHeight(unsigned long value);
    bool getIsMap() const;
    void setIsMap(bool value);
    unsigned long getNaturalHeight() const;
    void setNaturalHeight(unsigned long value);
    unsigned long getNaturalWidth() const;
    void setNaturalWidth(unsigned long value);
    std::string getSrc() const;
    void setSrc(std::string value);
    std::string getSrcSet() const;
    void setSrcSet(std::string value);
    std::string getUseMap() const;
    void setUseMap(std::string value);
    unsigned long getWidth() const;
    void setWidth(unsigned long value);
};
