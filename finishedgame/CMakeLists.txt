cmake_minimum_required(VERSION 3.25)
project(CatInvaders)

set(CMAKE_CXX_STANDARD 14)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Multimedia)

qt_standard_project_setup()

qt_add_executable(CatInvaders
        Bullet.cpp
        Bullet.h
        Enemy.cpp
        Enemy.h
        Game.cpp
        Game.h
        Health.cpp
        Health.h
        main.cpp
        Player.cpp
        Player.h
        Score.cpp
        Score.h)

set_target_properties(CatInvaders PROPERTIES
        WIN32_EXECUTABLE TRUE
        MACOSX_BUNDLE TRUE
        )

target_link_libraries(CatInvaders PRIVATE
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
        Qt6::Multimedia
        )
