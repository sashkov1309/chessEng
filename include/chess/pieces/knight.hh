#include <chess/pieces/piece.hh>

class Knight : public ChessPiece {
public:
    Knight(Position pos, bool white);;

    PieceType Type() override;

    bool CanMove(Position to, Board &board) override; //подив чи працює
};