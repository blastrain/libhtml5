#pragma once

#include "libhtml5.h"
#include <functional>

NAMESPACE_HTML5_BEGIN;

typedef std::function<void()> PromiseVoidFunction;
typedef std::function<void(double)> PromiseDoubleFunction;
typedef std::function<void(const std::string&)> PromiseStringFunction;
typedef std::function<void(const Object&)> PromiseObjectFunction;

typedef std::function<Promise*()> PromiseVoidPromiseFunction;
typedef std::function<Promise*(double)> PromiseDoublePromiseFunction;
typedef std::function<Promise*(const std::string&)> PromiseStringPromiseFunction;
typedef std::function<Promise*(const Object&)> PromiseObjectPromiseFunction;

typedef std::function<void(PromiseVoidFunction, PromiseVoidFunction)>   PromiseVoidVoidPairFunction;
typedef std::function<void(PromiseVoidFunction, PromiseDoubleFunction)> PromiseVoidDoublePairFunction;
typedef std::function<void(PromiseVoidFunction, PromiseStringFunction)> PromiseVoidStringPairFunction;
typedef std::function<void(PromiseVoidFunction, PromiseObjectFunction)> PromiseVoidObjectPairFunction;

typedef std::function<void(PromiseDoubleFunction, PromiseVoidFunction)>   PromiseDoubleVoidPairFunction;
typedef std::function<void(PromiseDoubleFunction, PromiseDoubleFunction)> PromiseDoubleDoublePairFunction;
typedef std::function<void(PromiseDoubleFunction, PromiseStringFunction)> PromiseDoubleStringPairFunction;
typedef std::function<void(PromiseDoubleFunction, PromiseObjectFunction)> PromiseDoubleObjectPairFunction;

typedef std::function<void(PromiseStringFunction, PromiseVoidFunction)>   PromiseStringVoidPairFunction;
typedef std::function<void(PromiseStringFunction, PromiseDoubleFunction)> PromiseStringDoublePairFunction;
typedef std::function<void(PromiseStringFunction, PromiseStringFunction)> PromiseStringStringPairFunction;
typedef std::function<void(PromiseStringFunction, PromiseObjectFunction)> PromiseStringObjectPairFunction;

typedef std::function<void(PromiseObjectFunction, PromiseVoidFunction)>   PromiseObjectVoidPairFunction;
typedef std::function<void(PromiseObjectFunction, PromiseDoubleFunction)> PromiseObjectDoublePairFunction;
typedef std::function<void(PromiseObjectFunction, PromiseStringFunction)> PromiseObjectStringPairFunction;
typedef std::function<void(PromiseObjectFunction, PromiseObjectFunction)> PromiseObjectObjectPairFunction;


class Promise : public Object {
public:

    HTML5_PROPERTY(Promise, unsigned long, length);

    Promise(emscripten::val v);
    virtual ~Promise();
    static Promise *create(PromiseVoidVoidPairFunction fn);
    static Promise *create(PromiseVoidDoublePairFunction fn);
    static Promise *create(PromiseVoidStringPairFunction fn);
    static Promise *create(PromiseVoidObjectPairFunction fn);
    static Promise *create(PromiseDoubleVoidPairFunction fn);
    static Promise *create(PromiseDoubleDoublePairFunction fn);
    static Promise *create(PromiseDoubleStringPairFunction fn);
    static Promise *create(PromiseDoubleObjectPairFunction fn);
    static Promise *create(PromiseStringVoidPairFunction fn);
    static Promise *create(PromiseStringDoublePairFunction fn);
    static Promise *create(PromiseStringStringPairFunction fn);
    static Promise *create(PromiseStringObjectPairFunction fn);
    static Promise *create(PromiseObjectVoidPairFunction fn);
    static Promise *create(PromiseObjectDoublePairFunction fn);
    static Promise *create(PromiseObjectStringPairFunction fn);
    static Promise *create(PromiseObjectObjectPairFunction fn);
    static Promise *create(emscripten::val v);
    Promise *then(PromiseVoidFunction onFulfilled);
    Promise *then(PromiseVoidFunction onFulfilled, PromiseVoidFunction onRejected);
    Promise *then(PromiseVoidFunction onFulfilled, PromiseDoubleFunction onRejected);
    Promise *then(PromiseVoidFunction onFulfilled, PromiseStringFunction onRejected);
    Promise *then(PromiseVoidFunction onFulfilled, PromiseObjectFunction onRejected);
    Promise *then(PromiseVoidPromiseFunction onFulfilled);
    Promise *then(PromiseVoidPromiseFunction onFulfilled, PromiseVoidFunction onRejected);
    Promise *then(PromiseVoidPromiseFunction onFulfilled, PromiseDoubleFunction onRejected);
    Promise *then(PromiseVoidPromiseFunction onFulfilled, PromiseStringFunction onRejected);
    Promise *then(PromiseVoidPromiseFunction onFulfilled, PromiseObjectFunction onRejected);
    Promise *then(PromiseVoidPromiseFunction onFulfilled, PromiseVoidPromiseFunction onRejected);
    Promise *then(PromiseVoidPromiseFunction onFulfilled, PromiseDoublePromiseFunction onRejected);
    Promise *then(PromiseVoidPromiseFunction onFulfilled, PromiseStringPromiseFunction onRejected);
    Promise *then(PromiseVoidPromiseFunction onFulfilled, PromiseObjectPromiseFunction onRejected);
    Promise *then(PromiseDoubleFunction onFulfilled);
    Promise *then(PromiseDoubleFunction onFulfilled, PromiseVoidFunction onRejected);
    Promise *then(PromiseDoubleFunction onFulfilled, PromiseDoubleFunction onRejected);
    Promise *then(PromiseDoubleFunction onFulfilled, PromiseStringFunction onRejected);
    Promise *then(PromiseDoubleFunction onFulfilled, PromiseObjectFunction onRejected);
    Promise *then(PromiseDoublePromiseFunction onFulfilled);
    Promise *then(PromiseDoublePromiseFunction onFulfilled, PromiseVoidFunction onRejected);
    Promise *then(PromiseDoublePromiseFunction onFulfilled, PromiseDoubleFunction onRejected);
    Promise *then(PromiseDoublePromiseFunction onFulfilled, PromiseStringFunction onRejected);
    Promise *then(PromiseDoublePromiseFunction onFulfilled, PromiseObjectFunction onRejected);
    Promise *then(PromiseDoublePromiseFunction onFulfilled, PromiseVoidPromiseFunction onRejected);
    Promise *then(PromiseDoublePromiseFunction onFulfilled, PromiseDoublePromiseFunction onRejected);
    Promise *then(PromiseDoublePromiseFunction onFulfilled, PromiseStringPromiseFunction onRejected);
    Promise *then(PromiseDoublePromiseFunction onFulfilled, PromiseObjectPromiseFunction onRejected);
    Promise *then(PromiseStringFunction onFulfilled);
    Promise *then(PromiseStringFunction onFulfilled, PromiseVoidFunction onRejected);
    Promise *then(PromiseStringFunction onFulfilled, PromiseDoubleFunction onRejected);
    Promise *then(PromiseStringFunction onFulfilled, PromiseStringFunction onRejected);
    Promise *then(PromiseStringFunction onFulfilled, PromiseObjectFunction onRejected);
    Promise *then(PromiseStringPromiseFunction onFulfilled);
    Promise *then(PromiseStringPromiseFunction onFulfilled, PromiseVoidFunction onRejected);
    Promise *then(PromiseStringPromiseFunction onFulfilled, PromiseDoubleFunction onRejected);
    Promise *then(PromiseStringPromiseFunction onFulfilled, PromiseStringFunction onRejected);
    Promise *then(PromiseStringPromiseFunction onFulfilled, PromiseObjectFunction onRejected);
    Promise *then(PromiseStringPromiseFunction onFulfilled, PromiseVoidPromiseFunction onRejected);
    Promise *then(PromiseStringPromiseFunction onFulfilled, PromiseDoublePromiseFunction onRejected);
    Promise *then(PromiseStringPromiseFunction onFulfilled, PromiseStringPromiseFunction onRejected);
    Promise *then(PromiseStringPromiseFunction onFulfilled, PromiseObjectPromiseFunction onRejected);
    Promise *then(PromiseObjectFunction onFulfilled);
    Promise *then(PromiseObjectFunction onFulfilled, PromiseVoidFunction onRejected);
    Promise *then(PromiseObjectFunction onFulfilled, PromiseDoubleFunction onRejected);
    Promise *then(PromiseObjectFunction onFulfilled, PromiseStringFunction onRejected);
    Promise *then(PromiseObjectFunction onFulfilled, PromiseObjectFunction onRejected);
    Promise *then(PromiseObjectPromiseFunction onFulfilled);
    Promise *then(PromiseObjectPromiseFunction onFulfilled, PromiseVoidFunction onRejected);
    Promise *then(PromiseObjectPromiseFunction onFulfilled, PromiseDoubleFunction onRejected);
    Promise *then(PromiseObjectPromiseFunction onFulfilled, PromiseStringFunction onRejected);
    Promise *then(PromiseObjectPromiseFunction onFulfilled, PromiseObjectFunction onRejected);
    Promise *then(PromiseObjectPromiseFunction onFulfilled, PromiseVoidPromiseFunction onRejected);
    Promise *then(PromiseObjectPromiseFunction onFulfilled, PromiseDoublePromiseFunction onRejected);
    Promise *then(PromiseObjectPromiseFunction onFulfilled, PromiseStringPromiseFunction onRejected);
    Promise *then(PromiseObjectPromiseFunction onFulfilled, PromiseObjectPromiseFunction onRejected);
    Promise *all(std::vector<Promise *> iterable);
    Promise *race(std::vector<Promise *> iterable);
    Promise *reject(std::string reason);
    Promise *resolve(void *value);
    Promise *pcatch(std::function<Promise*(Promise*)> onRejected);

    PromiseVoidVoidPairFunction vvPairFn;
    PromiseVoidDoublePairFunction vdPairFn;
    PromiseVoidStringPairFunction vsPairFn;
    PromiseVoidObjectPairFunction voPairFn;
    PromiseDoubleVoidPairFunction dvPairFn;
    PromiseDoubleDoublePairFunction ddPairFn;
    PromiseDoubleStringPairFunction dsPairFn;
    PromiseDoubleObjectPairFunction doPairFn;
    PromiseStringVoidPairFunction svPairFn;
    PromiseStringDoublePairFunction sdPairFn;
    PromiseStringStringPairFunction ssPairFn;
    PromiseStringObjectPairFunction soPairFn;
    PromiseObjectVoidPairFunction ovPairFn;
    PromiseObjectDoublePairFunction odPairFn;
    PromiseObjectStringPairFunction osPairFn;
    PromiseObjectObjectPairFunction ooPairFn;

    union PromiseFunction {
        PromiseVoidFunction v;
        PromiseDoubleFunction d;
        PromiseStringFunction s;
        PromiseObjectFunction o;
        PromiseVoidPromiseFunction vp;
        PromiseDoublePromiseFunction dp;
        PromiseStringPromiseFunction sp;
        PromiseObjectPromiseFunction op;
        PromiseFunction() : v([]{}) {};
        ~PromiseFunction(){};
    };

    class PromiseChainFunction {
    public:
        PromiseFunction onFulfilled;
        PromiseFunction onRejected;
        PromiseChainFunction(){};
        ~PromiseChainFunction(){};
    };

    std::vector<PromiseChainFunction *> chains;
    void callbackVV(emscripten::val resolve, emscripten::val reject);
    void callbackVD(emscripten::val resolve, emscripten::val reject);
    void callbackVS(emscripten::val resolve, emscripten::val reject);
    void callbackVO(emscripten::val resolve, emscripten::val reject);
    void callbackDV(emscripten::val resolve, emscripten::val reject);
    void callbackDD(emscripten::val resolve, emscripten::val reject);
    void callbackDS(emscripten::val resolve, emscripten::val reject);
    void callbackDO(emscripten::val resolve, emscripten::val reject);
    void callbackSV(emscripten::val resolve, emscripten::val reject);
    void callbackSD(emscripten::val resolve, emscripten::val reject);
    void callbackSS(emscripten::val resolve, emscripten::val reject);
    void callbackSO(emscripten::val resolve, emscripten::val reject);
    void callbackOV(emscripten::val resolve, emscripten::val reject);
    void callbackOD(emscripten::val resolve, emscripten::val reject);
    void callbackOS(emscripten::val resolve, emscripten::val reject);
    void callbackOO(emscripten::val resolve, emscripten::val reject);
    void callbackThenV();
    void callbackThenD(emscripten::val v);
    void callbackThenS(emscripten::val v);
    void callbackThenO(emscripten::val v);
    void callbackRejectV();
    void callbackRejectD(emscripten::val v);
    void callbackRejectS(emscripten::val v);
    void callbackRejectO(emscripten::val v);
    emscripten::val callbackThenVP();
    emscripten::val callbackThenDP(emscripten::val v);
    emscripten::val callbackThenSP(emscripten::val v);
    emscripten::val callbackThenOP(emscripten::val v);
    emscripten::val callbackRejectVP();
    emscripten::val callbackRejectDP(emscripten::val v);
    emscripten::val callbackRejectSP(emscripten::val v);
    emscripten::val callbackRejectOP(emscripten::val v);
};

NAMESPACE_HTML5_END;
