include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.2
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

# Make all targets in this directory look for headers here
include_directories(${CMAKE_SOURCE_DIR}/src ${CMAKE_SOURCE_DIR}/include)

# Add the library for expression
add_library(split_lib SHARED ${CMAKE_SOURCE_DIR}/src/split.cpp)
add_library(my_type_lib SHARED ${CMAKE_SOURCE_DIR}/src/my_type.cpp)
# Make all targets in this directory link against Gtest
link_libraries(GTest::gtest_main)

add_executable(test_split ${CMAKE_SOURCE_DIR}/tests/test_split.cpp) # Compile a test source
add_executable(test_mytype ${CMAKE_SOURCE_DIR}/tests/test_mytype.cpp)
add_executable(test_sum ${CMAKE_SOURCE_DIR}/tests/test_sum.cpp)
add_executable(test_pair ${CMAKE_SOURCE_DIR}/tests/test_pair.cpp)
add_executable(test_transform ${CMAKE_SOURCE_DIR}/tests/test_transform.cpp)
add_executable(test_is_raw_pointer ${CMAKE_SOURCE_DIR}/tests/test_is_raw_pointer.cpp)
add_executable(test_flexible_container ${CMAKE_SOURCE_DIR}/tests/test_flexible_container.cpp)
# Link against any required libraries. The library "some_library" is compiled in src/
target_link_libraries(
  test_split
  split_lib
  GTest::gtest_main
)

target_link_libraries(
  test_mytype
  my_type_lib
  GTest::gtest_main
)

target_link_libraries(
  test_sum
  GTest::gtest_main
)

target_link_libraries(
  test_pair
  GTest::gtest_main
)

target_link_libraries(
  test_transform
  GTest::gtest_main
)

target_link_libraries(
  test_is_raw_pointer
  GTest::gtest_main
)

target_link_libraries(
  test_flexible_container
  GTest::gtest_main
)

# Discover the tests in both test executables
gtest_discover_tests(test_split)            # Register the tests to gtest
gtest_discover_tests(test_mytype)
gtest_discover_tests(test_sum)
gtest_discover_tests(test_pair)
gtest_discover_tests(test_transform)
gtest_discover_tests(test_is_raw_pointer)
gtest_discover_tests(test_flexible_container)