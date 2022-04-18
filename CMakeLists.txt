cmake_minimum_required(VERSION 3.21)
project(chessEng)

set(CMAKE_CXX_STANDARD 17)

add_executable(chessEng
        main.cpp
        chess/pieces/piece.cpp
        chess/pieces/rook.cpp
        chess/pieces/king.cpp
        chess/pieces/pawn.cpp
        chess/pieces/bishop.cpp
        chess/pieces/queen.cpp
        chess/pieces/knight.cpp
        chess/chessboard.cpp
        )
