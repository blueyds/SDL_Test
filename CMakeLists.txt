cmake_minimum_required(VERSION 3.25)
set(CMAKE_CXX_STANDARD 20)
project(sandbox VERSION 0.1.0 LANGUAGES C CXX)

find_path(SDL2_INCLUDE_DIR "SDL2/SDL.h" REQUIRED)


find_library(SDL2_LIBRARY SDL2 REQUIRED)

find_library(SDL2_IMAGE SDL2_image REQURED)
find_path(SDL2_IMAGE_INCLUDE_DIR "SDL2/SDL_image.h" REQUIRED)


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