
add_library(src_stuff 
        game.cpp 
        TextureManager.cpp 
        gameObject.cpp 
        Map.cpp
        Vector2D.cpp
        Collision.cpp
        ECS/ECS.cpp
)


target_include_directories(src_stuff PUBLIC
    ${SDL2_INCLUDE_DIR}
    ${SDL2_IMAGE_INCLUDE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
)
