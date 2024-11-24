cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
project(sandbox VERSION 0.1.0 LANGUAGES C CXX)
add_subdirectory(src)

add_custom_command(
      TARGET sandbox POST_BUILD
      COMMAND ${CMAKE_COMMAND} copy_directoryy
            assets
            ${CMAKE_BINARY_DIR}
)