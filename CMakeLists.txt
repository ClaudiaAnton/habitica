cmake_minimum_required(VERSION 3.21)
project(triedit)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(Qt6_DIR "/Users/antonclaudia/Qt/6.2.1/macos/lib/cmake")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

include_directories(.)



find_package(Qt6 COMPONENTS Core Widgets REQUIRED)

add_executable(triedit
        ToDoList.h
        User.h
        main.cpp)
target_link_libraries(triedit
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

find_package(Qt6 COMPONENTS Core Widgets REQUIRED)

target_link_libraries(triedit Qt6::Core Qt6::Widgets)
