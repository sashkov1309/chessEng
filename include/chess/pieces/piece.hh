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
    ChessPiece(Position pos, bool white) : position(pos), white(white) {};
    enum PieceType {
        QUEEN,
        KING,
        BISHOP,
        KNIGHT,
        ROOK,
        PAWN
    };
#define TO_STR(x) case x: return #x;
    static string ToStr(PieceType type) {
        switch (type) {
            TO_STR(QUEEN)
            TO_STR(KING)
            TO_STR(BISHOP)
            TO_STR(KNIGHT)
            TO_STR(ROOK)
            TO_STR(PAWN)
        }
    }
    static string CharRepresentation(PieceType type) {
        switch(type) {
            case QUEEN : return "Qn";
            case KING : return "Kg";
            case BISHOP : return "Bp";
            case KNIGHT : return "Kn";
            case ROOK : return "Rk";
            case PAWN : return "Pn";
        }
    }

    virtual PieceType Type() = 0;
    virtual bool CanMove(Position to, Board &board) = 0;
    Position getPosition() {
        return position;
    }
    void setPosition(int x, int y) {
        position.x = x;
        position.y = y;
    }
    bool White() {
        return white;
    }
protected:
    bool white = false;
    Position position;
};

#endif