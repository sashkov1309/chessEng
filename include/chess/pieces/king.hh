#include <chess/pieces/piece.hh>

class King : public ChessPiece {
public:
    King(Position pos, bool white) : ChessPiece(pos, white) {};
    PieceType Type() override {
        return KING;
    }
    bool CanMove(Position to,  Board &board) override {
        int p_x = abs(to.x - position.x);
        int p_y = abs(to.y - position.y);
        bool diagonal = (p_x == p_y) && (p_x == 1) && (p_y == 1);
        bool left_right = (p_y == 0) && (p_x == 1);
        bool up_down = (p_x == 0) && (p_y == 1);
        if (diagonal || left_right || up_down) {
            return true;
        }
        return false;
    }
private:
    bool hadCastle = false;
};
