# The name of our project is "CLIENTE". CMakeLists files in this project can
# refer to the root source directory of the project as ${CLIENTE_SOURCE_DIR} and
# to the root binary directory of the project as ${CLIENTE_BINARY_DIR}.
PROJECT(SISL)

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
#SET(CMAKE_VERBOSE_MAKEFILE ON)

# The CDT Error Parser cannot handle error messages that span more than one line,
# which is the default gcc behavior. In order to force gcc to generate single
# line error messages with no line wrapping
IF(CMAKE_COMPILER_IS_GNUCC)
  SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fmessage-length=0")
ENDIF(CMAKE_COMPILER_IS_GNUCC)
IF(CMAKE_COMPILER_IS_GNUCXX)
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fmessage-length=0")
ENDIF(CMAKE_COMPILER_IS_GNUCXX)

#############################################################
# search for Qt4
# This command finds Qt4 libraries and sets all required variables
FIND_PACKAGE(Qt4 REQUIRED) 

# add some useful macros and variables
# (QT_USE_FILE is a variable defined by FIND_PACKAGE(Qt4) that contains a path to CMake script)
INCLUDE(${QT_USE_FILE})

SET( QT_USE_QTXML      TRUE )
SET( QT_USE_QTNETWORK  TRUE )

#############################################################
# set path to additional CMake modules
SET(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})

#############################################################
# Enable warnings
# Compile flag. Make it posible to turn it off.
SET(PEDANTIC TRUE CACHE BOOL "Determines if we should compile with -Wall -Werror.")

IF (PEDANTIC)
  ADD_DEFINITIONS( -Wall -Werror )
ELSE (PEDANTIC)
  ADD_DEFINITIONS( -Wall )
ENDIF (PEDANTIC)

# Note that CMAKE_BUILD_TYPE is not initialized with 
# a readable value at configuration time. Set on compilation options
# cmake -D CMAKE_BUILD_TYPE=Debug ../
#SET (CMAKE_BUILD_TYPE Debug)

IF (CMAKE_BUILD_TYPE MATCHES Debug)
  ADD_DEFINITIONS(-DDEBUG=1)
  ADD_DEFINITIONS(-DCLNTTEST=1)
ENDIF (CMAKE_BUILD_TYPE MATCHES Debug)

#############################################################
# Platform specific stuff

IF (WIN32)
  SET (CLNT_BIN_DIR     ${CMAKE_INSTALL_PREFIX})
  SET (CLNT_DATA_DIR    ${CMAKE_INSTALL_PREFIX})
  SET (CLNT_PLUGIN_DIR  ${CMAKE_INSTALL_PREFIX}/plugins)
  SET (CLNT_INCLUDE_DIR ${CMAKE_INSTALL_PREFIX}/include)
  SET (CLNT_SOURCE_DIR  ${CMAKE_SOURCE_DIR})

ELSE (WIN32)

  IF (APPLE)
    # for Mac OS X, everything is put inside an application bundle
    SET (CMAKE_INSTALL_PREFIX ${CMAKE_INSTALL_PREFIX}/${PROJECT_NAME}.app/Contents/MacOS)
    # path for library references
    SET (CMAKE_INSTALL_NAME_DIR @executable_path/lib)
  ENDIF (APPLE)

  # common for MAC and UNIX
  SET (CLNT_BIN_DIR     ${CMAKE_INSTALL_PREFIX}/bin)
  SET (CLNT_DATA_DIR    ${CMAKE_INSTALL_PREFIX}/share/siba)
  SET (CLNT_PLUGIN_DIR  ${CMAKE_INSTALL_PREFIX}/lib/siba)
  SET (CLNT_INCLUDE_DIR ${CMAKE_INSTALL_PREFIX}/include/siba)
  SET (CLNT_SOURCE_DIR  ${CMAKE_SOURCE_DIR})

  IF (UNIX AND NOT APPLE)
    ADD_DEFINITIONS(-DPREFIX=\\"${CMAKE_INSTALL_PREFIX}\\")
    ADD_DEFINITIONS(-DPLUGINPATH=\\"${QGIS_PLUGIN_DIR}\\")
    ADD_DEFINITIONS(-DPKGDATAPATH=\\"${QGIS_DATA_DIR}\\")
  ENDIF (UNIX AND NOT APPLE)

ENDIF (WIN32)

IF (WIN32)
  # expect that classes are being imported
  # Note: MSVC doesn't like when the macros are quotes
  # and MSYS doesn't like them unqouted (bacause of braces)
  IF (MSVC)
    ADD_DEFINITIONS("-DCORE_EXPORT=__declspec(dllimport)")
    ADD_DEFINITIONS("-DGUI_EXPORT=__declspec(dllimport)")
  ELSE (MSVC)
    ADD_DEFINITIONS("\"-DCORE_EXPORT=__declspec(dllimport)\"")
    ADD_DEFINITIONS("\"-DGUI_EXPORT=__declspec(dllimport)\"")
  ENDIF (MSVC)

ELSE (WIN32)

  # other compilers don't use that MSVC construct
  ADD_DEFINITIONS(-DCORE_EXPORT=)
  ADD_DEFINITIONS(-DGUI_EXPORT=)

ENDIF (WIN32)

#############################################################

# with SET() command you can change variables or define new ones
# here we define PROJECT_SRCS variable that contains a list of all .cpp files
# note that we don't need \ at the end of line

  # Esta lista pretende contener las operaciones más basicas que
  # realiza el cliente.
  SET( PROJECT_SRCS
       sisl.cpp
  )
  
  #############################################################
  # Necessary includes
  
  # we need this to be able to include headers produced by uic in our code
  # (CMAKE_BINARY_DIR holds a path to the build directory, while INCLUDE_DIRECTORIES() works just like INCLUDEPATH from qmake)
  INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})
  # Make sure the linker can find the library once it is built.
  LINK_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})
  
################### Termina lista de definiciones
   
  # Este comando ejecuta el comando moc sobre los archivos especificados:
  QT4_WRAP_CPP( PROJECT_MOC_SRCS ${PROJECT_SRCS} )
  OUTPUT_REQUIRED_FILES(sisl.cpp moc_sisl.cxx)

  # Se le dice a CMale que construya un ejecutable "mediador" con todos los archivos fuente
  # Se deben de proporcionar todas las listas o archivos que se deseen y sean necesarios para el ejecutable
  ADD_EXECUTABLE(application ${PROJECT_SRCS})

  # Por ultimo se le dice a CMake que librerias o ejecutables son necesarios.
  TARGET_LINK_LIBRARIES(application ${QT_LIBRARIES})
    
