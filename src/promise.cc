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

Promise *Promise::create(PromiseVoidVoidPairFunction fn)
{
    Promise *p = new Promise(emscripten::val(0));
    p->vvPairFn = fn;
    EM_ASM_({
        var elem = Module['toPromise']($0);
        elem['_value'] = new Promise(function(resolve, reject) {
            elem.callbackVV({call: resolve}, {call: reject});
        });
    }, p);
    p->autorelease();
    return p;
}

Promise *Promise::create(PromiseVoidDoublePairFunction fn)
{
    Promise *p = new Promise(emscripten::val(0));
    p->vdPairFn = fn;
    EM_ASM_({
        var elem = Module['toPromise']($0);
        elem['_value'] = new Promise(function(resolve, reject) {
            elem.callbackVD({call: resolve}, {call: reject});
        });
    }, p);
    p->autorelease();
    return p;
}

Promise *Promise::create(PromiseVoidStringPairFunction fn)
{
    Promise *p = new Promise(emscripten::val(0));
    p->vsPairFn = fn;
    EM_ASM_({
        var elem = Module['toPromise']($0);
        elem['_value'] = new Promise(function(resolve, reject) {
            elem.callbackVS({call: resolve}, {call: reject});
        });
    }, p);
    p->autorelease();
    return p;
}

Promise *Promise::create(PromiseVoidObjectPairFunction fn)
{
    Promise *p = new Promise(emscripten::val(0));
    p->voPairFn = fn;
    EM_ASM_({
        var elem = Module['toPromise']($0);
        elem['_value'] = new Promise(function(resolve, reject) {
            elem.callbackVO({call: resolve}, {call: reject});
        });
    }, p);
    p->autorelease();
    return p;
}

Promise *Promise::create(PromiseDoubleVoidPairFunction fn)
{
    Promise *p = new Promise(emscripten::val(0));
    p->dvPairFn = fn;
    EM_ASM_({
        var elem = Module['toPromise']($0);
        elem['_value'] = new Promise(function(resolve, reject) {
            elem.callbackDV({call: resolve}, {call: reject});
        });
    }, p);
    p->autorelease();
    return p;
}

Promise *Promise::create(PromiseDoubleDoublePairFunction fn)
{
    Promise *p = new Promise(emscripten::val(0));
    p->ddPairFn = fn;
    EM_ASM_({
        var elem = Module['toPromise']($0);
        elem['_value'] = new Promise(function(resolve, reject) {
            elem.callbackDD({call: resolve}, {call: reject});
        });
    }, p);
    p->autorelease();
    return p;
}

Promise *Promise::create(PromiseDoubleStringPairFunction fn)
{
    Promise *p = new Promise(emscripten::val(0));
    p->dsPairFn = fn;
    EM_ASM_({
        var elem = Module['toPromise']($0);
        elem['_value'] = new Promise(function(resolve, reject) {
            elem.callbackDS({call: resolve}, {call: reject});
        });
    }, p);
    p->autorelease();
    return p;
}

Promise *Promise::create(PromiseDoubleObjectPairFunction fn)
{
    Promise *p = new Promise(emscripten::val(0));
    p->doPairFn = fn;
    EM_ASM_({
        var elem = Module['toPromise']($0);
        elem['_value'] = new Promise(function(resolve, reject) {
            elem.callbackDO({call: resolve}, {call: reject});
        });
    }, p);
    p->autorelease();
    return p;
}

Promise *Promise::create(PromiseStringVoidPairFunction fn)
{
    Promise *p = new Promise(emscripten::val(0));
    p->svPairFn = fn;
    EM_ASM_({
        var elem = Module['toPromise']($0);
        elem['_value'] = new Promise(function(resolve, reject) {
            elem.callbackSV({call: resolve}, {call: reject});
        });
    }, p);
    p->autorelease();
    return p;
}

Promise *Promise::create(PromiseStringDoublePairFunction fn)
{
    Promise *p = new Promise(emscripten::val(0));
    p->sdPairFn = fn;
    EM_ASM_({
        var elem = Module['toPromise']($0);
        elem['_value'] = new Promise(function(resolve, reject) {
            elem.callbackSD({call: resolve}, {call: reject});
        });
    }, p);
    p->autorelease();
    return p;
}

Promise *Promise::create(PromiseStringStringPairFunction fn)
{
    Promise *p = new Promise(emscripten::val(0));
    p->ssPairFn = fn;
    EM_ASM_({
        var elem = Module['toPromise']($0);
        elem['_value'] = new Promise(function(resolve, reject) {
            elem.callbackSS({call: resolve}, {call: reject});
        });
    }, p);
    p->autorelease();
    return p;
}

Promise *Promise::create(PromiseStringObjectPairFunction fn)
{
    Promise *p = new Promise(emscripten::val(0));
    p->soPairFn = fn;
    EM_ASM_({
        var elem = Module['toPromise']($0);
        elem['_value'] = new Promise(function(resolve, reject) {
            elem.callbackSO({call: resolve}, {call: reject});
        });
    }, p);
    p->autorelease();
    return p;
}

Promise *Promise::create(PromiseObjectVoidPairFunction fn)
{
    Promise *p = new Promise(emscripten::val(0));
    p->ovPairFn = fn;
    EM_ASM_({
        var elem = Module['toPromise']($0);
        elem['_value'] = new Promise(function(resolve, reject) {
            elem.callbackOV({call: resolve}, {call: reject});
        });
    }, p);
    p->autorelease();
    return p;
}

Promise *Promise::create(PromiseObjectDoublePairFunction fn)
{
    Promise *p = new Promise(emscripten::val(0));
    p->odPairFn = fn;
    EM_ASM_({
        var elem = Module['toPromise']($0);
        elem['_value'] = new Promise(function(resolve, reject) {
            elem.callbackOD({call: resolve}, {call: reject});
        });
    }, p);
    p->autorelease();
    return p;
}

Promise *Promise::create(PromiseObjectStringPairFunction fn)
{
    Promise *p = new Promise(emscripten::val(0));
    p->osPairFn = fn;
    EM_ASM_({
        var elem = Module['toPromise']($0);
        elem['_value'] = new Promise(function(resolve, reject) {
            elem.callbackOS({call: resolve}, {call: reject});
        });
    }, p);
    p->autorelease();
    return p;
}

Promise *Promise::create(PromiseObjectObjectPairFunction fn)
{
    Promise *p = new Promise(emscripten::val(0));
    p->ooPairFn = fn;
    EM_ASM_({
        var elem = Module['toPromise']($0);
        elem['_value'] = new Promise(function(resolve, reject) {
            elem.callbackOO({call: resolve}, {call: reject});
        });
    }, p);
    p->autorelease();
    return p;
}

void Promise::callbackVV(emscripten::val resolve, emscripten::val reject)
{
    PromiseVoidFunction resolver = [resolve]{
        HTML5_CALL(resolve, call);
    };
    PromiseVoidFunction rejector = [reject]{
        HTML5_CALL(reject, call);
    };
    this->vvPairFn(resolver, rejector);
}

void Promise::callbackVD(emscripten::val resolve, emscripten::val reject)
{
    PromiseVoidFunction resolver = [resolve]{
        HTML5_CALL(resolve, call);
    };
    PromiseDoubleFunction rejector = [reject](double v){
        HTML5_CALL(reject, call, v);
    };
    this->vdPairFn(resolver, rejector);
}

void Promise::callbackVS(emscripten::val resolve, emscripten::val reject)
{
    PromiseVoidFunction resolver = [resolve]{
        HTML5_CALL(resolve, call);
    };
    PromiseStringFunction rejector = [reject](const std::string &v){
        HTML5_CALL(reject, call, v);
    };
    this->vsPairFn(resolver, rejector);
}

void Promise::callbackVO(emscripten::val resolve, emscripten::val reject)
{
    PromiseVoidFunction resolver = [resolve]{
        HTML5_CALL(resolve, call);
    };
    PromiseObjectFunction rejector = [reject](const Object &v){
        HTML5_CALL(reject, call, v.v);
    };
    this->voPairFn(resolver, rejector);
}

void Promise::callbackDV(emscripten::val resolve, emscripten::val reject)
{
    PromiseDoubleFunction resolver = [resolve](double v){
        HTML5_CALL(resolve, call, v);
    };
    PromiseVoidFunction rejector = [reject]{
        HTML5_CALL(reject, call);
    };
    this->dvPairFn(resolver, rejector);
}

void Promise::callbackDD(emscripten::val resolve, emscripten::val reject)
{
    PromiseDoubleFunction resolver = [resolve](double v){
        HTML5_CALL(resolve, call, v);
    };
    PromiseDoubleFunction rejector = [reject](double v){
        HTML5_CALL(reject, call, v);
    };
    this->ddPairFn(resolver, rejector);
}

void Promise::callbackDS(emscripten::val resolve, emscripten::val reject)
{
    PromiseDoubleFunction resolver = [resolve](double v){
        HTML5_CALL(resolve, call, v);
    };
    PromiseStringFunction rejector = [reject](const std::string &v){
        HTML5_CALL(reject, call, v);
    };
    this->dsPairFn(resolver, rejector);
}

void Promise::callbackDO(emscripten::val resolve, emscripten::val reject)
{
    PromiseDoubleFunction resolver = [resolve](double v){
        HTML5_CALL(resolve, call, v);
    };
    PromiseObjectFunction rejector = [reject](const Object &v){
        HTML5_CALL(reject, call, v.v);
    };
    this->doPairFn(resolver, rejector);
}

void Promise::callbackSV(emscripten::val resolve, emscripten::val reject)
{
    PromiseStringFunction resolver = [resolve](const std::string &v){
        HTML5_CALL(resolve, call, v);
    };
    PromiseVoidFunction rejector = [reject]{
        HTML5_CALL(reject, call);
    };
    this->svPairFn(resolver, rejector);
}

void Promise::callbackSD(emscripten::val resolve, emscripten::val reject)
{
    PromiseStringFunction resolver = [resolve](const std::string &v){
        HTML5_CALL(resolve, call, v);
    };
    PromiseDoubleFunction rejector = [reject](double v){
        HTML5_CALL(reject, call, v);
    };
    this->sdPairFn(resolver, rejector);
}

void Promise::callbackSS(emscripten::val resolve, emscripten::val reject)
{
    PromiseStringFunction resolver = [resolve](const std::string &v){
        HTML5_CALL(resolve, call, v);
    };
    PromiseStringFunction rejector = [reject](const std::string &v){
        HTML5_CALL(reject, call, v);
    };
    this->ssPairFn(resolver, rejector);
}

void Promise::callbackSO(emscripten::val resolve, emscripten::val reject)
{
    PromiseStringFunction resolver = [resolve](const std::string &v){
        HTML5_CALL(resolve, call, v);
    };
    PromiseObjectFunction rejector = [reject](const Object &v){
        HTML5_CALL(reject, call, v.v);
    };
    this->soPairFn(resolver, rejector);
}

void Promise::callbackOV(emscripten::val resolve, emscripten::val reject)
{
    PromiseObjectFunction resolver = [resolve](const Object &v){
        HTML5_CALL(resolve, call, v.v);
    };
    PromiseVoidFunction rejector = [reject]{
        HTML5_CALL(reject, call);
    };
    this->ovPairFn(resolver, rejector);
}

void Promise::callbackOD(emscripten::val resolve, emscripten::val reject)
{
    PromiseObjectFunction resolver = [resolve](const Object &v){
        HTML5_CALL(resolve, call, v.v);
    };
    PromiseDoubleFunction rejector = [reject](double v){
        HTML5_CALL(reject, call, v);
    };
    this->odPairFn(resolver, rejector);
}

void Promise::callbackOS(emscripten::val resolve, emscripten::val reject)
{
    PromiseObjectFunction resolver = [resolve](const Object &v){
        HTML5_CALL(resolve, call, v.v);
    };
    PromiseStringFunction rejector = [reject](const std::string &v){
        HTML5_CALL(reject, call, v);
    };
    this->osPairFn(resolver, rejector);
}

void Promise::callbackOO(emscripten::val resolve, emscripten::val reject)
{
    PromiseObjectFunction resolver = [resolve](const Object &v){
        HTML5_CALL(resolve, call, v.v);
    };
    PromiseObjectFunction rejector = [reject](const Object &v){
        HTML5_CALL(reject, call, v.v);
    };
    this->ooPairFn(resolver, rejector);
}

HTML5_BIND_METHOD(Promise, callbackVV);
HTML5_BIND_METHOD(Promise, callbackVD);
HTML5_BIND_METHOD(Promise, callbackVS);
HTML5_BIND_METHOD(Promise, callbackVO);
HTML5_BIND_METHOD(Promise, callbackDV);
HTML5_BIND_METHOD(Promise, callbackDD);
HTML5_BIND_METHOD(Promise, callbackDS);
HTML5_BIND_METHOD(Promise, callbackDO);
HTML5_BIND_METHOD(Promise, callbackSV);
HTML5_BIND_METHOD(Promise, callbackSD);
HTML5_BIND_METHOD(Promise, callbackSS);
HTML5_BIND_METHOD(Promise, callbackSO);
HTML5_BIND_METHOD(Promise, callbackOV);
HTML5_BIND_METHOD(Promise, callbackOD);
HTML5_BIND_METHOD(Promise, callbackOS);
HTML5_BIND_METHOD(Promise, callbackOO);

Promise *Promise::then(PromiseVoidPromiseFunction onFulfilled)
{
    auto fn = new PromiseChainFunction();
    fn->onFulfilled.vp = onFulfilled;
    this->chains.push_back(fn);
    EM_ASM_({
        var elem = Module['toPromise']($0);
        elem._value = elem._value.then(function() { return elem.callbackThenVP(); });
    }, this);
    return this;
}

Promise *Promise::then(PromiseVoidPromiseFunction onFulfilled, PromiseVoidPromiseFunction onRejected)
{
    auto fn = new PromiseChainFunction();
    fn->onFulfilled.vp = onFulfilled;
    fn->onRejected.vp = onRejected;
    this->chains.push_back(fn);
    EM_ASM_({
        var elem = Module['toPromise']($0);
        elem._value = elem._value.then(
            function() { return elem.callbackThenVP(); },
            function() { return elem.callbackRejectVP(); }
        );
    }, this);
    return this;
}

Promise *Promise::then(PromiseVoidPromiseFunction onFulfilled, PromiseDoublePromiseFunction onRejected)
{
    auto fn = new PromiseChainFunction();
    fn->onFulfilled.vp = onFulfilled;
    fn->onRejected.dp = onRejected;
    this->chains.push_back(fn);
    EM_ASM_({
        var elem = Module['toPromise']($0);
        elem._value = elem._value.then(
            function() { return elem.callbackThenVP(); },
            function(v) { return elem.callbackRejectDP(v); }
        );
    }, this);
    return this;
}

Promise *Promise::then(PromiseVoidPromiseFunction onFulfilled, PromiseStringPromiseFunction onRejected)
{
    auto fn = new PromiseChainFunction();
    fn->onFulfilled.vp = onFulfilled;
    fn->onRejected.sp = onRejected;
    this->chains.push_back(fn);
    EM_ASM_({
        var elem = Module['toPromise']($0);
        elem._value = elem._value.then(
            function() { return elem.callbackThenVP(); },
            function(v) { return elem.callbackRejectSP(v); }
        );
    }, this);
    return this;
}

Promise *Promise::then(PromiseVoidPromiseFunction onFulfilled, PromiseObjectPromiseFunction onRejected)
{
    auto fn = new PromiseChainFunction();
    fn->onFulfilled.vp = onFulfilled;
    fn->onRejected.op = onRejected;
    this->chains.push_back(fn);
    EM_ASM_({
        var elem = Module['toPromise']($0);
        elem._value = elem._value.then(
            function() { return elem.callbackThenVP(); },
            function(v) { return elem.callbackRejectOP(v); }
        );
    }, this);
    return this;
}

Promise *Promise::then(PromiseDoublePromiseFunction onFulfilled)
{
    auto fn = new PromiseChainFunction();
    fn->onFulfilled.dp = onFulfilled;
    this->chains.push_back(fn);
    EM_ASM_({
        var elem = Module['toPromise']($0);
        elem._value = elem._value.then(function(v) { return elem.callbackThenDP(v); });
    }, this);
    return this;
}

Promise *Promise::then(PromiseDoublePromiseFunction onFulfilled, PromiseVoidPromiseFunction onRejected)
{
    auto fn = new PromiseChainFunction();
    fn->onFulfilled.dp = onFulfilled;
    fn->onRejected.vp = onRejected;
    this->chains.push_back(fn);
    EM_ASM_({
        var elem = Module['toPromise']($0);
        elem._value = elem._value.then(
            function(v) { return elem.callbackThenDP(v); },
            function() { return elem.callbackRejectVP(); }
        );
    }, this);
    return this;
}

Promise *Promise::then(PromiseDoublePromiseFunction onFulfilled, PromiseDoublePromiseFunction onRejected)
{
    auto fn = new PromiseChainFunction();
    fn->onFulfilled.dp = onFulfilled;
    fn->onRejected.dp = onRejected;
    this->chains.push_back(fn);
    EM_ASM_({
        var elem = Module['toPromise']($0);
        elem._value = elem._value.then(
            function(v) { return elem.callbackThenDP(v); },
            function(v) { return elem.callbackRejectDP(v); }
        );
    }, this);
    return this;
}

Promise *Promise::then(PromiseDoublePromiseFunction onFulfilled, PromiseStringPromiseFunction onRejected)
{
    auto fn = new PromiseChainFunction();
    fn->onFulfilled.dp = onFulfilled;
    fn->onRejected.sp = onRejected;
    this->chains.push_back(fn);
    EM_ASM_({
        var elem = Module['toPromise']($0);
        elem._value = elem._value.then(
            function(v) { return elem.callbackThenDP(v); },
            function(v) { return elem.callbackRejectSP(v); }
        );
    }, this);
    return this;
}

Promise *Promise::then(PromiseDoublePromiseFunction onFulfilled, PromiseObjectPromiseFunction onRejected)
{
    auto fn = new PromiseChainFunction();
    fn->onFulfilled.dp = onFulfilled;
    fn->onRejected.op = onRejected;
    this->chains.push_back(fn);
    EM_ASM_({
        var elem = Module['toPromise']($0);
        elem._value = elem._value.then(
            function(v) { return elem.callbackThenDP(v); },
            function(v) { return elem.callbackRejectOP(v); }
        );
    }, this);
    return this;
}

Promise *Promise::then(PromiseStringPromiseFunction onFulfilled)
{
    auto fn = new PromiseChainFunction();
    fn->onFulfilled.sp = onFulfilled;
    this->chains.push_back(fn);
    EM_ASM_({
        var elem = Module['toPromise']($0);
        elem._value = elem._value.then(function(v) { return elem.callbackThenSP(v); });
    }, this);
    return this;
}



Promise *Promise::then(PromiseStringPromiseFunction onFulfilled, PromiseVoidPromiseFunction onRejected)
{
    auto fn = new PromiseChainFunction();
    fn->onFulfilled.sp = onFulfilled;
    fn->onRejected.vp = onRejected;
    this->chains.push_back(fn);
    EM_ASM_({
        var elem = Module['toPromise']($0);
        elem._value = elem._value.then(
            function(v) { return elem.callbackThenSP(v); },
            function() { return elem.callbackRejectVP(); }
        );
    }, this);
    return this;
}

Promise *Promise::then(PromiseStringPromiseFunction onFulfilled, PromiseDoublePromiseFunction onRejected)
{
    auto fn = new PromiseChainFunction();
    fn->onFulfilled.sp = onFulfilled;
    fn->onRejected.dp = onRejected;
    this->chains.push_back(fn);
    EM_ASM_({
        var elem = Module['toPromise']($0);
        elem._value = elem._value.then(
            function(v) { return elem.callbackThenSP(v); },
            function(v) { return elem.callbackRejectDP(v); }
        );
    }, this);
    return this;
}

Promise *Promise::then(PromiseStringPromiseFunction onFulfilled, PromiseStringPromiseFunction onRejected)
{
    auto fn = new PromiseChainFunction();
    fn->onFulfilled.sp = onFulfilled;
    fn->onRejected.sp = onRejected;
    this->chains.push_back(fn);
    EM_ASM_({
        var elem = Module['toPromise']($0);
        elem._value = elem._value.then(
            function(v) { return elem.callbackThenSP(v); },
            function(v) { return elem.callbackRejectSP(v); }
        );
    }, this);
    return this;
}

Promise *Promise::then(PromiseStringPromiseFunction onFulfilled, PromiseObjectPromiseFunction onRejected)
{
    auto fn = new PromiseChainFunction();
    fn->onFulfilled.sp = onFulfilled;
    fn->onRejected.op = onRejected;
    this->chains.push_back(fn);
    EM_ASM_({
        var elem = Module['toPromise']($0);
        elem._value = elem._value.then(
            function(v) { return elem.callbackThenSP(v); },
            function(v) { return elem.callbackRejectOP(v); }
        );
    }, this);
    return this;
}

emscripten::val Promise::callbackThenVP()
{
    PromiseChainFunction *chain = this->chains[0];
    auto func = chain->onFulfilled.vp;
    Promise *p = func();
    this->chains.erase(this->chains.begin());
    delete chain;
    if (p == nullptr) {
        return emscripten::val(0);
    }
    return p->v;
}

emscripten::val Promise::callbackThenDP(emscripten::val v)
{
    PromiseChainFunction *chain = this->chains[0];
    auto func = chain->onFulfilled.dp;
    Promise *p = func(v.as<double>());
    this->chains.erase(this->chains.begin());
    delete chain;
    if (p == nullptr) {
        return emscripten::val(0);
    }
    return p->v;
}

emscripten::val Promise::callbackThenSP(emscripten::val v)
{
    PromiseChainFunction *chain = this->chains[0];
    auto func = chain->onFulfilled.sp;
    Promise *p = func(v.as<std::string>());
    this->chains.erase(this->chains.begin());
    delete chain;
    if (p == nullptr) {
        return emscripten::val(0);
    }
    return p->v;
}

emscripten::val Promise::callbackThenOP(emscripten::val v)
{
    PromiseChainFunction *chain = this->chains[0];
    auto func = chain->onFulfilled.op;
    Promise *p = func(Object(v));
    this->chains.erase(this->chains.begin());
    delete chain;
    if (p == nullptr) {
        return emscripten::val(0);
    }
    return p->v;
}

emscripten::val Promise::callbackRejectVP()
{
    PromiseChainFunction *chain = this->chains[0];
    auto func = chain->onRejected.vp;
    Promise *p = func();
    this->chains.erase(this->chains.begin());
    delete chain;
    if (p == nullptr) {
        return emscripten::val(0);
    }
    return p->v;
}

emscripten::val Promise::callbackRejectDP(emscripten::val v)
{
    PromiseChainFunction *chain = this->chains[0];
    auto func = chain->onRejected.dp;
    Promise *p = func(v.as<double>());
    this->chains.erase(this->chains.begin());
    delete chain;
    if (p == nullptr) {
        return emscripten::val(0);
    }
    return p->v;
}

emscripten::val Promise::callbackRejectSP(emscripten::val v)
{
    PromiseChainFunction *chain = this->chains[0];
    auto func = chain->onRejected.sp;
    Promise *p = func(v.as<std::string>());
    this->chains.erase(this->chains.begin());
    delete chain;
    if (p == nullptr) {
        return emscripten::val(0);
    }
    return p->v;
}

emscripten::val Promise::callbackRejectOP(emscripten::val v)
{
    PromiseChainFunction *chain = this->chains[0];
    auto func = chain->onRejected.op;
    Promise *p = func(Object(v));
    this->chains.erase(this->chains.begin());
    delete chain;
    if (p == nullptr) {
        return emscripten::val(0);
    }
    return p->v;
}

HTML5_BIND_METHOD(Promise, callbackThenVP);
HTML5_BIND_METHOD(Promise, callbackThenDP);
HTML5_BIND_METHOD(Promise, callbackThenSP);
HTML5_BIND_METHOD(Promise, callbackThenOP);
HTML5_BIND_METHOD(Promise, callbackRejectVP);
HTML5_BIND_METHOD(Promise, callbackRejectDP);
HTML5_BIND_METHOD(Promise, callbackRejectSP);
HTML5_BIND_METHOD(Promise, callbackRejectOP);


Promise *Promise::catchError(PromiseVoidPromiseFunction onRejected)
{
    this->catchErrorFn.vp = onRejected;
    EM_ASM_({
        var elem = Module['toPromise']($0);
        elem._value = elem._value.catch(
            function() { return elem.callbackCatchVP(); }
        );
    }, this);
    return this;
}

Promise *Promise::catchError(PromiseDoublePromiseFunction onRejected)
{
    this->catchErrorFn.dp = onRejected;
    EM_ASM_({
        var elem = Module['toPromise']($0);
        elem._value = elem._value.catch(
            function(v) { return elem.callbackCatchDP(v); }
        );
    }, this);
    return this;
}

Promise *Promise::catchError(PromiseStringPromiseFunction onRejected)
{
    this->catchErrorFn.sp = onRejected;
    EM_ASM_({
        var elem = Module['toPromise']($0);
        elem._value = elem._value.catch(
            function(v) { return elem.callbackCatchSP(v); }
        );
    }, this);
    return this;
}
    
Promise *Promise::catchError(PromiseObjectPromiseFunction onRejected)
{
    this->catchErrorFn.op = onRejected;
    EM_ASM_({
        var elem = Module['toPromise']($0);
        elem._value = elem._value.catch(
            function(v) { return elem.callbackCatchOP(v); }
        );
    }, this);
    return this;
}

Promise *Promise::finally(PromiseVoidPromiseFunction onFinally)
{
    this->finallyFn.vp = onFinally;
    EM_ASM_({
        var elem = Module['toPromise']($0);
        elem._value = elem._value.finally(
            function() { return elem.callbackFinally(); }
        );
    }, this);
    return this;
}

emscripten::val Promise::callbackCatchVP()
{
    Promise *p = this->catchErrorFn.vp();
    if (p == nullptr) {
        return emscripten::val(0);
    }
    return p->v;
}

emscripten::val Promise::callbackCatchDP(emscripten::val v)
{
    Promise *p = this->catchErrorFn.dp(v.as<double>());
    if (p == nullptr) {
        return emscripten::val(0);
    }
    return p->v;
}

emscripten::val Promise::callbackCatchSP(emscripten::val v)
{
    Promise *p = this->catchErrorFn.sp(v.as<std::string>());
    if (p == nullptr) {
        return emscripten::val(0);
    }
    return p->v;
}

emscripten::val Promise::callbackCatchOP(emscripten::val v)
{
    Promise *p = this->catchErrorFn.op(Object(v));
    if (p == nullptr) {
        return emscripten::val(0);
    }
    return p->v;
}

emscripten::val Promise::callbackFinally()
{
    Promise *p = this->finallyFn.vp();
    if (p == nullptr) {
        return emscripten::val(0);
    }
    return p->v;
}

HTML5_BIND_METHOD(Promise, callbackCatchVP);
HTML5_BIND_METHOD(Promise, callbackCatchDP);
HTML5_BIND_METHOD(Promise, callbackCatchSP);
HTML5_BIND_METHOD(Promise, callbackCatchOP);
HTML5_BIND_METHOD(Promise, callbackFinally);


Promise *Promise::all(std::vector<Promise *> iterable)
{
    emscripten::val array = toJSArray<Promise *>(iterable);
    auto promise = HTML5_STATIC_PRIMITIVE_INSTANCE(Promise);
    return Promise::create(HTML5_CALLv(promise, all, array));
}

Promise *Promise::race(std::vector<Promise *> iterable)
{
    emscripten::val array = toJSArray<Promise *>(iterable);
    auto promise = HTML5_STATIC_PRIMITIVE_INSTANCE(Promise);
    return Promise::create(HTML5_CALLv(promise, race, array));
}

Promise *Promise::reject()
{
    auto promise = HTML5_STATIC_PRIMITIVE_INSTANCE(Promise);
    return Promise::create(HTML5_CALLv(promise, reject));
}

Promise *Promise::reject(double value)
{
    auto promise = HTML5_STATIC_PRIMITIVE_INSTANCE(Promise);
    return Promise::create(HTML5_CALLv(promise, reject, value));
}

Promise *Promise::reject(const std::string &value)
{
    auto promise = HTML5_STATIC_PRIMITIVE_INSTANCE(Promise);
    return Promise::create(HTML5_CALLv(promise, reject, value));
}

Promise *Promise::reject(Object *value)
{
    auto promise = HTML5_STATIC_PRIMITIVE_INSTANCE(Promise);
    return Promise::create(HTML5_CALLv(promise, reject, value->v));
}

Promise *Promise::resolve()
{
    auto promise = HTML5_STATIC_PRIMITIVE_INSTANCE(Promise);
    return Promise::create(HTML5_CALLv(promise, resolve));
}

Promise *Promise::resolve(double value)
{
    auto promise = HTML5_STATIC_PRIMITIVE_INSTANCE(Promise);
    return Promise::create(HTML5_CALLv(promise, resolve, value));
}

Promise *Promise::resolve(const std::string &value)
{
    auto promise = HTML5_STATIC_PRIMITIVE_INSTANCE(Promise);
    return Promise::create(HTML5_CALLv(promise, resolve, value));
}

Promise *Promise::resolve(Object *value)
{
    auto promise = HTML5_STATIC_PRIMITIVE_INSTANCE(Promise);
    return Promise::create(HTML5_CALLv(promise, resolve, value->v));
}

HTML5_PROPERTY_IMPL(Promise, unsigned long, length);

