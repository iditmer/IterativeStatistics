
cmake_minimum_required(VERSION 3.14)

project ("IterativeStatistics")
set(CMAKE_CXX_STANDARD 14)

include_directories("../source")
file(GLOB SOURCE_FILES "../source/*.cpp" "../source/*.hpp")
file(GLOB TEST_FILES "*.cpp")
add_executable (unit-tests ${SOURCE_FILES} ${TEST_FILES})

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        b796f7d44681514f58a683a3a71ff17c94edb0c1 # release-1.13.0
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

target_link_libraries(
  unit-tests
  gtest_main
  gmock_main
)

include(GoogleTest)
gtest_discover_tests(unit-tests)