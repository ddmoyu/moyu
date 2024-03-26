cmake_minimum_required(VERSION 3.28)

project(moyu)

set(LANGUAGE CXX)

set(VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(STRINGS ".env" ENV_ENTRIES)
foreach(ENV_ENTRY ${ENV_ENTRIES})
    if (ENV_ENTRY MATCHES "^([^=]+)=(.*)$")
        set(ENV_${CMAKE_MATCH_1} ${CMAKE_MATCH_2})
    endif()
endforeach()
#set(CMAKE_PREFIX_PATH D:/Qt6/6.6.2/msvc2019_64)
set(CMAKE_PREFIX_PATH ${ENV_QT6_DIR})

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

include_directories(
    ${PROJECT_SOURCE_DIR}/third_party/sass/include
)

target_link_directories(
    ${PROJECT_NAME}
    PRIVATE
    ${PROJECT_SOURCE_DIR}/third_party/sass/lib
)

target_sources(${PROJECT_NAME}
    PRIVATE
    ${SOURCES}
)

target_link_libraries(${PROJECT_NAME} 
    PRIVATE 
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    Sass
)
