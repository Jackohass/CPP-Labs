#include"chess.h"
#include<sstream>
#include <fstream>

using namespace std;

void testBoards()
{
    ChessBoard chess;
    int numWCM, numBCM, numWNCM, numBNCM;
    ifstream myfile("data.txt");
    if (myfile.is_open())
    {
        int numPassed = 0;
        int numTests = 0;
        while (!myfile.eof())
        {
            bool passed = true;
            myfile >> chess;
            myfile >> numWCM;
            myfile >> numBCM;
            myfile >> numWNCM;
            myfile >> numBNCM;
            cout << chess;
            vector<ChessMove> vW = chess.capturingMoves(true);
            vector<ChessMove> vB = chess.capturingMoves(false);
            vector<ChessMove> vnW = chess.nonCapturingMoves(true);
            vector<ChessMove> vnB = chess.nonCapturingMoves(false);
            if (vW.size() != numWCM) {
                cout << "capturingMoves white FAILED, expected " << numWCM << " moves but got " << vW.size() << " moves" << endl;
                passed = false;
            } else {
                cout << "capturingMoves white PASSED, expected " << numWCM << " moves and got " << vW.size() << " moves" << endl;
            }
            if (vB.size() != numBCM) {
                cout << "capturingMoves black FAILED, expected " << numBCM << " moves but got " << vB.size() << " moves" << endl;
                passed = false;
            } else {
                cout << "capturingMoves black PASSED, expected " << numBCM << " moves and got " << vB.size() << " moves" << endl;
            }

            if (vnW.size() != numWNCM) {
                cout << "nonCapturingMoves white FAILED, expected " << numWNCM << " moves but got " << vnW.size() << " moves" << endl;
                passed = false;
            } else {
                cout << "nonCapturingMoves white PASSED, expected " << numWNCM << " moves and got " << vnW.size() << " moves" << endl;
            }
            if (vnB.size() != numBNCM) {
                cout << "nonCapturingMoves black FAILED, expected " << numBNCM << " moves but got " << vnB.size() << " moves" << endl;
                passed = false;
            } else {
                cout << "nonCapturingMoves black PASSED, expected " << numBNCM << " moves and got " << vnB.size() << " moves" << endl;
            }
            cout << endl;
            numTests++;
            if(passed) numPassed++;
        }
        myfile.close();

        cout << numPassed << "/" << numTests << " passed" << endl;
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
    //s << "RNBQKBNR";
    // s << "........" << endl;
    // s << "........" << endl;
    // s << "........" << endl;
    // s << ".r......" << endl;
    // s << ".p......" << endl;
    // s << "...P...n" << endl;
    // s << "......P." << endl;
    // s << ".N...B..";
    // s << "rnbqkbnr" << endl;
    // s << "pppppppp" << endl;
    // s << "........" << endl;
    // s << "........" << endl;
    // s << "....P..." << endl;
    // s << "........" << endl;
    // s << "PPPP.PPP" << endl;
    // s << "RNBQKBNR";

    // cout << s.str() << endl;
    // s >> chess;
    // cout << chess << endl;

    // chess.move_piece(ChessMove{7,1,7,0,chess.getPiece(7,1)});
    // chess.move_piece(ChessMove{7,6,7,7,chess.getPiece(7,6)});
    // cout << chess << endl;
    // cout << chess.getPiece(7,7)->print(false).compare("p") << endl;

    // vector<ChessMove> v = chess.capturingMoves(true);
    // cout << "capturingMoves: got " << v.size() << " moves" << endl;
    // cout << "capturingMoves: " << v << endl;
    // vector<ChessMove> v0 = chess.nonCapturingMoves(true);
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