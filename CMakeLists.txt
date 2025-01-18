cmake_minimum_required (VERSION 3.20)

project(The_thing VERSION 0.1)
message(STATUS "THE_THING @ ${CMAKE_PROJECT_VERSION}")

add_executable(The_thing)

add_library(target_compiler_flags INTERFACE)
target_compile_features(target_compiler_flags INTERFACE cxx_std_20)

target_compile_options(target_compiler_flags INTERFACE
    -Wextra
    -Wall
    -Werror
)
target_link_libraries(The_thing PUBLIC target_compiler_flags)

option(DEBUG "Enable Debug mode" OFF)

if(DEBUG )
    message(STATUS "Building in Debug mode")
    target_compile_definitions(The_thing PRIVATE DEBUG)
    target_compile_options(The_thing PRIVATE -g)
else()
    message(STATUS "Building in Release mode")
    target_compile_options(The_thing PRIVATE -Ofast)
endif()


set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_sources(The_thing PRIVATE
    ${SOURCE_DIR}/main.cpp
    ${SOURCE_DIR}/Stopwatch.cpp
)

target_include_directories(The_thing PRIVATE include)
