# we need this to be able to include headers produced by uic in our code
# (CMAKE_BINARY_DIR holds a path to the build directory, while INCLUDE_DIRECTORIES() works just like INCLUDEPATH from qmake)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})
# Make sure the linker can find the library once it is built.
LINK_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})

#############################################################
# Add executable called "mainDemo" that is built from the source files
# "main.cpp".  The extensions are automatically found.
#QT4_WRAP_UI(UI_APP_HDRS uiapp.ui)
#QT4_WRAP_CPP(MOC_APP_SRCS mocapp.h)

ADD_EXECUTABLE(configtest config.cpp)
TARGET_LINK_LIBRARIES(configtest ${QT_LIBRARIES})