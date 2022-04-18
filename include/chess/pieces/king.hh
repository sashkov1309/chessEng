#include <chess/pieces/piece.hh>

class King : public ChessPiece {
public:
    King(Position pos, bool white);;

    PieceType Type() override;

    bool CanMove(Position to, Board &board) override;

private:
    bool hadCastle = false;
};
