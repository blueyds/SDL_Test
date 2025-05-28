
add_library(src_lib 
        GameTileEntity.cpp 
        player.cpp 
        RpgGame.cpp 
)

add_subdirectory(ECS)
link_directories(ECS)
target_link_libraries(src_lib ecs_lib)
target_include_directories(src_lib 
        PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}
)
