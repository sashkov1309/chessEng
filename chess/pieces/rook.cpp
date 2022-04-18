#include "piece.cpp"

class Rook : public ChessPiece {
public:
    Rook(Position pos, bool white) : ChessPiece(pos, white) {};
    PieceType Type() override {
        return ROOK;
    }
    bool CanMove(Position to, Board &board) override {
        bool left_right = to.y - position.y == 0;
        bool up_down = to.x - position.x == 0;
        return left_right || up_down;
    }
};