cmake_minimum_required(VERSION 3.16)

project(CatInvaders LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

qt_standard_project_setup()

qt_add_executable(CatInvaders main.cpp window.cpp)

set_target_properties(CatInvaders PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)

target_link_libraries(CatInvaders PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)