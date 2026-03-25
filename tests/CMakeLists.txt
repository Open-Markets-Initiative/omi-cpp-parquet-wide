cmake_minimum_required(VERSION 3.28)

set(CMAKE_CXX_STANDARD 23)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.tar.gz
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

find_package(Arrow REQUIRED)
find_package(Parquet REQUIRED)

enable_testing()

add_executable(cme_tests cme_tests.cpp)
target_link_libraries(cme_tests PRIVATE GTest::gtest_main Arrow::arrow_shared Parquet::parquet_shared)
add_test(NAME cme_tests COMMAND cme_tests)

add_executable(nasdaq_tests nasdaq_tests.cpp)
target_link_libraries(nasdaq_tests PRIVATE GTest::gtest_main Arrow::arrow_shared Parquet::parquet_shared)
add_test(NAME nasdaq_tests COMMAND nasdaq_tests)

add_executable(iex_tests iex_tests.cpp)
target_link_libraries(iex_tests PRIVATE GTest::gtest_main Arrow::arrow_shared Parquet::parquet_shared)
add_test(NAME iex_tests COMMAND iex_tests)

add_executable(siac_tests siac_tests.cpp)
target_link_libraries(siac_tests PRIVATE GTest::gtest_main Arrow::arrow_shared Parquet::parquet_shared)
add_test(NAME siac_tests COMMAND siac_tests)

add_executable(euronext_tests euronext_tests.cpp)
target_link_libraries(euronext_tests PRIVATE GTest::gtest_main Arrow::arrow_shared Parquet::parquet_shared)
add_test(NAME euronext_tests COMMAND euronext_tests)
