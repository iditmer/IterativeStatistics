
cmake_minimum_required(VERSION 3.14)

project ("IterativeStatistics")
set(CMAKE_CXX_STANDARD 14)

include_directories("../source")
file(GLOB SOURCE_FILES "../source/*.cpp" "source/*.hpp")
add_executable (demo main.cpp ${SOURCE_FILES})