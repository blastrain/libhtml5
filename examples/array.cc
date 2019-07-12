#include "libhtml5.h"
#include "class.h"
#include <math.h>
#include "runtime.h"

static void arrayTest()
{
    html5::array subarray;
    html5::array array = {
        1, M_PI, "hello", subarray, html5::Object::create(),
    };
    html5::window->console->log("array = ", array);

    int ivalue = array[0];
    html5::window->console->log("array[0] = ", ivalue);

    double fvalue = array[1];
    html5::window->console->log("array[1] = ", fvalue);

    std::string svalue = array[2];
    html5::window->console->log("array[2] = ", svalue);

    html5::array *avalue = array[3];
    html5::window->console->log("array[3] = ", avalue);

    html5::Object *ovalue = array[4];
    html5::window->console->log("array[4] = ", ovalue);

    int index = 0;
    for (const auto &e : array) {
        switch (index) {
        case 0:
            html5::window->console->log((int)e);
            break;
        case 1:
            html5::window->console->log((double)e);
            break;
        case 2:
            html5::window->console->log((std::string)e);
            break;
        case 3:
            html5::window->console->log((html5::array)e);
            break;
        case 4:
            html5::window->console->log((html5::Object *)e);
            break;
        }
        index++;
    }

    array.forEach([](const html5::array::Element &e, int index){
        html5::window->console->log(index);
    });
}

EMSCRIPTEN_BINDINGS(Array) {
    emscripten::function("arrayTest", &arrayTest);
}
