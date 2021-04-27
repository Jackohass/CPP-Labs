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

public:
    void move_piece(ChessMove chessMove);
    vector<ChessMove> capturingMoves(bool isWhite);
    vector<ChessMove> nonCapturingMoves(bool isWhite);

    /**
     * Returns nullptr
     * else returns the piece on that position
     */
    const ChessPiece* getPiece(int x, int y) const {return state(x,y).get();}
    ChessPiece* getPiece(int x, int y) {return state(x,y).get();}
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
    virtual int validMove(int to_x, int to_y)
    {
        if(to_x < 0 || to_y < 0 || to_x > 7 || to_y > 7) return 0;
        const ChessPiece* piece = board->getPiece(to_x,to_y);
        if(piece != nullptr)
        {
            return piece->isWhite != isWhite ? 2 : 0;
        }
        return 1;
    }
    virtual string utfRepresentation() const {return ".";};     // may be implemented as string
    virtual char latin1Representation() const {return '.';}

public:
    // Constructor
    const bool isWhite;
    ChessPiece(int xPos, int yPos, bool isWhity, ChessBoard * boardy)
    : x{xPos}, y{yPos}, isWhite{isWhity}, board{boardy} {}
    /**
     * Checks if this move is valid for this piece and captures
     * a piece of the opposite color.
     */
    bool capturingMove(int to_x, int to_y)
    {
        return validMove(to_x, to_y) == 2;
    }
    /**
     * Checks if this move is valid but does not capture a piece.
     */
    bool nonCapturingMove(int to_x, int to_y)
    {
        return validMove(to_x, to_y) == 1;
    }
    virtual vector<ChessMove> capturingMoves() {return vector<ChessMove>();}
    virtual vector<ChessMove> nonCapturingMoves() {return vector<ChessMove>();}

    string print(bool utf) const
    {
        
        return utf ? utfRepresentation() : string(1, latin1Representation());
    }

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
    int validMove(int to_x, int to_y)
    {
        int deltaX = abs(x-to_x);
        int deltaY = abs(y-to_y);
        if(deltaX+deltaY == 1 || deltaX*deltaY == 1)
        {
            return ChessPiece::validMove(to_x, to_y);
        }
        return 0;
    }
    // may be implemented as string
    string utfRepresentation() const {return (isWhite ? "♔" : "♚");}
    char latin1Representation() const {return (isWhite ? 'K' : 'k');}

public:
    King(int xPos, int yPos, bool isWhity, ChessBoard * boardy) : ChessPiece(xPos, yPos, isWhity, boardy) {}

    vector<ChessMove> capturingMoves()
    {
        vector<ChessMove> toReturn;
        toReturn.reserve(8);
        int moves[8][2] {
            {x-1,y+1},
            {x,y+1},
            {x+1,y+1},
            {x-1,y},
            {x+1,y},
            {x-1,y-1},
            {x,y-1},
            {x+1,y-1},
        };
        for (int i = 0; i < 8; i++)
        {
            if(capturingMove(moves[i][0], moves[i][1])) toReturn.push_back(ChessMove{x,y,moves[i][0],moves[i][1],this});
        }
        return toReturn;
    }
    vector<ChessMove> nonCapturingMoves()
    {
        vector<ChessMove> toReturn(8);
        int moves[8][2] {
            {x-1,y+1},
            {x,y+1},
            {x+1,y+1},
            {x-1,y},
            {x+1,y},
            {x-1,y-1},
            {x,y-1},
            {x+1,y-1},
        };
        for (int i = 0; i < 8; i++)
        {
            if(nonCapturingMove(moves[i][0], moves[i][1])) toReturn.push_back(ChessMove{x,y,moves[i][0],moves[i][1],this});
        }
        return toReturn;
    }
};

class Knight : public ChessPiece
{
private:
    /* data */

protected:
    int validMove(int to_x, int to_y)
    {
        int deltaX = abs(x-to_x);
        int deltaY = abs(y-to_y);
        if(pow(deltaX,2)+pow(deltaY,2) == 5)
        {
            return ChessPiece::validMove(to_x, to_y);
        }
        return 0;
    }
    // may be implemented as string
    string utfRepresentation() const {return (isWhite ? "♘" : "♞");}
    char latin1Representation() const {return (isWhite ? 'N' : 'n');}

public:
    Knight(int xPos, int yPos, bool isWhity, ChessBoard * boardy) : ChessPiece(xPos, yPos, isWhity, boardy) {}

    vector<ChessMove> capturingMoves()
    {
        vector<ChessMove> toReturn;
        toReturn.reserve(8);
        int moves[8][2] {
            {x+1,y-2},
            {x+2,y-1},
            {x+2,y+1},
            {x+1,y+2},
            {x-1,y+2},
            {x-2,y+1},
            {x-2,y-1},
            {x-1,y-2},
        };
        for (int i = 0; i < 8; i++)
        {
            if(capturingMove(moves[i][0], moves[i][1])) toReturn.push_back(ChessMove{x,y,moves[i][0],moves[i][1],this});
        }
        return toReturn;
    }
    vector<ChessMove> nonCapturingMoves()
    {
        vector<ChessMove> toReturn;
        toReturn.reserve(8);
        int moves[8][2] {
            {x+1,y-2},
            {x+2,y-1},
            {x+2,y+1},
            {x+1,y+2},
            {x-1,y+2},
            {x-2,y+1},
            {x-2,y-1},
            {x-1,y-2},
        };
        for (int i = 0; i < 8; i++)
        {
            if(nonCapturingMove(moves[i][0], moves[i][1])) toReturn.push_back(ChessMove{x,y,moves[i][0],moves[i][1],this});
        }
        return toReturn;
    }
};

class Pawn : public ChessPiece
{
private:
    /* data */

protected:
    int validMove(int to_x, int to_y)
    {
        if(isWhite)
        {
            if(to_x == x && (to_y == y-1 || (y == 6 && to_y == y-2)))
            {
                return ChessPiece::validMove(to_x, to_y) == 1;
            }
            else if(to_y == y-1 && (to_x == x-1 || to_x == x+1))
            {
                return ChessPiece::validMove(to_x, to_y) == 2 ? 2 : 0;
            }
            return 0;
        }
        else
        {
            if(to_x == x && (to_y == y+1 || (y == 1 && to_y == y+2)))
            {
                return ChessPiece::validMove(to_x, to_y) == 1;
            }
            else if(to_y == y+1 && (to_x == x-1 || to_x == x+1))
            {
                return ChessPiece::validMove(to_x, to_y) == 2 ? 2 : 0;
            }
            return 0;
        }
    }
    // may be implemented as string
    string utfRepresentation() const {return (isWhite ? "♙" : "♟︎");}
    char latin1Representation() const {return (isWhite ? 'P' : 'p');}

public:
    Pawn(int xPos, int yPos, bool isWhity, ChessBoard * boardy) : ChessPiece(xPos, yPos, isWhity, boardy) {}

    vector<ChessMove> capturingMoves()
    {
        vector<ChessMove> toReturn;
        toReturn.reserve(2);
        int moves[2][2] = {
            {x+1,y+1-2*isWhite},
            {x-1,y+1-2*isWhite}
        };
        for (int i = 0; i < 2; i++)
        {
            if(capturingMove(moves[i][0], moves[i][1])) toReturn.push_back(ChessMove{x,y,moves[i][0],moves[i][1],this});
        }
        return toReturn;
    }
    vector<ChessMove> nonCapturingMoves()
    {
        vector<ChessMove> toReturn;
        toReturn.reserve(2);
        if(isWhite)
        {
            if(nonCapturingMove(x, y-1)) toReturn.push_back(ChessMove{x,y,x,y-1,this});
            if(y == 6 && nonCapturingMove(x, y-2)) toReturn.push_back(ChessMove{x,y,x,y-2,this});
        }
        else
        {
            if(nonCapturingMove(x, y+1)) toReturn.push_back(ChessMove{x,y,x,y+1,this});
            if(y == 1 && nonCapturingMove(x, y+2)) toReturn.push_back(ChessMove{x,y,x,y+2,this});
        }
        return toReturn;
    }
};

// class Bishop : ChessPiece
// {
// private:
//     /* data */
// public:
//     Bishop(/* args */);
//     ~Bishop();
// };

// class Rook : ChessPiece
// {
// private:
//     /* data */
// public:
//     Rook(/* args */);
//     ~Rook();
// };

// class Queen : ChessPiece
// {
// private:
//     /* data */
// public:
//     Queen(/* args */);
//     ~Queen();
// };

ChessBoard& operator>>(istream& is, ChessBoard& cb);
ostream& operator<<(ostream& os, ChessBoard& cb);
ostream& operator<<(ostream& os, ChessMove& cm);
ostream& operator<<(ostream& os, const vector<ChessMove>& v);