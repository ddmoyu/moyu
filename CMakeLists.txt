cmake_minimum_required(VERSION 3.28)

project(moyu)

set(LANGUAGE CXX)

set(VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Network Concurrent)

qt_standard_project_setup()

if (NOT Qt6_FOUND)
    message(FATAL_ERROR "Not Found Qt6!")
endif ()

set(QAPPLICATION_CLASS QApplication CACHE STRING "Inheritance class for SingleApplication")

file(GLOB_RECURSE SOURCES
        ${PROJECT_SOURCE_DIR}/src/*.cpp
        ${PROJECT_SOURCE_DIR}/src/*.h
        ${PROJECT_SOURCE_DIR}/src/*.ui
)

qt_add_executable(${PROJECT_NAME})
# no terminal use the following line
# qt_add_executable(${PROJECT_NAME} WIN32)

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

add_subdirectory(third_party/singleapplication)
add_subdirectory(third_party/qtpromise)
add_subdirectory(third_party/simdjson)
add_subdirectory(third_party/pugixml)

target_link_libraries(${PROJECT_NAME} 
    PRIVATE 
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    Qt6::Network
    Qt6::Concurrent
    Sass
    SingleApplication::SingleApplication
    qtpromise
    simdjson
    pugixml
)
