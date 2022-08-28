set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

list(APPEND RESOURCES ${PROJECT_SOURCE_DIR}/include/gui/resources.qrc)
qt_add_resources(RCC_SOURCES ${RESOURCES})

file(GLOB GUI_SOURCES "*.cpp")

add_library(gui ${GUI_SOURCES} ${RCC_SOURCES})

target_link_libraries(gui
    PUBLIC Qt6::Widgets Qt6::Core chess
)

target_include_directories(gui
    PUBLIC ${PROJECT_SOURCE_DIR}/include/gui
)
