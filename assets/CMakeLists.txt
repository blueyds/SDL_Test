
add_custom_target(tileset_png
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_CURRENT_SOURCE_DIR}/tileset.png
        ${PROJECT_BINARY_DIR} )

add_custom_target(map_csv
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_CURRENT_SOURCE_DIR}/map.csv
        ${PROJECT_BINARY_DIR})


add_custom_target(player_png
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_CURRENT_SOURCE_DIR}/universal-lpc-sprite_male_01_walk-3frame.png
        ${PROJECT_BINARY_DIR} )
    

add_custom_target(copyAssets ALL DEPENDS 
    player_png
    tileset_png
    map_csv
    )
