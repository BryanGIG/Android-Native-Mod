cmake_minimum_required(VERSION 3.22.1)

# set the project name
project("template")

# Dobby setup
macro(SET_OPTION option value)
    set(${option} ${value} CACHE INTERNAL "" FORCE)
endmacro()

SET_OPTION(DOBBY_GENERATE_SHARED OFF)
SET_OPTION(Plugin.SymbolResolver OFF)
add_subdirectory(External/dobby)

# KittyMemory setup
add_compile_definitions(kNO_KEYSTONE)
file(GLOB_RECURSE KITTY_MEMORY_SOURCES External/KittyMemory/KittyMemory/*.cpp)

# Engine setup
file(GLOB_RECURSE ENGINE_SOURCES Engine/Structure/*.cpp)
file(GLOB_RECURSE ENGINE_HEADER_SOURCES Engine/Structure/*.hpp)

add_library(${CMAKE_PROJECT_NAME} SHARED
        native-lib.cpp
        Engine/API/API.cpp
        ${ENGINE_SOURCES}
        ${KITTY_MEMORY_SOURCES})

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC
        External/Dobby/include
        External/KittyMemory
        Utils)

target_link_libraries(${CMAKE_PROJECT_NAME} log dobby)