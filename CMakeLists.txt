cmake_minimum_required(VERSION 3.21)
project(chessEngine)

set(CMAKE_CXX_STANDARD 17)

add_library(${PROJECT_NAME} SHARED
        chess/chessboard.cpp
        chess/pieces/piece.cpp
        chess/pieces/rook.cpp
        chess/pieces/king.cpp
        chess/pieces/pawn.cpp
        chess/pieces/bishop.cpp
        chess/pieces/queen.cpp
        chess/pieces/knight.cpp
        chess/chessboard.cpp
        )

include_directories(chess)

add_executable(chessMain
        main.cpp
        )

target_link_libraries(chessMain ${PROJECT_NAME})