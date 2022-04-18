#include <chess/pieces/piece.hh>

class Queen : public ChessPiece {
public:
    Queen(Position pos, bool white);;

    PieceType Type() override;

    bool CanMove(Position to, Board &board) override;
};