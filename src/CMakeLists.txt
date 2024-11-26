
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
set(sandbox_sources 
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/game.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/TextureManager.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/gameObject.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/Map.cpp
    PARENT_SCOPE)

set(sandbox_include_directories 
    ${SDL2_INCLUDE_DIR}
    ${SDL2_IMAGE_INCLUDE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
    PARENT_SCOPE
)

set(sandbox_libraries
    ${SDL2_LIBRARY} 
    ${SDL2_IMAGE}
    PARENT_SCOPE)