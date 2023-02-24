
cmake_minimum_required(VERSION 3.14)

project ("IterativeStatistics")
set(CMAKE_CXX_STANDARD 14)

include_directories("source")
file(GLOB SOURCE_FILES "source/*.cpp" "source/*.hpp")
add_executable (unit-tests "tests/UnivariateSampleTests.cpp" ${SOURCE_FILES} ${TEST_FILES})

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        e2239ee6043f73722e7aa812a459f54a28552929 # release-1.11.0
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

target_link_libraries(
  unit-tests
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(unit-tests)