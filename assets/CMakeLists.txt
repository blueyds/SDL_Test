
add_custom_target(dirt_png
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_CURRENT_SOURCE_DIR}/dirt.png
        ${PROJECT_BINARY_DIR} )

add_custom_target(grass_png
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_CURRENT_SOURCE_DIR}/grass.png
        ${PROJECT_BINARY_DIR})

add_custom_target(water_png
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${CMAKE_CURRENT_SOURCE_DIR}/water.png
            ${PROJECT_BINARY_DIR} )

add_custom_target(player_png
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_CURRENT_SOURCE_DIR}/universal-lpc-sprite_male_01_walk-3frame.png
        ${PROJECT_BINARY_DIR} )

add_custom_target(map_map
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
                ${CMAKE_CURRENT_SOURCE_DIR}/map16x16.map
                ${PROJECT_BINARY_DIR} )
    

add_custom_target(copyAssets ALL DEPENDS 
    player_png
    water_png
    grass_png
    dirt_png
    map_map
    )
