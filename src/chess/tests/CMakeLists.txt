set(CMAKE_AUTOMOC OFF)

add_executable(test_pieces test_pieces.cpp main.cpp)
target_link_libraries(test_pieces PRIVATE chess Catch)

enable_testing()

add_test(NAME "Test Pieces" COMMAND test_pieces)