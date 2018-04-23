cmake_minimum_required(VERSION 2.8.11)
set (QT_MIN_VERSION "5.2.0")

project(helloworld)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 ${QT_MIN_VERSION} CONFIG REQUIRED Core Gui Quick)

add_executable(hello main.cpp main.qrc)

target_link_libraries(hello Qt5::Core Qt5::Gui Qt5::Quick)
