
add_library(ecs_lib 
        Game/game.cpp 
        Drawing/TextureManager.cpp 
        Mapping/MapTiledCSV.cpp
        Vector2D.cpp
        Collision/Collision.cpp
	Utilities.cpp
        Core/Entity.cpp
	Core/Manager.cpp
	Drawing/AnimationComponent.cpp
        Inputs/KeyboardController.cpp
        Drawing/SpriteComponent.cpp
        Drawing/TileComponent.cpp
	Drawing/TransformComponent.cpp
)

target_link_libraries(ecs_lib PRIVATE SDL2::SDL2 ${SDL2_IMAGE})
target_include_directories(ecs_lib
        PRIVATE "/opt/homebrew/include"
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
        "./.."
)
