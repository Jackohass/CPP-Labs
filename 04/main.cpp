#include"chess.h"
#include<sstream>
#include<fstream>
#include<stdlib.h>
#include<time.h>

void doAI1Move(ChessBoard& cb, ChessMove move)
{
    cout << "doAI1Move0" << endl;
    if(cb.isPawnPromotion(move))
    {
        cout << "doAI1Move promotion 0" << endl;
        char signs[4] = {'n','r','b','q'};
        cb.move_piecePromotion(move,signs[rand()%4]);
    }
    else
    {
        cout << "doAI1Move no0" << endl;
        cb.move_piece(move);
    }
}

void doAI2Move(ChessBoard& cb, ChessMove move)
{
    cout << "doAI2Move0" << endl;
    if(cb.isPawnPromotion(move))
    {
        cout << "doAI2Move pawn0" << endl;
        char signs[4] = {'n','r','b','q'};
        bool foundMove = false;
        for (int j = 0; j < 4 && !foundMove; j++)
        {
            ChessBoard newCb;
            cb.deepCopy(newCb);
            newCb.move_piecePromotion(move, signs[j]);
            vector<ChessMove> newCbV = move.piece->capturingMoves();
            if(newCbV.size() == 0)
            {
                cb.move_piecePromotion(move,signs[j]);
                foundMove = true;
            }
        }
        if(!foundMove)
        {
            cb.move_piecePromotion(move,signs[rand()%4]);
        }
    }
    else
    {
        cout << "doAI2Move no0" << endl;
        cb.move_piece(move);
    }
    cout << "doAI2Move done" << endl;
}

void AI1Play(ChessBoard& cb, bool isWhite)
{
    vector<ChessMove> v = cb.capturingMoves(isWhite);
    if(v.size() != 0)
    {
        cout << "AI1Play capture0" << endl;
        ChessMove move = v[rand()%v.size()];
        doAI1Move(cb, move);
        cout << "AI1Play capture1" << endl;
    }
    else
    {
        cout << "AI1Play noncapture0" << endl;
        v = cb.nonCapturingMoves(isWhite);
        if(v.size() != 0)
        {
            ChessMove move = v[rand()%v.size()];
            doAI1Move(cb, move);
        }
        cout << "AI1Play noncapture1" << endl;
    }
}

void AI2Play(ChessBoard& cb, bool isWhite)
{
    vector<ChessMove> v = cb.capturingMoves(isWhite);
    if(v.size() != 0)
    {
        cout << "AI2Play capture0" << endl;
        bool foundMove = false;
        for (int i = 0; i < v.size() && !foundMove; i++)
        {
            ChessBoard newCb;
            cb.deepCopy(newCb);
            cout << "AI2Play capture1" << endl;
            doAI2Move(newCb, v[i]);
            vector<ChessMove> newCbV = newCb.capturingMoves(!isWhite);
            for (int j = 0; j < newCbV.size(); j++)
            {
                if(newCbV[j].to_x == v[i].to_x && newCbV[j].to_y == v[i].to_y)
                {
                    cout << "AI2Play capture2" << endl;
                    doAI2Move(cb, v[i]);
                    foundMove = true;
                    break;
                }
            }
            
        }
        if(!foundMove)
        {
            cout << "AI2Play capture3" << endl;
            doAI2Move(cb, v[rand()%v.size()]);
        }
        cout << "AI2Play capture done" << endl;
    }
    else
    {
        cout << "AI2Play noncapture0" << endl;
        v = cb.nonCapturingMoves(isWhite);
        bool foundMove = false;
        for (int i = 0; i < v.size() && !foundMove; i++)
        {
            cout << "AI2Play noncapture1" << endl;
            ChessBoard newCb;
            cb.deepCopy(newCb);
            doAI2Move(newCb, v[i]);
            cout << "AI2Play noncapture2" << endl;
            vector<ChessMove> newCbV = newCb.capturingMoves(!isWhite);
            cout << "AI2Play noncapture3" << endl;
            for (int j = 0; j < newCbV.size(); j++)
            {
                cout << "AI2Play noncapture4" << endl;
                if(newCbV[j].to_x == v[i].to_x && newCbV[j].to_y == v[i].to_y)
                {
                    doAI2Move(cb, v[i]);
                    foundMove = true;
                    break;
                }
            }
            
        }
        if(!foundMove)
        {
            if(v.size() != 0)
            {
                ChessMove move = v[rand()%v.size()];
                doAI2Move(cb, move);
            }
            cout << "AI2Play noncapture WOOPS" << endl;
        }
        cout << "AI2Play noncapture done" << endl;
    }
}

/**
 * argv[0] = name
 * argv[1] = which colour that goes first
 * argv[2] = which AI goes first
 */
int main(int argc, char *argv[])
{
    if(argc < 3) return 0;
    bool whiteFirst;
    string colour(argv[1]);
    if(colour.compare("black")) whiteFirst = false;
    else if(colour.compare("white")) whiteFirst = true;
    else return 0;
    srand (time(NULL));
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
    s << "rnbqkbnr" << endl;
    s << "pppppppp" << endl;
    s << "........" << endl;
    s << "........" << endl;
    s << "........" << endl;
    s << "........" << endl;
    s << "PPPPPPPP" << endl;
    s << "RNBQKBNR";
    s >> chess;
    cout << chess << endl;

    bool tick = argv[2][0] == '1' ? true : false;
    while(chess.getNumBlack() > 0 && chess.getNumWhite() > 0)
    {
        if(tick)
        {
            cout << "true" << endl;
            AI1Play(chess, !whiteFirst);
        }
        else
        {
            cout << "false" << endl;
            AI2Play(chess, whiteFirst);
        }
        cout << chess << endl;
        tick = !tick;
    }
    

    return 0;
}