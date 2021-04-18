cmake_minimum_required(VERSION 3.20.0)

project(LinkedList)
set(PROJECT_LIB ${PROJECT_NAME})

file(GLOB SRC_FILES *.cpp *.c)

add_library(${PROJECT_NAME} STATIC ${SRC_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

project(LinkedList_test)
add_executable(${PROJECT_NAME} main.c)
target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_LIB})
