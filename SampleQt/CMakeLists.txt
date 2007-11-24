# The name of our project is "HELLO".  CMakeLists files in this project can
# refer to the root source directory of the project as ${HELLO_SOURCE_DIR} and
# to the root binary directory of the project as ${HELLO_BINARY_DIR}.
PROJECT(HELLO)

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

cmake_minimum_required(VERSION 2.4.0)

#find_package(Qt4 REQUIRED) # find and setup Qt4 for this project

# Recurse into the "Hello" and "Demo" subdirectories.  This does not actually
# cause another cmake executable to run.  The same process will walk through
# the project's entire directory structure.
ADD_SUBDIRECTORY(Demo)
ADD_SUBDIRECTORY(Hello)
