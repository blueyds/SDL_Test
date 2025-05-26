
add_library(src_stuff 
        game.cpp 
        TextureManager.cpp 
        Map.cpp
        Vector2D.cpp
        Collision.cpp
	Utilities.cpp
        ECS/Entity.cpp
	ECS/Manager.cpp
	ECS/AnimationComponent.cpp
        ECS/KeyboardController.cpp
        ECS/SpriteComponent.cpp
        ECS/TileComponent.cpp
	ECS/TransformComponent.cpp
)


target_include_directories(src_stuff PUBLIC
    ${SDL2_INCLUDE_DIR}
    ${SDL2_IMAGE_INCLUDE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
)
