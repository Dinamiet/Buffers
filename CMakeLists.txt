cmake_minimum_required(VERSION 3.20.0)

set(
    SRC_FILES
        bufferedlist.c
        linkedlist.c
)

project(LinkedList)
set(PROJECT_LIB ${PROJECT_NAME})
add_library(${PROJECT_NAME} STATIC ${SRC_FILES})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

project(LinkedList_test)
add_executable(${PROJECT_NAME} main.c)
target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_LIB})
