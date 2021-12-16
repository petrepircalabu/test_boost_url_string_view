cmake_minimum_required (VERSION 3.13)
cmake_policy(SET CMP0048 NEW)

project(test_stringview VERSION 0.1)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Check for boost
find_package(Boost
    1.78.0 REQUIRED
)

find_package(Boost 1.36.0)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    include(FetchContent)

    FetchContent_Declare(
        boosturl
        URL https://github.com/CPPAlliance/url/archive/refs/tags/beta-1.tar.gz
        URL_HASH MD5=5a6f4cecdb4223a48c03c2c28b297cbc
        PATCH_COMMAND patch -p1 < "${CMAKE_CURRENT_SOURCE_DIR}/patches/0001-Change-boost-url-string_view-to-boost-core-string_vi.patch"
    )

    if(NOT boosturl_POPULATED)
        FetchContent_Populate(boosturl)
        #Use Header-only boosturl.
        include_directories(${boosturl_SOURCE_DIR}/include)
        add_compile_definitions(BOOST_URL_NO_LIB)
    endif()

    add_executable(test
	src/main.cpp
    )

endif()

