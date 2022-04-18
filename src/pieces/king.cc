#include <chess/pieces/king.hh>

King::King(Position pos, bool white) : ChessPiece(pos, white) {}

ChessPiece::PieceType King::Type() {
    return KING;
}

bool King::CanMove(Position to, Board &board) {
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
