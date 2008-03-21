# we need this to be able to include headers produced by uic in our code
# (CMAKE_BINARY_DIR holds a path to the build directory, while INCLUDE_DIRECTORIES() works just like INCLUDEPATH from qmake)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})
# Make sure the linker can find the library once it is built.
#LINK_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})

#############################################################
# Add executable called "mainDemo" that is built from the source files
# "main.cpp".  The extensions are automatically found.
QT4_WRAP_UI(UI_APP_HDRS MainWindow.ui)
QT4_WRAP_CPP(MOC_APP_SRCS MainWindow.h TemplateHandler.h)

# generate rules for building source files from the resources
QT4_ADD_RESOURCES(RCC_APP_SRCS application.qrc)

ADD_EXECUTABLE(cute_edit_2 cuteedit.cpp MainWindow.cpp TemplateHandler.cpp ${MOC_APP_SRCS} ${UI_APP_HDRS} ${RCC_APP_SRCS})
TARGET_LINK_LIBRARIES(cute_edit_2 ${QT_LIBRARIES})