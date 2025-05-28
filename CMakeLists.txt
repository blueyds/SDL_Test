cmake_minimum_required(VERSION 3.25)
set(CMAKE_CXX_STANDARD 20)
project(sandbox VERSION 0.1.0 LANGUAGES C CXX)
include(CTest)

find_package(SDL2)


find_library(SDL2_IMAGE SDL2_image PATHS SDL2 DOC "CHECKING FOR SDL2 Image" REQUIRED)
#find_path(SDL2_IMAGE_INCLUDE_DIR "SDL2/SDL_image.h" REQUIRED)


add_executable(sandbox main.cpp)

add_subdirectory(src)
link_directories(src)
target_link_libraries(sandbox 
        src_lib
        SDL2::SDL2main
        SDL2::SDL2 
        ${SDL2_IMAGE}
)
target_include_directories(sandbox
        PRIVATE src src/ECS
        "/opt/homebrew/include"
)
add_subdirectory(tests)

# post buildl make assets directoro and copy file
add_subdirectory(assets)
add_dependencies(sandbox copyAssets)