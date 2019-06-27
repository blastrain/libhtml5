cmake_minimum_required (VERSION 3.0.2)

set(ENABLE_EMSCRIPTEN $ENV{ENABLE_EMSCRIPTEN})

include_directories(../include)

if ($ENV{ENABLE_EMSCRIPTEN})
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Oz -g -std=c++11 --memory-init-file 0 --llvm-lto 1 --bind -s DEMANGLE_SUPPORT=1 -s WASM=0 -s NO_FILESYSTEM=1 -DENABLE_EMSCRIPTEN=1 -DPROPERTY_TRACE=1")
   link_directories(../build)
   link_libraries("-lhtml5")
   add_executable(libhtml5_example image.cc video.cc style_sheet.cc array.cc string.cc test_exec.cc)
else()
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g -std=c++11")
   link_libraries("-lhtml5")
   add_executable(libhtml5_example image.cc video.cc style_sheet.cc array.cc string.cc test_exec.cc)
endif()
