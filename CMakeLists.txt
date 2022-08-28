cmake_minimum_required(VERSION 3.24)
project(
    QtChess
    VERSION 1.0.0
    LANGUAGES CXX)

enable_testing()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_INCLUDE_CURRENT_DIR YES)
set(CMAKE_AUTOMOC ON)

add_executable(${PROJECT_NAME} src/chess.cpp include/gui/mainwindow.h)

target_link_libraries(${PROJECT_NAME} PRIVATE chess)
target_link_libraries(${PROJECT_NAME} PRIVATE gui)

set_target_properties(${PROJECT_NAME} PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)

add_subdirectory(src/chess)
add_subdirectory(src/gui)
add_subdirectory(libs)