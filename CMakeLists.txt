project(qtwebkit-sexp-server)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_definitions(-std=c++11)

aux_source_directory(. SRC_LIST)

set(CMAKE_AUTOMOC ON)

find_package(Qt5Core)

add_executable(${PROJECT_NAME} ${SRC_LIST})
qt5_use_modules(${PROJECT_NAME} WebKitWidgets Network Gui)
