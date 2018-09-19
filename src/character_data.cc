#include "element.h"
#include "character_data.h"

USING_NAMESPACE_HTML5;

CharacterData::CharacterData(emscripten::val v) :
    Node(v)
{

}

CharacterData::~CharacterData()
{
}

CharacterData *CharacterData::create(emscripten::val v)
{
    auto data = new CharacterData(v);
    data->autorelease();
    return data;
}

void CharacterData::after(std::vector<Node *> nodes)
{
    for (Node *node : nodes) {
        HTML5_CALL(this->v, after, node->v);
    }
}

void CharacterData::appendData(std::string data)
{
    HTML5_CALL(this->v, appendData, data);
}

void CharacterData::before(std::vector<Node *> nodes)
{
    for (Node *node : nodes) {
        HTML5_CALL(this->v, after, node->v);
    }
}

void CharacterData::deleteData(unsigned long offset, unsigned long count)
{
    HTML5_CALL(this->v, deleteData, offset, count);
}

void CharacterData::insertData(unsigned long offset, std::string data)
{
    HTML5_CALL(this->v, insertData, offset, data);
}

void CharacterData::remove()
{
    HTML5_CALL(this->v, remove);
}

void CharacterData::replace(std::vector<Node *> nodes)
{
    for (Node *node : nodes) {
        HTML5_CALL(this->v, replace, node->v);
    }
}

void CharacterData::replaceData(unsigned long offset, unsigned long count, std::string data)
{
    HTML5_CALL(this->v, replaceData, offset, count);
}

std::string CharacterData::substringData(unsigned long offset, unsigned long count)
{
    return HTML5_CALLs(this->v, substringData, offset, count);
}

HTML5_PROPERTY_IMPL(CharacterData, std::string, data);
HTML5_PROPERTY_IMPL(CharacterData, unsigned long, length);
HTML5_PROPERTY_OBJECT_IMPL(CharacterData, Element, nextElementSibling);
HTML5_PROPERTY_OBJECT_IMPL(CharacterData, Element, previousElementSibling);
