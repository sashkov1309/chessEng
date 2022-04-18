#include <chess/pieces/piece.hh>

ChessPiece::ChessPiece(Position pos, bool white) : position(pos), white(white) {}

#define TO_STR(x) case x: return #x;

string ChessPiece::ToStr(ChessPiece::PieceType type) {
    switch (type) {
        TO_STR(QUEEN)
        TO_STR(KING)
        TO_STR(BISHOP)
        TO_STR(KNIGHT)
        TO_STR(ROOK)
        TO_STR(PAWN)
    }
}

string ChessPiece::CharRepresentation(ChessPiece::PieceType type) {
    switch (type) {
        case QUEEN :
            return "Qn";
        case KING :
            return "Kg";
        case BISHOP :
            return "Bp";
        case KNIGHT :
            return "Kn";
        case ROOK :
            return "Rk";
        case PAWN :
            return "Pn";
    }
}

Position ChessPiece::getPosition() {
    return position;
}

void ChessPiece::setPosition(int x, int y) {
    position.x = x;
    position.y = y;
}

bool ChessPiece::White() const {
    return white;
}
