cmake_minimum_required(VERSION 3.21)
project(habitica)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(Qt6_DIR "/Users/antonclaudia/Qt/6.2.1/macos/lib/cmake")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

include_directories(.)

set(-DCMAKE_PREFIX_PATH=/Users/antonclaudia/Qt/6.2.1/macos/lib/cmake)

find_package(Qt6 COMPONENTS Core Widgets REQUIRED)

add_executable(habitica
        RepoDaily.h
        RepoToDo.h
        RepoHabits.h
        Daily.h
        UI.h
        ControllerUser.h
        RepoUser.h
        Habits.h
        ToDoList.h
        User.h
        main.cpp RepoToDo.h RepoDaily.h)
target_link_libraries(habitica
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

find_package(Qt6 COMPONENTS Core Widgets REQUIRED)

target_link_libraries(habitica Qt6::Core Qt6::Widgets)
