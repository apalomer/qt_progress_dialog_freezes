# Set up cmake
cmake_minimum_required (VERSION 3.0)
project (qt_progress_bar_freezes CXX)

# Find LIbrary
find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets)
# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)

add_subdirectory(src)
