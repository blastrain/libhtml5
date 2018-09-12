cmake_minimum_required (VERSION 3.0.2)

set(ENABLE_EMSCRIPTEN $ENV{ENABLE_EMSCRIPTEN})

include_directories(include)

set(SOURCES src/array.cc
            src/auto_release_pool.cc
            src/object.cc
            src/attr.cc
            src/audio_track.cc
            src/audio_track_list.cc
            src/css_style_declaration.cc
            src/css_rule.cc
            src/css_rule_list.cc
            src/date.cc
            src/style_sheet.cc
            src/text_track.cc
            src/text_track_list.cc
            src/text_track_cue.cc
            src/text_track_cue_list.cc
            src/video_track_list.cc
            src/video_track.cc
            src/media_list.cc
            src/media_controller.cc
            src/media_error.cc
            src/time_ranges.cc
            src/html_collection.cc
            src/dom_token_list.cc
            src/node_list.cc
            src/event_target.cc
            src/event.cc
            src/node.cc
            src/element.cc
            src/html_element.cc
            src/html_image_element.cc
            src/html_media_element.cc
            src/document.cc
            src/html_video_element.cc
            src/html_source_element.cc
            src/window.cc
            src/promise.cc
            src/blob.cc
            src/html_canvas_element.cc
            src/rendering_context.cc
            src/canvas_rendering_context_2d.cc
            src/webgl_rendering_context.cc
            src/text_metrics.cc
            src/path2d.cc
            src/svgmatrix.cc
            src/canvas_gradient.cc
            src/canvas_pattern.cc
            src/hit_region_options.cc
            src/array_buffer.cc
            src/array_buffer_view.cc
            src/uint8_clamped_array.cc
            src/image_data.cc
            src/image_bitmap.cc
            )

if ($ENV{ENABLE_EMSCRIPTEN})
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g -std=c++11 --memory-init-file 0 --llvm-lto 1 --bind -s DEMANGLE_SUPPORT=1 -s WASM=0 -s NO_FILESYSTEM=1 -DENABLE_EMSCRIPTEN=1")
   add_executable(create-video main.cc ${SOURCES})
else()
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g -std=c++11")
   add_library(html5 STATIC ${SOURCES})
endif()
