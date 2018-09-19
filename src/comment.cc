#include "comment.h"

USING_NAMESPACE_HTML5;

Comment::Comment(emscripten::val v) :
    CharacterData(v)
{

}

Comment::~Comment()
{

}

Comment *Comment::create(emscripten::val v)
{
    auto comment = new Comment(v);
    comment->autorelease();
    return comment;
}
