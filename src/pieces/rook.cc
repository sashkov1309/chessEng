#include <chess/pieces/rook.hh>

Rook::Rook(Position pos, bool white) : ChessPiece(pos, white) {}

ChessPiece::PieceType Rook::Type() {
    return ROOK;
}

bool Rook::CanMove(Position to, Board &board) {
    bool left_right = to.y - position.y == 0;
    bool up_down = to.x - position.x == 0;
    return left_right || up_down;
}
