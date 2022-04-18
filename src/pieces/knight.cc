#include <chess/pieces/knight.hh>

Knight::Knight(Position pos, bool white) : ChessPiece(pos, white) {}

ChessPiece::PieceType Knight::Type() {
    return KNIGHT;
}

bool Knight::CanMove(Position to, Board &board) {
    int p_x = abs(to.x - position.x);
    int p_y = abs(to.y - position.y);
    bool first_move = p_x == 1 && p_y == 2;
    bool second_move = p_x == 2 && p_y == 1;
    if (first_move || second_move) {
        return true;
    }
    return false;
}
