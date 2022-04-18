#include "piece.cpp"

class Knight : public ChessPiece {
public:
    Knight(Position pos, bool white) : ChessPiece(pos, white) {};
    PieceType Type() override {
        return KNIGHT;
    }
    bool CanMove(Position to, Board &board) override {
        int p_x = abs(to.x - position.x);
        int p_y = abs(to.y - position.y);
        bool first_move = p_x == 1 && p_y == 2;
        bool second_move = p_x == 2 && p_y == 1;
        if (first_move || second_move) {
            return true;
        }
        return false;
    } //подив чи працює
};