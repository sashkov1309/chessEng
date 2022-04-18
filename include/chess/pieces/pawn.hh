#include <chess/pieces/piece.hh>

class Pawn : public ChessPiece {
public:
    Pawn(Position pos, bool white, bool isFirstMove);;

    PieceType Type() override;

    bool CanMove(Position to, Board &board) override;

private:
    bool isFirstMove = true;
};