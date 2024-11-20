# ensure that directory exists
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/assets)
# copy the asset files to the asset directory in build
file(INSTALL
    Sara_16x18_Preview.png
    sara_credit.txt
    Sara16x18.png
    DESTINATION ${CMAKE_BINARY_DIR}/assets)