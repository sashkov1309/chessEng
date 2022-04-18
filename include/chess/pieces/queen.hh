#include <chess/pieces/piece.hh>

class Queen : public ChessPiece {
public:
    Queen(Position pos, bool white) : ChessPiece(pos, white) {};
    PieceType Type() override {
        return QUEEN;
    }
    bool CanMove(Position to, Board &board) override {
        bool diagonal = abs(to.x - position.x) == abs(to.y - position.y);
        bool left_right = to.y - position.y == 0;
        bool up_down = to.x - position.x == 0;
        if (diagonal || left_right || up_down) {
            return true;
        }
        return false;
    }
};