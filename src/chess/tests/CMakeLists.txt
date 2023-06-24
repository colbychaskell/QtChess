set(CMAKE_AUTOMOC OFF)

add_executable(test_pieces test_pieces.cpp main.cpp)
target_link_libraries(test_pieces PRIVATE chess Catch)

add_executable(test_chess test_chess.cpp main.cpp)
target_link_libraries(test_chess PRIVATE chess Catch)

enable_testing()

add_test(NAME "Test Pieces" COMMAND test_pieces)
add_test(NAME "Test Chess" COMMAND test_chess)