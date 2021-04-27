#include"chess.h"
#include<sstream>

using namespace std;

int main()
{
    ChessBoard chess;
    stringstream s;
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
    s << "....P..." << endl;
    s << "....p..." << endl;
    s << ".p.P...." << endl;
    s << "..P....." << endl;
    s << "....p.p." << endl;
    s << "...p.P.." << endl;
    s << "..P....." << endl;
    s << ".....p..";
    cout << s.str() << endl;
    s >> chess;

    vector<ChessMove> v = chess.capturingMoves(true);
    cout << "capturingMoves: got " << v.size() << " moves" << endl;
    cout << "capturingMoves: " << v << endl;

    vector<ChessMove> v0 = chess.nonCapturingMoves(true);
    cout << "nonCapturingMoves: got " << v0.size() << " moves" << endl;
    cout << "nonCapturingMoves: " << v0 << endl;

    cout << chess << endl;
    return 0;
}