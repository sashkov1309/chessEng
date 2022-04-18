#include <chess/pieces/piece.hh>

class Bishop : public ChessPiece {
public:
    Bishop(Position pos, bool white);;

    PieceType Type() override;

    bool CanMove(Position to, Board &board) override;
};