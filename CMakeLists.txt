cmake_minimum_required(VERSION 3.28)

project(moyu)

set(LANGUAGE CXX)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_PREFIX_PATH D:/Qt6/6.6.2/msvc2019_64)

add_subdirectory(main)
add_subdirectory(manager)
add_subdirectory(player)
add_subdirectory(downloader)
