cmake_minimum_required(VERSION 3.15)
project(FutureXiang)

set(CMAKE_CXX_STANDARD 17)
set(GOOGLETEST_VERSION 1.10.0) # from googletest-master/CML.txt


add_subdirectory(external/googletest)
include_directories(src external/googletest/include)


add_executable(FutureXiang
        main.cpp
        src/Calculator.cpp)
add_executable(TEST external/googletest
        test/test.cpp
        src/Calculator.cpp)
target_link_libraries(TEST gtest_main)