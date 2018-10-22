#include "libhtml5.h"
#include "class.h"

static void stringTest()
{
    HTML5_INIT();

    {
        html5::string s = "hello world";
        std::cout << s << std::endl;
        html5::window->console->log(s);
    }
    {
        std::string s = "hello";
        html5::string s2 = s;
        s2 += "world";
        std::cout << s2 << std::endl;
    }
    {
        html5::string a = "hello";
        html5::string b = "world";
        html5::string c = a + b;
        std::cout << c << std::endl;
    }
    {
        html5::string s = "hello world";
        for (const auto &splitted : *s.split(" ")) {
            html5::string v = splitted;
            std::cout << v << std::endl;
            std::cout << "includes h? " << v.includes("h") << std::endl;
        }
    }
}

EMSCRIPTEN_BINDINGS(string) {
    emscripten::function("stringTest", &stringTest);
}
