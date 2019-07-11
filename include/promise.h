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
    Promise *then(PromiseVoidPromiseFunction onFulfilled);
    Promise *then(PromiseVoidPromiseFunction onFulfilled, PromiseVoidPromiseFunction onRejected);
    Promise *then(PromiseVoidPromiseFunction onFulfilled, PromiseDoublePromiseFunction onRejected);
    Promise *then(PromiseVoidPromiseFunction onFulfilled, PromiseStringPromiseFunction onRejected);
    Promise *then(PromiseVoidPromiseFunction onFulfilled, PromiseObjectPromiseFunction onRejected);
    Promise *then(PromiseDoublePromiseFunction onFulfilled);
    Promise *then(PromiseDoublePromiseFunction onFulfilled, PromiseVoidPromiseFunction onRejected);
    Promise *then(PromiseDoublePromiseFunction onFulfilled, PromiseDoublePromiseFunction onRejected);
    Promise *then(PromiseDoublePromiseFunction onFulfilled, PromiseStringPromiseFunction onRejected);
    Promise *then(PromiseDoublePromiseFunction onFulfilled, PromiseObjectPromiseFunction onRejected);
    Promise *then(PromiseStringPromiseFunction onFulfilled);
    Promise *then(PromiseStringPromiseFunction onFulfilled, PromiseVoidPromiseFunction onRejected);
    Promise *then(PromiseStringPromiseFunction onFulfilled, PromiseDoublePromiseFunction onRejected);
    Promise *then(PromiseStringPromiseFunction onFulfilled, PromiseStringPromiseFunction onRejected);
    Promise *then(PromiseStringPromiseFunction onFulfilled, PromiseObjectPromiseFunction onRejected);
    template<typename T> Promise *then(std::function<Promise *(T)> onFulfilled) {
      auto fn = new PromiseChainFunction();
      PromiseObjectPromiseFunction f = [onFulfilled](const Object &o) {
          return onFulfilled((T)(&o));
      };
      fn->onFulfilled.op = f;
      this->chains.push_back(fn);
      EM_ASM_({
        var elem = Module['toPromise']($0);
        elem._value = elem._value.then(function(v) { return elem.callbackThenOP(v); });
      }, this);
      return this;
    };
    template<typename T> Promise *then(std::function<Promise *(T)> onFulfilled, PromiseVoidPromiseFunction onRejected) {
      auto fn = new PromiseChainFunction();
      PromiseObjectPromiseFunction f = [onFulfilled](const Object &o) {
          return onFulfilled((T)(&o));
      };
      fn->onFulfilled.op = f;
      fn->onRejected.vp = onRejected;
      this->chains.push_back(fn);
      EM_ASM_({
        var elem = Module['toPromise']($0);
        elem._value = elem._value.then(
            function(v) { return elem.callbackThenOP(v); },
            function() { return elem.callbackRejectVP(); }
        );
      }, this);
      return this;
    };
    template<typename T> Promise *then(std::function<Promise *(T)> onFulfilled, PromiseDoublePromiseFunction onRejected) {
      auto fn = new PromiseChainFunction();
      PromiseObjectPromiseFunction f = [onFulfilled](const Object &o) {
          return onFulfilled((T)(&o));
      };
      fn->onFulfilled.op = f;
      fn->onRejected.dp = onRejected;
      this->chains.push_back(fn);
      EM_ASM_({
        var elem = Module['toPromise']($0);
        elem._value = elem._value.then(
            function(v) { return elem.callbackThenOP(v); },
            function(v) { return elem.callbackRejectDP(v); }
        );
      }, this);
      return this;
    };
    template<typename T> Promise *then(std::function<Promise *(T)> onFulfilled, PromiseStringPromiseFunction onRejected) {
      auto fn = new PromiseChainFunction();
      PromiseObjectPromiseFunction f = [onFulfilled](const Object &o) {
          return onFulfilled((T)(&o));
      };
      fn->onFulfilled.op = f;
      fn->onRejected.sp = onRejected;
      this->chains.push_back(fn);
      EM_ASM_({
        var elem = Module['toPromise']($0);
        elem._value = elem._value.then(
            function(v) { return elem.callbackThenOP(v); },
            function(v) { return elem.callbackRejectSP(v); }
        );
      }, this);
      return this;
    };
    template<typename T> Promise *then(std::function<Promise *(T)> onFulfilled, PromiseObjectPromiseFunction onRejected) {
      auto fn = new PromiseChainFunction();
      PromiseObjectPromiseFunction f = [onFulfilled](const Object &o) {
          return onFulfilled((T)(&o));
      };
      fn->onFulfilled.op = f;
      fn->onRejected.op = onRejected;
      this->chains.push_back(fn);
      EM_ASM_({
        var elem = Module['toPromise']($0);
        elem._value = elem._value.then(
            function(v) { return elem.callbackThenOP(); },
            function(v) { return elem.callbackRejectOP(v); }
        );
      }, this);
      return this;
    };
    Promise *catchError(PromiseVoidPromiseFunction onRejected);
    Promise *catchError(PromiseDoublePromiseFunction onRejected);
    Promise *catchError(PromiseStringPromiseFunction onRejected);
    Promise *catchError(PromiseObjectPromiseFunction onRejected);
    Promise *finally(PromiseVoidPromiseFunction onFinally);
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
        PromiseVoidPromiseFunction vp;
        PromiseDoublePromiseFunction dp;
        PromiseStringPromiseFunction sp;
        PromiseObjectPromiseFunction op;
        PromiseFunction() : vp([]{return nullptr;}) {};
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
    PromiseFunction catchErrorFn;
    PromiseFunction finallyFn;
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
    emscripten::val callbackCatchVP();
    emscripten::val callbackCatchDP(emscripten::val v);
    emscripten::val callbackCatchSP(emscripten::val v);
    emscripten::val callbackCatchOP(emscripten::val v);
    emscripten::val callbackFinally();
};

NAMESPACE_HTML5_END;
