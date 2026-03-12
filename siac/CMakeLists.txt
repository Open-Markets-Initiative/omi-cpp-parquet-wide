cmake_minimum_required(VERSION 3.28)

project(siac_opra_recipient_obi_v6_2_siac)

set(CMAKE_CXX_STANDARD 23)

find_package(Boost 1.30 COMPONENTS program_options REQUIRED)
find_package(Arrow REQUIRED)
find_package(Parquet REQUIRED)
find_package(PkgConfig QUIET)

add_executable(siac_opra_recipient_obi_v6_2_siac main.cpp)
target_link_libraries(siac_opra_recipient_obi_v6_2_siac PRIVATE ${Boost_LIBRARIES} Arrow::arrow_shared Parquet::parquet_shared)
target_include_directories(siac_opra_recipient_obi_v6_2_siac PRIVATE ${Boost_INCLUDE_DIR})

# Decompression libraries
find_package(ZLIB QUIET)
if(ZLIB_FOUND)
    target_link_libraries(siac_opra_recipient_obi_v6_2_siac PRIVATE ZLIB::ZLIB)
    target_compile_definitions(siac_opra_recipient_obi_v6_2_siac PRIVATE HAS_ZLIB)
endif()

pkg_check_modules(ZSTD QUIET libzstd)
if(ZSTD_FOUND)
    target_link_libraries(siac_opra_recipient_obi_v6_2_siac PRIVATE ${ZSTD_LIBRARIES})
    target_include_directories(siac_opra_recipient_obi_v6_2_siac PRIVATE ${ZSTD_INCLUDE_DIRS})
    target_compile_definitions(siac_opra_recipient_obi_v6_2_siac PRIVATE HAS_ZSTD)
endif()

pkg_check_modules(BZIP2 QUIET bzip2)
if(BZIP2_FOUND)
    target_link_libraries(siac_opra_recipient_obi_v6_2_siac PRIVATE ${BZIP2_LIBRARIES})
    target_include_directories(siac_opra_recipient_obi_v6_2_siac PRIVATE ${BZIP2_INCLUDE_DIRS})
    target_compile_definitions(siac_opra_recipient_obi_v6_2_siac PRIVATE HAS_BZIP2)
endif()

pkg_check_modules(LZMA QUIET liblzma)
if(LZMA_FOUND)
    target_link_libraries(siac_opra_recipient_obi_v6_2_siac PRIVATE ${LZMA_LIBRARIES})
    target_include_directories(siac_opra_recipient_obi_v6_2_siac PRIVATE ${LZMA_INCLUDE_DIRS})
    target_compile_definitions(siac_opra_recipient_obi_v6_2_siac PRIVATE HAS_LZMA)
endif()

pkg_check_modules(LZ4 QUIET liblz4)
if(LZ4_FOUND)
    target_link_libraries(siac_opra_recipient_obi_v6_2_siac PRIVATE ${LZ4_LIBRARIES})
    target_include_directories(siac_opra_recipient_obi_v6_2_siac PRIVATE ${LZ4_INCLUDE_DIRS})
    target_compile_definitions(siac_opra_recipient_obi_v6_2_siac PRIVATE HAS_LZ4)
endif()