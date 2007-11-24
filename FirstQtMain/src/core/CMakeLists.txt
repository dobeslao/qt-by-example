# Make sure the compiler can find include files from our Hello library.
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR}/../ui)
# Make sure the linker can find the Hello library once it is built.
LINK_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR}/../ui)

SET( FIRSTQT_MOC_H
  first.h
)

QT4_WRAP_CPP( FIRSTQT_MOC_SRCS ${FIRSTQT_MOC_H} )

# Add executable called "mainDemo" that is built from the source files
# "main.cpp".  The extensions are automatically found.
ADD_EXECUTABLE(firstQtDemo main first ${FIRSTQT_MOC_SRCS} ${FIRSTQT_UIS_H})

TARGET_LINK_LIBRARIES(firstQtDemo ${QT_LIBRARIES})
