cmake_minimum_required(VERSION 3.26)
set(CMAKE_CXX_STANDARD 20)
project(sandbox VERSION 0.1.0 LANGUAGES C CXX)

find_path(SDL2_INCLUDE_DIR "SDL.h")
if(NOT ${SDL2_INCLUDE_DIR})
    find_path(SDL2_INCLUDE_DIR "SDL.h" PATH_SUFFIXES "SDL2")
endif()

find_library(SDL2_LIBRARY SDL2)

find_library(SDL2_IMAGE SDL2_image)
find_path(SDL2_IMAGE_INCLUDE_DIR "SDL_image.h")
if(NOT ${SDL2_IMAGE_INCLUDE_DIR})
    find_path(SDL2_IMAGE_INCLUDE_DIR "SDL_image.h" PATH_SUFFIXES "SDL2")
endif()

# add log messages
message([STATUS] "CMAKE_SYSTEM_PREFIX_PATH" ${CMAKE_SYSTEM_PREFIX_PATH})
message([STATUS] "SDL2_LIBRARY" ${SDL2_LIBRARY})
message([STATUS] "SDL_INCLUDE_DIR" ${SDL2_INCLUDE_DIR})
message([STATUS] "SDL2_IMAGE" ${SDL2_IMAGE})
message([STATUS] "SDL2_IMAGE_INCLUDE_DIR" ${SDL2_IMAGE_INCLUDE_DIR})


add_executable(sandbox main.cpp)

add_subdirectory(src)
link_directories(src)
target_link_libraries(sandbox 
        src_stuff
        ${SDL2_LIBRARY} 
        ${SDL2_IMAGE}
)
# post buildl make assets directoro and copy file
add_subdirectory(assets)
add_dependencies(sandbox copyAssets)