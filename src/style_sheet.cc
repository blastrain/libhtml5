#include "media_list.h"
#include "element.h"
#include "style_sheet.h"

StyleSheet::StyleSheet(emscripten::val v) : v(v)
{

}

StyleSheet::~StyleSheet()
{

}

StyleSheet *StyleSheet::create(emscripten::val v)
{
    return new StyleSheet(v);
}

bool StyleSheet::getDisabled() const
{
    return this->v["disabled"].as<bool>();
}

void StyleSheet::setDisabled(bool value)
{
    this->_disabled = value;
    this->v.set("disabled", value);
}

std::string StyleSheet::getHref() const
{
    return this->v["href"].as<std::string>();
}

void StyleSheet::setHref(std::string value)
{
    this->_href = value;
    this->v.set("href", value);
}

MediaList *StyleSheet::getMedia() const
{
    return MediaList::create(this->v["media"]);
}

void StyleSheet::setMedia(MediaList *value)
{
    this->_media = value;
    this->v.set("media", value->v);
}

Element *StyleSheet::getOwnerNode() const
{
    return Element::create(this->v["ownerNode"]);
}

void StyleSheet::setOwnerNode(Element *value)
{
    this->_ownerNode = value;
    this->v.set("ownerNode", value->v);
}

StyleSheet *StyleSheet::getParentStyleSheet() const
{
    return StyleSheet::create(this->v["parentStyleSheet"]);
}

void StyleSheet::setParentStyleSheet(StyleSheet *value)
{
    this->_parentStyleSheet = value;
    this->v.set("parentStyleSheet", value->v);
}

std::string StyleSheet::getTitle() const
{
    return this->v["title"].as<std::string>();
}

void StyleSheet::setTitle(std::string value)
{
    this->_title = value;
    this->v.set("title", value);
}

std::string StyleSheet::getType() const
{
    return this->v["type"].as<std::string>();
}

void StyleSheet::setType(std::string value)
{
    this->_type = value;
    this->v.set("type", value);
}
