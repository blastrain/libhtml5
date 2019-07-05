#include "promise.h"

USING_NAMESPACE_HTML5;

HTML5_BIND_CLASS(Promise);

Promise::Promise(emscripten::val v) :
    Object(v)
{

}

Promise::~Promise()
{

}

Promise *Promise::create(emscripten::val v)
{
    Promise *p = new Promise(v);
    p->autorelease();
    return p;
}

Promise *Promise::create(executor fn)
{
    Promise *p = new Promise(emscripten::val(0));
    EM_ASM_({                                                           
        var elem = Module['toPromise']($0);
        elem['_value'] = new Promise(function(resolve, reject) { elem.callbackThen(resolve, reject); });
    }, p);
    p->autorelease();
    return p;
}

Promise *Promise::create(executorString fn)
{
    Promise *p = new Promise(emscripten::val(0));
    p->execStr = fn;
    EM_ASM_({                                                           
        var elem = Module['toPromise']($0);
        elem['_value'] = new Promise(function(resolve, reject) {
            elem.executeString({call: resolve}, reject);
        });
    }, p);
    p->autorelease();
    return p;
}

HTML5_BIND_METHOD(Promise, executeString);

void Promise::executeString(emscripten::val resolve, emscripten::val reject)
{
    std::function<void(const std::string &)> resolver = [resolve](const std::string &s){
        HTML5_CALL(resolve, call, s);
    };
    std::function<void()> rejector = []{};
    this->execStr(resolver, rejector);
}

Promise *Promise::then(chainString onFulfilled)
{
    this->chainFns.push_back(onFulfilled);
    EM_ASM_({
        var elem = Module['toPromise']($0);
        elem._value.then(function(resolve) { elem.callbackThenString(resolve); });
    }, this);
    return this;
}

HTML5_BIND_METHOD(Promise, callbackThenString);

void Promise::callbackThenString(emscripten::val resolve)
{
    const chainString &chain = this->chainFns[0];
    chain(resolve.as<std::string>());
    this->chainFns.erase(this->chainFns.begin());
}

HTML5_PROPERTY_IMPL(Promise, unsigned long, length);
