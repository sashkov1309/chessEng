#include <iostream>
#include <utility>
#include <cassert>
#include <memory>
#include <vector>

using namespace std;

#include <chess/pieces/bishop.hh>
#include <chess/pieces/king.hh>
#include <chess/pieces/knight.hh>
#include <chess/pieces/pawn.hh>
#include <chess/pieces/queen.hh>
#include <chess/pieces/rook.hh>

namespace chess {

class ChessBoard {
public:
    ChessBoard(int rows, int cols);

    bool AddPiece(ChessPiecePtr piece);;

    bool isOnBoard(Position to);

    bool Move(Position from, Position to);

    bool Move(ChessPiecePtr piece, Position to);

    ChessPiecePtr Piece(Position pos);

    int getRows();

    int getCols();

    static bool isWhite(const ChessPiecePtr &piece);

    bool isCheck(bool white);

    bool IsNothingBetween(Position from, Position to);

    void Draw();

private:
    vector<vector<ChessPiecePtr>> board;
};


}

