#include <iostream>
#include <utility>
#include <cassert>
#include <memory>
#include <vector>

using namespace std;

#ifndef CHESS_PIECE
#define CHESS_PIECE

class ChessPiece;

using ChessPiecePtr = shared_ptr<ChessPiece>;
using Board = vector<vector<ChessPiecePtr>>;

struct Position {
    int x;
    int y;

    Position(int x, int y) : x(x), y(y) {}
};

class ChessPiece {
public:
    ChessPiece(Position pos, bool white);;
    enum PieceType {
        QUEEN,
        KING,
        BISHOP,
        KNIGHT,
        ROOK,
        PAWN
    };

    static string ToStr(PieceType type);

    static string CharRepresentation(PieceType type);

    virtual PieceType Type() = 0;

    virtual bool CanMove(Position to, Board &board) = 0;

    Position getPosition();

    void setPosition(int x, int y);

    bool White() const;

protected:
    bool white = false;
    Position position;
};

#endif