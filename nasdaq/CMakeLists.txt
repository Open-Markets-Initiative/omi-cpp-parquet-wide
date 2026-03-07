cmake_minimum_required(VERSION 3.28)

project(nasdaq_nsmequities_totalview_itch_v5_0_nasdaq)

set(CMAKE_CXX_STANDARD 23)

find_package(Boost 1.30 COMPONENTS program_options REQUIRED)
find_package(Arrow REQUIRED)
find_package(Parquet REQUIRED)
find_package(PkgConfig QUIET)

add_executable(nasdaq_nsmequities_totalview_itch_v5_0_nasdaq main.cpp)
target_link_libraries(nasdaq_nsmequities_totalview_itch_v5_0_nasdaq PRIVATE ${Boost_LIBRARIES} Arrow::arrow_shared Parquet::parquet_shared)
target_include_directories(nasdaq_nsmequities_totalview_itch_v5_0_nasdaq PRIVATE ${Boost_INCLUDE_DIR})

# Decompression libraries
find_package(ZLIB QUIET)
if(ZLIB_FOUND)
    target_link_libraries(nasdaq_nsmequities_totalview_itch_v5_0_nasdaq PRIVATE ZLIB::ZLIB)
    target_compile_definitions(nasdaq_nsmequities_totalview_itch_v5_0_nasdaq PRIVATE HAS_ZLIB)
endif()

pkg_check_modules(ZSTD QUIET libzstd)
if(ZSTD_FOUND)
    target_link_libraries(nasdaq_nsmequities_totalview_itch_v5_0_nasdaq PRIVATE ${ZSTD_LIBRARIES})
    target_include_directories(nasdaq_nsmequities_totalview_itch_v5_0_nasdaq PRIVATE ${ZSTD_INCLUDE_DIRS})
    target_compile_definitions(nasdaq_nsmequities_totalview_itch_v5_0_nasdaq PRIVATE HAS_ZSTD)
endif()

pkg_check_modules(BZIP2 QUIET bzip2)
if(BZIP2_FOUND)
    target_link_libraries(nasdaq_nsmequities_totalview_itch_v5_0_nasdaq PRIVATE ${BZIP2_LIBRARIES})
    target_include_directories(nasdaq_nsmequities_totalview_itch_v5_0_nasdaq PRIVATE ${BZIP2_INCLUDE_DIRS})
    target_compile_definitions(nasdaq_nsmequities_totalview_itch_v5_0_nasdaq PRIVATE HAS_BZIP2)
endif()

pkg_check_modules(LZMA QUIET liblzma)
if(LZMA_FOUND)
    target_link_libraries(nasdaq_nsmequities_totalview_itch_v5_0_nasdaq PRIVATE ${LZMA_LIBRARIES})
    target_include_directories(nasdaq_nsmequities_totalview_itch_v5_0_nasdaq PRIVATE ${LZMA_INCLUDE_DIRS})
    target_compile_definitions(nasdaq_nsmequities_totalview_itch_v5_0_nasdaq PRIVATE HAS_LZMA)
endif()

pkg_check_modules(LZ4 QUIET liblz4)
if(LZ4_FOUND)
    target_link_libraries(nasdaq_nsmequities_totalview_itch_v5_0_nasdaq PRIVATE ${LZ4_LIBRARIES})
    target_include_directories(nasdaq_nsmequities_totalview_itch_v5_0_nasdaq PRIVATE ${LZ4_INCLUDE_DIRS})
    target_compile_definitions(nasdaq_nsmequities_totalview_itch_v5_0_nasdaq PRIVATE HAS_LZ4)
endif()