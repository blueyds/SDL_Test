cmake_minimum_required(VERSION 3.26)
set(CMAKE_CXX_STANDARD 20)
project(sandbox VERSION 0.1.0 LANGUAGES C CXX)

add_subdirectory(src)
add_executable(sandbox 
    ${sandbox_sources})

target_include_directories(
    sandbox PUBLIC
    ${sandbox_include_directories})

target_link_libraries(sandbox 
    ${sandbox_libraries})

# post buildl make assets directoro and copy file
add_subdirectory(assets)
add_dependencies(sandbox copyAssets)
#add_custom_target(asset_dir
#    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/assets)
#add_custom_target(dirt_png DEPENDS asset_dir
#    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_SOURCE_DIR}/assets/dirt.png ${CMAKE_BINARY_DIR})
#add_custom_target(sara_png DEPENDS asset_dir
#    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_SOURCE_DIR}/assets/Sara_16x18_Preview.png ${CMAKE_BINARY_DIR})
#add_custom_target(grass_png DEPENDS asset_dir
#    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_SOURCE_DIR}/assets/grass.png ${CMAKE_BINARY_DIR})
#add_custom_target(water_png DEPENDS asset_dir
#    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_SOURCE_DIR}/assets/water.png ${CMAKE_BINARY_DIR})
#add_dependencies(sandbox dirt_png water_png grass_png sara_png)