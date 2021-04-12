
using namespace std;

class ChessPiece;

struct ChessMove {
    int from_x;
    int from_y;
    int to_x;
    int to_y;

    ChessPiece* piece;   // you can change the position of the chess piece with this pointer.
};

class ChessBoard {
// add additional members or functions of your choice

private:
    Matris<ChessPiece* > state; // Matris from lab 4 Matrix

public:
    void move_piece(ChessMove chessMove);
    vector<ChessMove> capturingMoves(bool isWhite);
    vector<ChessMove> nonCapturingMoves(bool isWhite);

};
ChessBoard & operator>>(istream & , ChessBoard &);

class ChessPiece {
friend void ChessBoard::move_piece(ChessMove p);
protected:                               // protected will cause problems
    int x,y;
    bool isWhite;
    ChessBoard* board;
    /**
     * Returns 0 if target square is unreachable.
     * Returns 1 if target square is reachable and empty.
     * Returns 2 if move captures a piece.
     */
    virtual int validMove(int to_x, int to_y);
    virtual char32_t utfRepresentation();     // may be implemented as string
    virtual char latin1Representation();
public:
    // Constructor
    ChessPiece( int x, int y, bool isWhite, ChessBoard * board);
    /**
     * Checks if this move is valid for this piece and captures
     * a piece of the opposite color.
     */
    bool capturingMove(int to_x, int to_y);
    /**
     * Checks if this move is valid but does not capture a piece.
     */
    bool nonCapturingMove(int to_x, int to_y);
    virtual vector<ChessMove> capturingMoves();
    virtual vector<ChessMove> nonCapturingMoves();

    /**
    * For testing multiple inheritance
    */
    int unnecessaryInt;
};