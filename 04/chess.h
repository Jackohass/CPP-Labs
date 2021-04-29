#pragma once

#include<iostream>
#include<vector>
#include<cmath>
#include<memory>
#include<string>
#include"matris.h"

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
friend ChessBoard& operator>>(istream& is, ChessBoard& cb);
// add additional members or functions of your choice

private:
    Matris<shared_ptr<ChessPiece>> state; // Matris from lab 4 Matrix
    int numWhite;
    int numBlack;

public:
    void move_piece(ChessMove chessMove);
    void move_piecePromotion(ChessMove chessMove, char sign);
    vector<ChessMove> capturingMoves(bool isWhite);
    vector<ChessMove> nonCapturingMoves(bool isWhite);
    int getNumWhite() {return numWhite;}
    int getNumBlack() {return numBlack;}
    bool isPawnPromotion(ChessMove chessMove);
    void deepCopy(ChessBoard& cb); 

    /**
     * Returns nullptr
     * else returns the piece on that position
     */
    const ChessPiece* getPiece(int x, int y);
    ChessPiece* getPiece(int x, int y);
};

class ChessPiece {
//friend void ChessBoard::move_piece(ChessMove p);
friend class ChessBoard;
protected:                               // protected will cause problems
    int x,y;
    
    ChessBoard* board;
    /**
     * Returns 0 if target square is unreachable.
     * Returns 1 if target square is reachable and empty.
     * Returns 2 if move captures a piece.
     */
    virtual int validMove(int to_x, int to_y);
    virtual string utfRepresentation() const;   // may be implemented as string
    virtual char latin1Representation() const;

public:
    virtual void changePos(int toX, int toY);
    // Constructor
    const bool isWhite;
    ChessPiece(int xPos, int yPos, bool isWhity, ChessBoard * boardy);
    /**
     * Checks if this move is valid for this piece and captures
     * a piece of the opposite color.
     */
    bool capturingMove(int to_x, int to_y);
    /**
     * Checks if this move is valid but does not capture a piece.
     */
    bool nonCapturingMove(int to_x, int to_y);
    virtual vector<ChessMove> capturingMoves() {return vector<ChessMove>();}
    virtual vector<ChessMove> nonCapturingMoves() {return vector<ChessMove>();}

    string print(bool utf) const;

    /**
    * For testing multiple inheritance
    */
    int unnecessaryInt;
};

class King : public ChessPiece
{
private:
    /* data */

protected:
    int validMove(int to_x, int to_y);
    // may be implemented as string
    string utfRepresentation() const;
    char latin1Representation() const;

public:
    King(int xPos, int yPos, bool isWhity, ChessBoard * boardy);

    vector<ChessMove> capturingMoves();
    vector<ChessMove> nonCapturingMoves();
};

class Knight : public ChessPiece
{
private:
    /* data */

protected:
    int validMove(int to_x, int to_y);
    // may be implemented as string
    string utfRepresentation();
    char latin1Representation();

public:
    Knight(int xPos, int yPos, bool isWhity, ChessBoard * boardy);

    vector<ChessMove> capturingMoves();
    vector<ChessMove> nonCapturingMoves();
};

class Pawn : public ChessPiece
{
private:
    /* data */

protected:
    int validMove(int to_x, int to_y);
    // may be implemented as string
    string utfRepresentation() const;
    char latin1Representation() const;
public:
    Pawn(int xPos, int yPos, bool isWhity, ChessBoard * boardy);

    vector<ChessMove> capturingMoves();
    vector<ChessMove> nonCapturingMoves();
};

class Rook : public ChessPiece
{
private:
    /* data */

protected:
    int validMove(int to_x, int to_y);
    // may be implemented as string
    string utfRepresentation() const;
    char latin1Representation() const;

public:
    Rook(int xPos, int yPos, bool isWhity, ChessBoard * boardy);

    vector<ChessMove> capturingMoves();
    vector<ChessMove> nonCapturingMoves();
};

class Bishop : public ChessPiece
{
private:
    /* data */

protected:
    int validMove(int to_x, int to_y);
    string utfRepresentation() const;
    char latin1Representation() const;

public:
    Bishop(int xPos, int yPos, bool isWhity, ChessBoard * boardy);

    vector<ChessMove> capturingMoves();
    vector<ChessMove> nonCapturingMoves();
};

ostream& operator<<(ostream& os, const vector<ChessMove>& v);
class Queen : public Rook, public Bishop
{
private:
    /* data */

protected:
    int validMove(int to_x, int to_y);
    string utfRepresentation() const;
    char latin1Representation() const;

public:
    Queen(int xPos, int yPos, bool isWhity, ChessBoard * boardy);

    virtual void changePos(int toX, int toY);

    vector<ChessMove> capturingMoves();
    vector<ChessMove> nonCapturingMoves();
};

ChessBoard& operator>>(istream& is, ChessBoard& cb);
ostream& operator<<(ostream& os, ChessBoard& cb);
ostream& operator<<(ostream& os, ChessMove& cm);
