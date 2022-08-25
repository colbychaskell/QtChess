cmake_minimum_required(VERSION 3.24)
project(
    QtChess
    VERSION 1.0.0
    LANGUAGES CXX)

enable_testing()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_INCLUDE_CURRENT_DIR YES)

list(APPEND RESOURCES src/gui/resources.qrc)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

qt_add_resources(RCC_SOURCES ${RESOURCES})

file(GLOB SOURCES "src/chess/*.cpp")
file(GLOB GUI_SOURCES "src/gui/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES} ${GUI_SOURCES} ${RCC_SOURCES} include/mainwindow.h include/boardqt.h)

target_include_directories(${PROJECT_NAME}
    PRIVATE ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE Qt6::Widgets Qt6::Core
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)
