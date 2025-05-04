cmake_minimum_required(VERSION 3.27)
project(rash VERSION 0.1)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS True)

set(RASH_SRC_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/src/include)
include_directories(${RASH_SRC_INCLUDE_DIR})

# add_subdirectory(src)

add_executable(rash ${PROJECT_SOURCE_DIR}/src/main.cpp)