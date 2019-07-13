# libhtml5
minimum html5 library for your C++ code running on web browser

# Status

This project is under development.  
Interface may change without notice.

# Motivation

## 1. Convert existing JavaScript into WebAssembly

Of course, we know story about JavaScript => TypeScript => AssemblyScript => WebAssembly . It is good solution !  
Similarly, we think good about Emscripten too. It can compile from C/C++ to pure JavaScript ( with `asm.js` ) or WebAssembly.  
Also, Emscripten supports bridge for Web Browser APIs, but not easy to use it.  

So, we support easy to use bridge as if call Web Browser API in JavaScript for Emscripten.

Our goal is support to write all existing JavaScript in C++ easily. ( and convert WebAssembly )

## 2. Introduce Web Technology into Native Application (e.g. iOS or Android ).

We know some project that port Native Application source codes to Web Application.  
But, we want to support another approach.  
`libhtml5` supports multi platform ( `iOS` / `Android` / `Web Browser` ) for HTML5 API .
For example, the following code work `iOS` and `Android` and `Web Browser` .

```cpp
html5::HTMLImageElement *image = html5::HTMLImageElement::create();
image->onload = [image](html5::Event *e){
    std::cout << "callback: onload" << std::endl;
    std::cout << "width = " << image->width << std::endl;
    std::cout << "height = " << image->height << std::endl;
    std::cout << "naturalWidth = " << image->naturalWidth << std::endl;
    std::cout << "naturalHeight = " << image->naturalHeight << std::endl;
};
image->src = url;
html5::window->document->body->appendChild(image);
```

If the above code is running on iOS, `HTMLImageElement` work as `UIImage` . 

# Example

## Console

Can use `console.log` for debug.
Of course, also can use print debugging in C++ feature ( `std::cout` ).

```cpp
html5::console->log(html5::HTMLImageElement::create());
```

## String

`html5::string` is compatible `String` class in Browser .

```cpp
html5::string s = "hello world";
for (const auto &splitted : s.split(" ")) {
    html5::string v = splitted;
    std::cout << v << std::endl;
    std::cout << "includes h? " << std::boolalpha << v.includes("h") << std::endl;
}
```

## Array

Supports multiple type into Array.

```cpp
html5::array subarray;
html5::array array = {
    1, M_PI, "hello", subarray,
};
```

## Image

```cpp
auto image = html5::HTMLImageElement::create();
image->onload = [](html5::Event *e){
    std::cout << "onload" << std::endl;
};
image->src = "https://example.com/images/01.png";
html5::document->body->appendChild(image);
```

## Promise

```cpp
html5::fetch("https://example.com/images/01.png")->then<html5::Response *>([](html5::Response *response) {
    return response->blob();
})->then<html5::Blob *>([](html5::Blob *blob) {
    auto reader = html5::FileReader::create();
    reader->onload = [reader](html5::Event *event) {
        std::string data = reader->result;
        auto image = html5::HTMLImageElement::create();
        image->src = data;
        html5::document->body->appendChild(image);
    };
    reader->readAsDataURL(blob);
    return nullptr;
})->catchError([]{
    html5::console->log("catch");
    return nullptr;
})->finally([]{
    html5::console->log("finally");
    return nullptr;
});
```

# How to use

## Start docker container for building environment

```
$ docker-compose up -d
```

## Build libhtml5.a

```
$ docker exec -it libhtml5 bash
( ... running on container ... )
$ mkdir build
$ mv build
$ ENABLE_EMSCRIPTEN=1 emcmake cmake ../
$ make
```

Generated `libhtml5.a` in build directory

## Build examples

```
$ docker exec -it libhtml5 bash
( ... running on container ... )
$ mv examples
$ mkdir build
$ mv build
$ ENABLE_EMSCRIPTEN=1 emcmake cmake ../
$ make
```

Generated `libhtml5_example.js` in examples/build directory

## Start simple application with libhtml5_example.js

### Serve simple application

- index.html

```html
<html>
  <head>
    <script src="libhtml5_example.js"></script>
  </head>
</html>
```

### Execute example

Open Developer Console, and executes the following.

- `Module.arrayTest()`
- `Module.executeTest()`
- `Module.stringTest()`
- `Module.promiseTest()`
- `Module.fetchImageTest("image url")`
