# ensure that directory exists
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/assets)
# copy the asset files to the asset directory in build
file(COPY
    Sara_16x18_Preview.png
    Sara16x18.png
    dirt.png 
    grass.png 
    water.png 
    DESTINATION ${CMAKE_BINARY_DIR}/assets/)