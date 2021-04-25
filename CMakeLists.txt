cmake_minimum_required(VERSION 3.20.0)

project(
    LinkedLists
)

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)

    # Let's nicely support folders in IDEs
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)

    add_subdirectory(app)

endif()

add_library(
    ${PROJECT_NAME}
    STATIC
)

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

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE # All external libraries needed for this project.
        m
)
