cmake_minimum_required(VERSION 3.21)
project(untitled1)

set(CMAKE_CXX_STANDARD 14)

if(NOT MODE)
    set(MODE File)
endif()

add_library(MATRIX_MATH SHARED MatrixMath.cpp MatrixMath.h )
add_library(MATRIX${MODE}PRINT SHARED Matrix${MODE}Print.cpp Matrix${MODE}Print.h PrintTo.cpp PrintTo.h)
add_executable(MAIN main.cpp)
target_link_libraries(MAIN MATRIX_MATH MATRIX${MODE}PRINT)

add_subdirectory(tests/googletest)
enable_testing()
include_directories(${STACK_INCLUDE_DIR})
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
target_link_libraries(MAIN gtest gtest_main)