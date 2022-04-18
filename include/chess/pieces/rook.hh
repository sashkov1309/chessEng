#include <chess/pieces/piece.hh>

class Rook : public ChessPiece {
public:
    Rook(Position pos, bool white);;

    PieceType Type() override;

    bool CanMove(Position to, Board &board) override;
};