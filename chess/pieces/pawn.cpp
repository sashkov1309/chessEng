#include "piece.cpp"

class Pawn : public ChessPiece {
public:
    Pawn(Position pos, bool white, bool isFirstMove) : ChessPiece(pos, white), isFirstMove(isFirstMove) {};
    PieceType Type() override {
        return PAWN;
    }
    bool CanMove(Position to,  Board &board) override {\
        // TODO: fix this later
        int p_y = abs(to.x - position.x);
        int p_x = abs(to.y - position.y);
        if (isFirstMove) {
            if ((p_y == 2 || p_y == 1) && (p_x == 0)) {
                return true;
            }
        } else {
            if (p_y == 1 && p_x == 0) {
                return true;
            }
        }
        return false;
    }
private:
    bool isFirstMove = true;
};