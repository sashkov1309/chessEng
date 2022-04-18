#include <memory>
#include <chess/chessboard.hh>

using namespace std;

int main() {
    chess::ChessBoard board(8, 8);
    /// BLACK
    for (int i = 0; i < 8; i++) {
        board.AddPiece(std::make_shared<Pawn>(Position(1, i), false, true));
    }
    board.AddPiece(std::make_shared<Rook>(Position(0, 0), false));
    board.AddPiece(std::make_shared<Rook>(Position(0, 7), false));
    board.AddPiece(std::make_shared<Bishop>(Position(0, 2), false));
    board.AddPiece(std::make_shared<Bishop>(Position(0, 5), false));
    board.AddPiece(std::make_shared<Knight>(Position(0, 1), false));
    board.AddPiece(std::make_shared<Knight>(Position(0, 6), false));
    board.AddPiece(std::make_shared<King>(Position(0, 4), false));
    board.AddPiece(std::make_shared<Queen>(Position(0, 3), false));

    /// WHITE
    for (int i = 0; i < 8; i++) {
        board.AddPiece(std::make_shared<Pawn>(Position(6, i), true, true));
    }
    board.AddPiece(std::make_shared<Rook>(Position(7, 0), true));
    board.AddPiece(std::make_shared<Rook>(Position(7, 7), true));
    board.AddPiece(std::make_shared<Bishop>(Position(7, 2), true));
    board.AddPiece(std::make_shared<Bishop>(Position(7, 5), true));
    board.AddPiece(std::make_shared<Knight>(Position(7, 1), true));
    board.AddPiece(std::make_shared<Knight>(Position(7, 6), true));
    board.AddPiece(std::make_shared<King>(Position(7, 4), true));
    board.AddPiece(std::make_shared<Queen>(Position(7, 3), true));
    board.Draw();

    board.Move(Position(6, 4), Position(4, 4));
    board.Draw();

    board.Move(Position(1, 4), Position(3, 4));
    board.Draw();

    board.Move(Position(7, 3), Position(3, 7));
    board.Draw();

    board.Move(Position(0, 1), Position(2, 2));
    board.Draw();

    // bishop moving
    board.Move(Position(7, 5), Position(4, 2));
    board.Draw();

    board.Move(Position(0, 6), Position(2, 5));
    board.Draw();

    board.Move(Position(3, 7), Position(1, 5));
    board.Draw();

    return 0;
}


