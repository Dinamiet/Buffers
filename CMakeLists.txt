cmake_minimum_required(VERSION 3.20.0)

project(
    LinkedLists
)

set(CMAKE_CXX_CLANG_TIDY "/usr/bin/clang-tidy")
set(CMAKE_C_CLANG_TIDY ${CMAKE_CXX_CLANG_TIDY})

set(CMAKE_CXX_CPPCHECK "/usr/bin/cppcheck")
set(CMAKE_C_CPPCHECK ${CMAKE_CXX_CPPCHECK})

set(CMAKE_CXX_CPPLINT "/usr/bin/cpplint")
set(CMAKE_C_CPPLINT ${CMAKE_CXX_CPPLINT})

set(CMAKE_CXX_INCLUDE_WHAT_YOU_USE "/usr/bin/include-what-you-use")
set(CMAKE_C_INCLUDE_WHAT_YOU_USE ${CMAKE_CXX_INCLUDE_WHAT_YOU_USE})

set(CMAKE_LINK_WHAT_YOU_USE TRUE)


if (NOT TARGET ${PROJECT_NAME})

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)

    # Let's nicely support folders in IDEs
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)

    include(CTest)

    add_subdirectory(app)

endif()

add_library(
    ${PROJECT_NAME}
    STATIC
)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
        include
)

target_sources(
    ${PROJECT_NAME}
    PUBLIC  # All public source and header files listed here
        include/linkedlist.h
        include/bufferedlist.h
    PRIVATE # All private source and header files listed here
        src/linkedlist.c
        src/bufferedlist.c
)

endif()
