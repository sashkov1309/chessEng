#include <chess/pieces/pawn.hh>

Pawn::Pawn(Position pos, bool white, bool isFirstMove) : ChessPiece(pos, white), isFirstMove(isFirstMove) {}

ChessPiece::PieceType Pawn::Type() {
    return PAWN;
}

bool Pawn::CanMove(Position to, Board &board) {
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
