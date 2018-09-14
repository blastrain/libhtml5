#include "history.h"

History::History(emscripten::val v) :
    Object(),
    v(v)
{

}

History::~History()
{

}

History *History::create(emscripten::val v)
{
    auto history = new History(v);
    history->autorelease();
    return history;
}

void History::back()
{
    HTML5_CALL(this->v, back);
}

void History::forward()
{
    HTML5_CALL(this->v, forward);
}

void History::go(long delta)
{
    HTML5_CALL(this->v, go, delta);
}

void History::pushState(void *data, std::string title, std::string url)
{
    //HTML5_CALL(this->v, pushState, data, title, url);
}

void History::replaceState(void *data, std::string title, std::string url)
{
    //HTML5_CALL(this->v, replaceState, data, title, url);
}
