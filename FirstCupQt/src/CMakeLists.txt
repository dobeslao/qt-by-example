# Add executable called "mainDemo" that is built from the source files
# "main.cpp".  The extensions are automatically found.
ADD_EXECUTABLE(mainDemo main)
TARGET_LINK_LIBRARIES(mainDemo ${QT_LIBRARIES})

ADD_EXECUTABLE(helloRun hello)
TARGET_LINK_LIBRARIES(helloRun ${QT_LIBRARIES} )
