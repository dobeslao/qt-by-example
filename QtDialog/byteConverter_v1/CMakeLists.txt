#############################################################
# Add executable called "mainDemo" that is built from the source files
# "main.cpp".  The extensions are automatically found.
QT4_WRAP_CPP(MOC_APP_SRCS ByteConverterDialog.h)
ADD_EXECUTABLE(qtdialog qtDialog.cpp ByteConverterDialog.cpp ${MOC_APP_SRCS})
TARGET_LINK_LIBRARIES(qtdialog ${QT_LIBRARIES})