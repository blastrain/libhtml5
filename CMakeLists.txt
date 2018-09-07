cmake_minimum_required (VERSION 3.0.2)

include_directories(include)

set(SOURCES src/attr.cc
            src/html_collection.cc
            src/dom_token_list.cc
            src/node_list.cc
            src/event_target.cc
            src/event.cc
            src/node.cc
            src/element.cc
            src/html_element.cc
            src/html_media_element.cc
            src/document.cc
            src/html_video_element.cc
            src/html_source_element.cc
            )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g -std=c++11 --memory-init-file 0 --llvm-lto 1 --bind -s DEMANGLE_SUPPORT=1 -s WASM=0 -s NO_FILESYSTEM=1")
add_executable(create-video main.cc ${SOURCES})
