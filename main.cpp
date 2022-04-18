#include <memory>
#include "chessboard.cpp"

using namespace std;

int main() {
    ChessBoard board(4, 4);
    auto queen = std::make_shared <Queen>(Position(2, 0), true);
    board.AddPiece(queen);
    board.Draw();
    board.Move(queen, Position(0, 0));
    board.Draw();
    auto king = std::make_shared <King>(Position(2, 0), true);
    board.AddPiece(king);
    board.Draw();

    auto BlackQueen = std::make_shared<Queen>(Position(0, 1), false);
    board.AddPiece(BlackQueen);
    board.Draw();

    board.Move(BlackQueen, Position(0, 3));
    board.Draw();
    auto bishop = std::make_shared<Bishop>(Position(1, 1), false);
    board.AddPiece(bishop);
    board.Draw();
    board.Move(bishop, Position(0, 2));
    board.Draw();

    auto BlackKnight = std::make_shared<Knight>(Position(2, 3), false);
    board.AddPiece(BlackKnight);
    board.Draw();
    board.Move(BlackKnight, Position(1, 1));
    board.Draw();
    return 0;
}


