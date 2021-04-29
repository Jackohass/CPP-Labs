#include"chess.h"
#include<sstream>
#include <fstream>

using namespace std;

void testBoards()
{
    ChessBoard chess;
    ifstream myfile("data.txt");
    if (myfile.is_open())
    {
        while (!myfile.eof())
        {
            myfile >> chess;
            cout << chess;
            vector<ChessMove> vW = chess.capturingMoves(true);
            cout << "Number of white capturing moves: " << vW.size() << " moves\n";
            vector<ChessMove> vB = chess.capturingMoves(false);
            cout << "Number of black capturing moves: " << vB.size() << " moves\n";
            cout << endl;
        }
        myfile.close();
    }
}

int main()
{
    ChessBoard chess;
    stringstream s;
    // s << "........" << endl;
    // s << "........" << endl;
    // s << "........" << endl;
    // s << "........" << endl;
    // s << "........" << endl;
    // s << "........" << endl;
    // s << "........" << endl;
    // s << "........";
    // s << ".....K.." << endl;
    // s << ".....k.." << endl;
    // s << "......K." << endl;
    // s << "k......." << endl;
    // s << ".......K" << endl;
    // s << ".k......" << endl;
    // s << "....K..." << endl;
    // s << "..k.....";
    // s << ".....N.." << endl;
    // s << "........" << endl;
    // s << "....n..." << endl;
    // s << "........" << endl;
    // s << "........" << endl;
    // s << "....n..." << endl;
    // s << "........" << endl;
    // s << "........";
    // s << "....P..." << endl;
    // s << "....p..." << endl;
    // s << ".p.P...." << endl;
    // s << "..P....." << endl;
    // s << "....p.p." << endl;
    // s << "...p.P.." << endl;
    // s << "..P....." << endl;
    // s << ".....p..";
    // s << "R......r" << endl;
    // s << "........" << endl;
    // s << "...R...." << endl;
    // s << "...Rrr.." << endl;
    // s << "..rrR..." << endl;
    // s << "....R..." << endl;
    // s << "........" << endl;
    // s << "r......R";
    // s << "R......r" << endl;
    // s << "........" << endl;
    // s << "....r..." << endl;
    // s << "..RRr..." << endl;
    // s << "...rRR.." << endl;
    // s << "...r...." << endl;
    // s << "........" << endl;
    // s << "r......R";
    // s << "...p.p.." << endl;
    // s << "...P.p.." << endl;
    // s << "........" << endl;
    // s << "........" << endl;
    // s << "........" << endl;
    // s << "........" << endl;
    // s << "........" << endl;
    // s << "........";
    // s << "B......b" << endl;
    // s << "........" << endl;
    // s << "........" << endl;
    // s << "bb....BB" << endl;
    // s << "BB....bb" << endl;
    // s << "........" << endl;
    // s << "........" << endl;
    // s << "b......B";
    // s << "Q......." << endl;
    // s << ".......P" << endl;
    // s << "........" << endl;
    // s << "........" << endl;
    // s << "........" << endl;
    // s << "........" << endl;
    // s << ".Q.....p" << endl;
    // s << ".q......";
    // s << "rnbqkbnr" << endl;
    // s << "pppppppp" << endl;
    // s << "........" << endl;
    // s << "........" << endl;
    // s << "........" << endl;
    // s << "........" << endl;
    // s << "PPPPPPPP" << endl;
    // s << "RNBQKBNR";

    // cout << s.str() << endl;
    // s >> chess;
    // cout << chess << endl;

    // chess.move_piece(ChessMove{7,1,7,0,chess.getPiece(7,1)});
    // chess.move_piece(ChessMove{7,6,7,7,chess.getPiece(7,6)});
    // cout << chess << endl;
    // cout << chess.getPiece(7,7)->print(false).compare("p") << endl;

    // vector<ChessMove> v = chess.capturingMoves(false);
    // cout << "capturingMoves: got " << v.size() << " moves" << endl;
    // cout << "capturingMoves: " << v << endl;
    // vector<ChessMove> v0 = chess.nonCapturingMoves(false);
    // cout << "nonCapturingMoves: got " << v0.size() << " moves" << endl;
    // cout << "nonCapturingMoves: " << v0 << endl;

    // vector<ChessMove> vW = chess.capturingMoves(true);
    // cout << "Number of white capturing moves: " << vW.size() << " moves" << endl;
    // vector<ChessMove> vB = chess.capturingMoves(false);
    // cout << "Number of black capturing moves: " << vB.size() << " moves" << endl;

    testBoards();

    // Queen q(0,0,true,&chess);
    // q.unnecessaryInt = 2;

    return 0;
}