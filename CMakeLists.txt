cmake_minimum_required(VERSION 3.21)
project(chessEngine)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_library(${PROJECT_NAME} SHARED
        src/chessboard.cc
        src/pieces/piece.cc
        src/pieces/rook.cc
        src/pieces/king.cc
        src/pieces/pawn.cc
        src/pieces/bishop.cc
        src/pieces/queen.cc
        src/pieces/knight.cc
        )

add_executable(chessMain main.cpp)
target_link_libraries(chessMain ${PROJECT_NAME})