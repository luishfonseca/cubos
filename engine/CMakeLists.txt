# engine/CMakeLists.txt
# Cubos engine build configuration

include(QuadradosGenerate)

option(BUILD_ENGINE_SAMPLES "Build cubos engine samples" OFF)
option(BUILD_ENGINE_TESTS "Build cubos engine tests?" OFF)

message("# Building engine samples: " ${BUILD_ENGINE_SAMPLES})
message("# Building engine tests: " ${BUILD_ENGINE_TESTS})

# Set engine source files
set(CUBOS_ENGINE_SOURCE
    "src/cubos/engine/cubos.cpp"

    "src/cubos/engine/settings/plugin.cpp"
    "src/cubos/engine/settings/settings.cpp"

    "src/cubos/engine/window/plugin.cpp"

    "src/cubos/engine/imgui/plugin.cpp"
    "src/cubos/engine/imgui/imgui.cpp"
    "src/cubos/engine/imgui/serialization.cpp"

    "src/cubos/engine/tools/asset_explorer/plugin.cpp"
    "src/cubos/engine/tools/settings_inspector/plugin.cpp"
    "src/cubos/engine/tools/entity_selector/plugin.cpp"
    "src/cubos/engine/tools/world_inspector/plugin.cpp"
    "src/cubos/engine/tools/entity_inspector/plugin.cpp"
    "src/cubos/engine/tools/scene_editor/plugin.cpp"

    "src/cubos/engine/transform/plugin.cpp"

    "src/cubos/engine/assets/plugin.cpp"
    "src/cubos/engine/assets/assets.cpp"
    "src/cubos/engine/assets/bridge.cpp"
    "src/cubos/engine/assets/asset.cpp"
    "src/cubos/engine/assets/meta.cpp"
    "src/cubos/engine/assets/bridges/file.cpp"

    "src/cubos/engine/scene/plugin.cpp"
    "src/cubos/engine/scene/bridge.cpp"

    "src/cubos/engine/voxels/plugin.cpp"
    "src/cubos/engine/voxels/grid.cpp"
    "src/cubos/engine/voxels/material.cpp"
    "src/cubos/engine/voxels/palette.cpp"

    "src/cubos/engine/collisions/plugin.cpp"
    "src/cubos/engine/collisions/broad_phase.cpp"
    "src/cubos/engine/collisions/broad_phase_collisions.cpp"

    "src/cubos/engine/input/plugin.cpp"
    "src/cubos/engine/input/input.cpp"
    "src/cubos/engine/input/bindings.cpp"
    "src/cubos/engine/input/action.cpp"
    "src/cubos/engine/input/axis.cpp"

    "src/cubos/engine/renderer/plugin.cpp"
    "src/cubos/engine/renderer/vertex.cpp"
    "src/cubos/engine/renderer/frame.cpp"
    "src/cubos/engine/renderer/renderer.cpp"
    "src/cubos/engine/renderer/deferred_renderer.cpp"
    "src/cubos/engine/renderer/pps/bloom.cpp"
    "src/cubos/engine/renderer/pps/copy_pass.cpp"
    "src/cubos/engine/renderer/pps/manager.cpp"
    "src/cubos/engine/renderer/pps/pass.cpp"
)

# Create cubos engine
add_library(cubos-engine ${CUBOS_ENGINE_SOURCE})
target_include_directories(cubos-engine PUBLIC "include")
target_link_libraries(cubos-engine PUBLIC cubos-core)
cubos_common_target_options(cubos-engine)

add_library(imgui STATIC
    "lib/imgui/imgui.cpp"
    "lib/imgui/imgui_draw.cpp"
    "lib/imgui/imgui_tables.cpp"
    "lib/imgui/imgui_widgets.cpp"
    "lib/imgui/imgui_demo.cpp"
    "lib/imgui/misc/cpp/imgui_stdlib.cpp"
)

target_include_directories(imgui PUBLIC "lib/imgui" "lib/imgui/misc/cpp/imgui_stdlib.hpp")
target_link_libraries(cubos-engine PUBLIC imgui)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(cubos-engine PUBLIC -Wno-attributes)
endif()

# Generate component headers
quadrados_generate(cubos-engine ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Add engine tests
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_ENGINE_TESTS)
    add_subdirectory(tests)
endif()

# Add engine samples
if(BUILD_ENGINE_SAMPLES)
    add_subdirectory(samples)
endif()
