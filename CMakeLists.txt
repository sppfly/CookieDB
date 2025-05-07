cmake_minimum_required(VERSION 3.27)

set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS True)

project(CookieDB VERSION 0.1)

# Options for enabling various checks (all ON by default)
option(ENABLE_CLANG_TIDY "Enable clang-tidy checks" ON)
option(ENABLE_WARNINGS_AS_ERRORS "Treat compiler warnings as errors" ON)
option(ENABLE_SANITIZERS "Enable sanitizers (ASan, UBSan)" ON)

# Compile flags common to all build types
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Wconversion -Wsign-conversion -Wcast-qual -Wformat=2 -Wundef -Werror=float-equal -Wshadow -Wcast-align -Wunused -Wnull-dereference -Wdouble-promotion -Wfloat-equal")

# Add extra warnings for Clang
if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wmost -Wextra-semi -Woverloaded-virtual -Wundefined-func-template -Wmissing-prototypes")
endif()

# Configure warning as errors if enabled
if(ENABLE_WARNINGS_AS_ERRORS)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror")
endif()

# Configure sanitizers if enabled
if(ENABLE_SANITIZERS)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")
endif()

set(CookieDB_SRC_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/src/include)
include_directories(${CookieDB_SRC_INCLUDE_DIR})



set(SRC
    src/databox.cpp
    src/tuple.cpp
    src/type.cpp
)
add_executable(CookieDB ${PROJECT_SOURCE_DIR}/src/main.cpp ${SRC})