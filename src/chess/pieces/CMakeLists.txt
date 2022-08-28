set(CMAKE_AUTOMOC OFF)
file(GLOB SRC "*.cpp")

add_library(pieces ${SRC})

target_include_directories(pieces
    PUBLIC ${PROJECT_SOURCE_DIR}/include/chess/pieces
)

target_include_directories(pieces
    PUBLIC ${PROJECT_SOURCE_DIR}/include/chess
)

add_subdirectory(tests)