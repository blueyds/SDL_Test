cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
project(sandbox VERSION 0.1.0 LANGUAGES C CXX)
find_path(SDL2_INCLUDE_DIR "SDL2/SDL.h")
find_library(SDL2_LIBRARY SDL2)
find_library(SDL2_IMAGE SDL2_image)
# add log messages
message([STATUS] "CMAKE_SYSTEM_PREFIX_PATH" ${CMAKE_SYSTEM_PREFIX_PATH})
message([STATUS] "SDL2_LIBRARY" ${SDL2_LIBRARY})
message([STATUS] "SDL_INCLUDE_DIR" ${SDL2_INCLUDE_DIR})
message([STATUS] "SDL2_IMAGE" ${SDL2_IMAGE})

add_executable(sandbox main.cpp game.cpp)

target_include_directories(
    sandbox PUBLIC
    ${SDL2_INCLUDE_DIR}

)
target_link_libraries(sandbox ${SDL2_LIBRARY} ${SDL2_IMAGE})

get_target_property(INCLUDEDIRS sandbox INCLUDE_DIRECTORIES)
message([STATUS] "Include directories for SDL_Test: ${INCLUDEDIRS}")