cmake_minimum_required(VERSION 3.0)

project("dsda-doom" VERSION 0.25.6)

# Set a default build type if none was specified
set(default_build_type "RelWithDebInfo")
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to '${default_build_type}' as none was specified.")
  set(CMAKE_BUILD_TYPE "${default_build_type}" CACHE
      STRING "Choose the type of build." FORCE)
  # Set the possible values of build type for cmake-gui
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
    "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include(TargetArch)

include(TestBigEndian)
TEST_BIG_ENDIAN(WORDS_BIGENDIAN)

include(GNUInstallDirs)

# Automated dependencies discovery, mostly needed for MSVC
target_architecture(TARGET_ARCH)
foreach(target ${TARGET_ARCH})
    if(${target} MATCHES "i386")
        set(DEPENDENCY_SUFFIX x86)
    elseif(${target} MATCHES "x86_64")
        set(DEPENDENCY_SUFFIX x64)
    endif()
endforeach()
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/../dependencies_${DEPENDENCY_SUFFIX}")

set(PACKAGE_NAME "${PROJECT_NAME}")
set(PACKAGE_TARNAME "dsda-doom")
set(WAD_DATA "dsda-doom.wad")
set(PACKAGE_VERSION "${PROJECT_VERSION}")
set(PACKAGE_STRING "${PROJECT_NAME} ${PROJECT_VERSION}")

include(CheckSymbolExists)

check_symbol_exists(stricmp "string.h" HAVE_STRICMP)
if(NOT HAVE_STRICMP)
    add_definitions("-Dstricmp=strcasecmp")
endif()
check_symbol_exists(strnicmp "string.h" HAVE_STRNICMP)
if(NOT HAVE_STRNICMP)
    add_definitions("-Dstrnicmp=strncasecmp")
endif()

check_symbol_exists(getopt "unistd.h" HAVE_GETOPT)
check_symbol_exists(mmap "sys/mman.h" HAVE_MMAP)
check_symbol_exists(CreateFileMapping "windows.h" HAVE_CREATE_FILE_MAPPING)
check_symbol_exists(strsignal "string.h" HAVE_STRSIGNAL)
check_symbol_exists(mkstemp "stdlib.h" HAVE_MKSTEMP)

include(CheckIncludeFile)

check_include_file("sys/wait.h" HAVE_SYS_WAIT_H)
check_include_file("unistd.h" HAVE_UNISTD_H)
check_include_file("asm/byteorder.h" HAVE_ASM_BYTEORDER_H)
check_include_file("dirent.h" HAVE_DIRENT_H)

set(OpenGL_GL_PREFERENCE LEGACY)
find_package(OpenGL REQUIRED)

find_package(SDL2 2.0.7 REQUIRED)

option(WITH_IMAGE "Use SDL2_image if available" ON)
if(WITH_IMAGE)
    find_package(SDL2_image)
    if(SDL2_IMAGE_FOUND)
        set(HAVE_LIBSDL2_IMAGE TRUE)
    endif()
endif()

find_package(SDL2_mixer REQUIRED)

option(WITH_ZLIB "Use ZLIB if available" ON)
if(WITH_ZLIB)
    find_package(ZLIB)
    if(ZLIB_FOUND)
        set(HAVE_LIBZ TRUE)
    endif()
endif()

option(WITH_MAD "Use libmad if available" ON)
if(WITH_MAD)
    find_package(LibMad)
    if(LIBMAD_FOUND)
        set(HAVE_LIBMAD TRUE)
    endif()
endif()

option(WITH_FLUIDSYNTH "Use FluidSynth if available" ON)
if(WITH_FLUIDSYNTH)
    find_package(FluidSynth)
    if(FLUIDSYNTH_FOUND)
        set(HAVE_LIBFLUIDSYNTH TRUE)
    endif()
endif()

option(WITH_DUMB "Use DUMB if available" ON)
if(WITH_DUMB)
    find_package(DUMB)
    if(DUMB_FOUND)
        set(HAVE_LIBDUMB TRUE)
    endif()
endif()

option(WITH_VORBISFILE "Use vorbisfile if available" ON)
if(WITH_VORBISFILE)
    find_package(Vorbis)
    if(VORBIS_FOUND)
        set(HAVE_LIBVORBISFILE TRUE)
    endif()
endif()

option(WITH_PORTMIDI "Use PortMidi if available" ON)
if(WITH_PORTMIDI)
    find_package(PortMidi)
    if(PortMidi_FOUND)
        set(HAVE_LIBPORTMIDI TRUE)
    endif()
endif()

set(CMAKE_REQUIRED_INCLUDES_PREV ${CMAKE_REQUIRED_INCLUDES})
set(CMAKE_REQUIRED_LIBRARIES_PREV ${CMAKE_REQUIRED_LIBRARIES})
set(CMAKE_REQUIRED_INCLUDES ${CMAKE_REQUIRED_INCLUDES} ${SDL2_INCLUDE_DIRS})
set(CMAKE_REQUIRED_LIBRARIES ${CMAKE_REQUIRED_LIBRARIES} ${SDL2_LIBRARIES})
set(CMAKE_REQUIRED_INCLUDES ${CMAKE_REQUIRED_INCLUDES_PREV})
set(CMAKE_REQUIRED_LIBRARIES ${CMAKE_REQUIRED_LIBRARIES_PREV})

set(DOOMWADDIR "${CMAKE_INSTALL_PREFIX}/share/games/doom" CACHE PATH "Path to look for WAD files")
set(DSDAPWADDIR "${DOOMWADDIR}" CACHE PATH "Path to install DSDA-Doom internal WAD")

option(SIMPLECHECKS "Enable checks which only impose significant overhead if a posible error is detected" ON)

# Debug options, disabled by default
option(RANGECHECK "Enable internal range checking" OFF)

configure_file(cmake/config.h.cin config.h)

add_definitions(-DHAVE_CONFIG_H)

if (MSVC)
    add_definitions("/D_CRT_SECURE_NO_WARNINGS")
else()
    set(CMAKE_C_FLAGS
        "${CMAKE_C_FLAGS} \
        -Wall -Wno-missing-field-initializers -Wwrite-strings -Wundef \
        -Wbad-function-cast -Wcast-align -Wcast-qual -Wdeclaration-after-statement \
        -Wpointer-arith -Wno-unused -Wno-switch -Wno-sign-compare -Wno-pointer-sign \
        -Wtype-limits -Wabsolute-value \
        -ffast-math"
    )
endif()

# Support cross compiling
option(FORCE_CROSSCOMPILE "Enable cross-compilation" OFF)
if(FORCE_CROSSCOMPILE)
    set(CMAKE_CROSSCOMPILING ON)
endif()

if(CMAKE_CROSSCOMPILING)
    set(IMPORT_EXECUTABLES "IMPORTFILE-NOTFOUND" CACHE FILEPATH "Export file from native build")
    include(${IMPORT_EXECUTABLES})
else()
    if(NOT CROSS_EXPORTS)
        set(CROSS_EXPORTS "")
    endif()
endif()

set(PRBOOM_OUTPUT_PATH ${CMAKE_BINARY_DIR})

set(WAD_DATA_PATH "${PRBOOM_OUTPUT_PATH}/${WAD_DATA}")

add_subdirectory(data)
add_subdirectory(src)

if(NOT CMAKE_CROSSCOMPILING)
    export(TARGETS ${CROSS_EXPORTS} FILE "${CMAKE_BINARY_DIR}/ImportExecutables.cmake")
endif()
