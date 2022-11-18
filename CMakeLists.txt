cmake_minimum_required(VERSION 3.23)
project(ESGI_casseBrick C)

set(CMAKE_C_STANDARD 11)

add_executable(ESGI_casseBrick main.c src/player.c header/player.h src/board.c header/board.h src/bomb.c header/bomb.h src/cell.c header/cell.h src/filereader.c header/filereader.h src/object.c header/object.h src/my_math.c header/my_math.h)
add_executable(TEST_bomb test_src/test_bomb.c src/player.c header/player.h src/board.c header/board.h src/bomb.c header/bomb.h src/cell.c header/cell.h src/object.c header/object.h)
add_executable(TEST_cell test_src/test_cell.c src/player.c header/player.h src/board.c header/board.h src/bomb.c header/bomb.h src/cell.c header/cell.h src/object.c header/object.h)
add_executable(TEST_board test_src/test_board.c  src/player.c header/player.h src/board.c header/board.h src/bomb.c header/bomb.h src/cell.c header/cell.h src/object.c header/object.h src/filereader.c header/filereader.h)
add_executable(TEST_player test_src/test_player.c src/player.c header/player.h src/board.c header/board.h src/bomb.c header/bomb.h src/cell.c header/cell.h src/object.c header/object.h)
add_executable(TEST_filereader test_src/test_filereader.c src/filereader.c header/filereader.h src/object.c header/object.h src/cell.c header/cell.h src/board.c header/board.h)


add_executable(TEST_my_math test_src/test_my_math.c src/player.c header/player.h src/board.c header/board.h src/bomb.c header/bomb.h src/cell.c header/cell.h src/filereader.c header/filereader.h src/object.c header/object.h src/my_math.c header/my_math.h)
