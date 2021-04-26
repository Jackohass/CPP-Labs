#include"chess.h"
#include<sstream>

using namespace std;

int main()
{
    ChessBoard chess;
    stringstream s;
    s << ".....K.." << endl;
    s << ".....k.." << endl;
    s << "......K." << endl;
    s << "k......." << endl;
    s << ".......K" << endl;
    s << ".k......" << endl;
    s << "....K..." << endl;
    s << "..k.....";
    cout << s.str() << endl;
    s >> chess;

    vector<ChessMove> v = chess.capturingMoves(true);
    if (v.size() != 0) {
        cout << "capturingMoves FAILED, expected 0 moves but got " << v.size() << " moves" << endl;
    } else {
        cout << "capturingMoves PASSED, expected 0 moves and got " << v.size() << " moves" << endl;
    }

    vector<ChessMove> v0 = chess.nonCapturingMoves(true);
    cout << "nonCapturingMoves: expected ? moves but got " << v0.size() << " moves" << endl;

    cout << chess << endl;
    return 0;
}