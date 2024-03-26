cmake_minimum_required(VERSION 3.28)

project(moyu)

set(LANGUAGE CXX)

set(VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH E:/Qt6/6.6.1/msvc2019_64)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

qt_standard_project_setup()

if (NOT Qt6_FOUND)
    message(FATAL_ERROR "Not Found Qt6!")
endif ()

file(GLOB_RECURSE SOURCES
        ${PROJECT_SOURCE_DIR}/src/*.cpp
        ${PROJECT_SOURCE_DIR}/src/*.h
        ${PROJECT_SOURCE_DIR}/src/*.ui
)

qt_add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
    PRIVATE
    ${SOURCES}
)

target_link_libraries(${PROJECT_NAME} 
    PRIVATE 
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)

#set(CMAKE_PREFIX_PATH D:/Qt6/6.6.2/msvc2019_64)

