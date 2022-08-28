cmake_minimum_required(VERSION 3.24)
project(
    QtChess
    VERSION 1.0.0
    LANGUAGES CXX)

include(InstallRequiredSystemLibraries)

set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
set(CPACK_PACKAGE_VERSION_MAJOR "${CMAKE_PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${CMAKE_PROJECT_VERSION_MINOR}")
set(CPACK_SOURCE_GENERATOR "TGZ")

include(CPack)

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

enable_testing()
add_subdirectory(src/chess)
add_subdirectory(src/gui)
add_subdirectory(libs)