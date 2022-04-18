#include <chess/pieces/queen.hh>

ChessPiece::PieceType Queen::Type() {
    return QUEEN;
}

Queen::Queen(Position pos, bool white) : ChessPiece(pos, white) {}

bool Queen::CanMove(Position to, Board &board) {
    bool diagonal = abs(to.x - position.x) == abs(to.y - position.y);
    bool left_right = to.y - position.y == 0;
    bool up_down = to.x - position.x == 0;
    if (diagonal || left_right || up_down) {
        return true;
    }
    return false;
}
