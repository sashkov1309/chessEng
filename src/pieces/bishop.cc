#include <chess/pieces/bishop.hh>

ChessPiece::PieceType Bishop::Type() {
    return BISHOP;
}

Bishop::Bishop(Position pos, bool white) : ChessPiece(pos, white) {}

bool Bishop::CanMove(Position to, Board &board) {
    bool diagonal = abs(to.x - position.x) == abs(to.y - position.y);
    if (diagonal) {
        return true;
    }
    return false;
}
