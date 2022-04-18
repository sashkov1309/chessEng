#include <chess/pieces/piece.hh>

class Bishop : public ChessPiece {
public:
    Bishop(Position pos, bool white) : ChessPiece(pos, white) {};
    PieceType Type() override {
        return BISHOP;
    }
    bool CanMove(Position to,  Board &board) override {
        bool diagonal = abs(to.x - position.x) == abs(to.y - position.y);
        if (diagonal) {
            return true;
        }
        return false;
    }
};