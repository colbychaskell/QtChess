set(CMAKE_AUTOMOC OFF)

add_executable(test_bishop test_bishop.cpp main.cpp)
target_link_libraries(test_bishop PRIVATE chess Catch)

add_executable(test_knight test_knight.cpp main.cpp)
target_link_libraries(test_knight PRIVATE chess Catch)

add_executable(test_king test_king.cpp main.cpp)
target_link_libraries(test_king PRIVATE chess Catch)

add_executable(test_queen test_queen.cpp main.cpp)
target_link_libraries(test_queen PRIVATE chess Catch)

add_executable(test_pawn test_pawn.cpp main.cpp)
target_link_libraries(test_pawn PRIVATE chess Catch)

add_executable(test_rook test_rook.cpp main.cpp)
target_link_libraries(test_rook PRIVATE chess Catch)

enable_testing()

add_test(NAME "Bishop Tests" COMMAND test_bishop)
add_test(NAME "Knight Tests" COMMAND test_knight)
add_test(NAME "King Tests" COMMAND test_king)
add_test(NAME "Queen Tests" COMMAND test_queen)
add_test(NAME "Pawn Tests" COMMAND test_pawn)
add_test(NAME "Rook Tests" COMMAND test_rook)



