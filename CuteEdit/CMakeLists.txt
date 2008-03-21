# The name of our project is "WHELLO". CMakeLists files in this project can
# refer to the root source directory of the project as ${WHELLO_SOURCE_DIR} and
# to the root binary directory of the project as ${WHELLO_BINARY_DIR}.
PROJECT(LCDWIDGET)

#############################################################
# CMake settings
CMAKE_MINIMUM_REQUIRED(VERSION 2.4.3)
SET(CMAKE_COLOR_MAKEFILE ON)

# Eclipse has a mechanism in place to 'Discover' these locations. The mechanism
# works by parsing the compiler invocation looking for "-I" arguments then adds
# these directories to the list of include paths to index. In order for this
# discovery process to work you need to build your project at least once with
# the CMAKE_VERBOSE_MAKEFILE to true (ON)
SET(CMAKE_VERBOSE_MAKEFILE OFF)

# The CDT Error Parser cannot handle error messages that span more than one line,
# which is the default gcc behavior. In order to force gcc to generate single
# line error messages with no line wrapping

IF(CMAKE_COMPILER_IS_GNUCC)
  SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fmessage-length=0")
ENDIF(CMAKE_COMPILER_IS_GNUCC)
IF(CMAKE_COMPILER_IS_GNUCXX)
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fmessage-length=0")
ENDIF(CMAKE_COMPILER_IS_GNUCXX)

# Enable warnings
#ADD_DEFINITIONS( -Wall )

#############################################################
# This command finds Qt4 libraries and sets all required variables
FIND_PACKAGE(Qt4 REQUIRED) 

# add some useful macros and variables
# (QT_USE_FILE is a variable defined by FIND_PACKAGE( Qt4 ) that contains a path to CMake script)
INCLUDE( ${QT_USE_FILE} )

add_subdirectory(mainwindow)
add_subdirectory(cuteedit1)
add_subdirectory(cuteedit2)
add_subdirectory(configtest)
add_subdirectory(cuteedit3)