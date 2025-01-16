cmake_minimum_required(VERSION 3.10)

project(MyWindowManager)

set(CMAKE_CXX_STANDARD 17)

find_package(X11 REQUIRED)

set(SOURCES main.cpp)

add_executable(my_window_manager src/main.cpp src/XDirector.cpp)

target_link_libraries(my_window_manager PRIVATE ${X11_LIBRARIES})
target_include_directories(my_window_manager PRIVATE ${X11_INCLUDE_DIR})