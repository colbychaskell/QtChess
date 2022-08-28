set(CMAKE_AUTOMOC OFF)
file(GLOB SRC "*.cpp")

file(GLOB PIECES "pieces/*.cpp")

add_library(chess ${SRC})

target_link_libraries(chess pieces)

target_include_directories(chess
    PUBLIC ${PROJECT_SOURCE_DIR}/include/chess
)

add_subdirectory(tests)
add_subdirectory(pieces)
