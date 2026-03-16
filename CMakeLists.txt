cmake_minimum_required(VERSION 3.28)

project(scaled_parquet_wide)

set(CMAKE_CXX_STANDARD 23)

find_package(Boost 1.30 COMPONENTS program_options REQUIRED)
find_package(Arrow REQUIRED)
find_package(Parquet REQUIRED)
add_subdirectory(cme)
add_subdirectory(nasdaq)
add_subdirectory(iex)
add_subdirectory(siac)
add_subdirectory(euronext)
