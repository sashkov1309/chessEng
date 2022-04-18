#include <iostream>
#include <utility>
#include <cassert>
#include <memory>
#include <vector>
using namespace std;

#include <chess/pieces/bishop.hh>
#include <chess/pieces/king.hh>
#include <chess/pieces/knight.hh>
#include <chess/pieces/pawn.hh>
#include <chess/pieces/queen.hh>
#include <chess/pieces/rook.hh>

class ChessBoard {
public:
    ChessBoard(int rows, int cols) {
        board = vector<vector<ChessPiecePtr>>(rows, vector <ChessPiecePtr>(cols, nullptr));
    }

    bool AddPiece(ChessPiecePtr piece) {
        auto pos = piece->getPosition();
        if (isOnBoard(pos)) {
            if (!Piece(pos)) {
                board[pos.x][pos.y] = piece;
                return true;
            }
        } else {
            cout << "Can't put a chess piece on cell with negative coordinates.\n";
            return false;
        }
    };

    bool isOnBoard(Position to) {
        return to.x >= 0 && to.x < getRows() && to.y >= 0 && to.y < getCols();
    }

    bool Move(Position from,  Position to) {
        return Move(Piece(from), to);
    }

    bool Move(ChessPiecePtr piece, Position to) {
        if (isOnBoard(to) && piece->CanMove(to, board)) {
            if (board[to.x][to.y]) {
                if (board[to.x][to.y]->White() == piece->White()) {
                    cout << "Can't take friendly piece.\n";
                    return false;
                } else {
                    cout << "The " << ChessPiece::ToStr(board[to.x][to.y]->Type()) << " was taken by " << ChessPiece::ToStr(piece->Type()) << ".\n";
                }
            }
            board[piece->getPosition().x][piece->getPosition().y] = nullptr;
            board[to.x][to.y] = piece;
            piece->setPosition(to.x, to.y);
            if (isCheck(piece->White())) {
                cout << "White king is under attack.\n";
                // todo: дописати
            }
            return true;
        } else {
            cout << ChessPiece::ToStr(piece->Type()) << " can't move like this.\n";
            return false;
        }
    }
    ChessPiecePtr Piece(Position pos) {
        return board[pos.x][pos.y];
    }

    int getRows() {
        return board.size();
    }
    int getCols() {
        return board.front().size();
    }

    bool isWhite(const ChessPiecePtr& piece) {
        return piece->White();
    }

    bool isCheck(bool white) {
        Position kingPos(-1, -1);
        for (int x = 0; x < getRows(); x++) {
            for (int y = 0; y < getCols(); y++) {
                if (board[x][y]) {
                    if (board[x][y]->Type() == ChessPiece::KING && board[x][y]->White() != white) {
                        kingPos.x = x;
                        kingPos.y = y;
                    }
                }
            }
        }
        if (kingPos.x != -1 && kingPos.y != -1) {
            for (int x = 0; x < getRows(); x++) {
                for (int y = 0; y < getCols(); y++) {
                    if (board[x][y]) {
                        if (board[x][y]->Type() != ChessPiece::KING && board[x][y]->White() != board[kingPos.x][kingPos.y]->White()) { // != white as parameter
                            if (board[x][y]->CanMove(kingPos, board) && IsNothingBetween(Position(x, y), kingPos)) {
                                cout << "\nCheck by ";
                                cout << (board[x][y]->White() ? "white " : "black ");
                                cout << ChessPiece::ToStr(board[x][y]->Type()) << ".\n";
                                return true;
                            }
                        }
                    }
                }
            }
        }
        return false;
    }

    bool IsNothingBetween(Position from, Position to) {
        ChessPiecePtr piece = board[from.x][from.y];
        assert(piece->CanMove(to, board));
        if (piece->Type() == ChessPiece::KING || piece->Type() == ChessPiece::PAWN || piece->Type() == ChessPiece::KNIGHT) {
            return true;
        }

        int dist = max(abs(to.x - from.x), abs(to.y - from.y));
        Position shift((to.x - from.x) / dist, (to.y - from.y) / dist);

        int xss = from.x + shift.x;
        int yss = from.y + shift.y;
        for (int xs = xss, ys = yss; xs < to.x || ys < to.y; xs += shift.x, ys += shift.y) {
            if (board[xs][ys])
                return false;
        }
        return true;
    }

    void Draw() {
        cout << '\n';
        for (int i = 0; i < getCols(); i++) {
            cout << ' ' << i << "  ";
        }
//        cout << '\n';
//        for (int i = 0; i < getCols(); i++) {
//            cout << " ___";
//        }
        cout << '\n';
        for (int i = 0; i < getRows(); i++) {
            for (int j = 0; j < getCols(); j++) {
                if (Piece({i, j})) {
                    cout << '|';
                    if (Piece({i, j})->White()) {
                        cout << '+';
                    } else {
                        cout << '-';
                    }
                    cout << ChessPiece::CharRepresentation(board[i][j]->Type());
                } else {
                    cout << "|___";
                }
            }
            cout << '|' << ' ' << i << '\n';
        }
        cout << "======================================================\n";
    }
private:
    vector <vector<ChessPiecePtr>> board;
};
