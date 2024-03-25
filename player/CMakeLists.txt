cmake_minimum_required(VERSION 3.28)

project(player)

set(VERSION 0.0.1)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets REQUIRED)

qt_standard_project_setup()

qt_add_executable(${PROJECT_NAME})

file(GLOB_RECURSE SOURCES 
    "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.ui"
)

target_sources(
    ${PROJECT_NAME}
    PRIVATE
    ${SOURCES}
)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}_autogen/include)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)