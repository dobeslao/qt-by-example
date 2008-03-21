#############################################################
# Add executable called "mainDemo" that is built from the source files
# "main.cpp".  The extensions are automatically found.
QT4_WRAP_CPP(MOC_APP_SRCS ByteConverterDialog.h ByteConverter.h)
ADD_EXECUTABLE(qtdialog2 qtDialog.cpp ByteConverterDialog.cpp ByteConverter.cpp ${MOC_APP_SRCS})
TARGET_LINK_LIBRARIES(qtdialog2 ${QT_LIBRARIES})