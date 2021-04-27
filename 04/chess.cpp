#include"chess.h"

vector<ChessMove> ChessBoard::capturingMoves(bool isWhite)
{
    vector<vector<ChessMove>> list(16);
    int count = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int y = 0; y < 8; y++)
        {
            ChessPiece* piece = state(i,y).get();
            if(piece != nullptr && piece->isWhite == isWhite)
            {
                vector<ChessMove> tmp = piece->capturingMoves();
                list.push_back(tmp);
                count += tmp.size();
            }
        }
    }
    vector<ChessMove> toRet(count);
    int prevSize = 0;
    for (int i = 0; i < list.size(); i++)
    {
        copy(list[i].begin(), list[i].end(), toRet.begin()+prevSize);
        prevSize += list[i].size();
    }
    return toRet;
}

vector<ChessMove> ChessBoard::nonCapturingMoves(bool isWhite)
{
    vector<vector<ChessMove>> list(16);
    int count = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int y = 0; y < 8; y++)
        {
            ChessPiece* piece = state(i,y).get();
            if(piece != nullptr && piece->isWhite == isWhite)
            {
                vector<ChessMove> tmp = piece->nonCapturingMoves();
                list.push_back(tmp);
                count += tmp.size();
            }
        }
    }
    vector<ChessMove> toRet(count);
    int prevSize = 0;
    for (int i = 0; i < list.size(); i++)
    {
        copy(list[i].begin(), list[i].end(), toRet.begin()+prevSize);
        prevSize += list[i].size();
    }
    return toRet;
}

ChessBoard& operator>>(istream& is, ChessBoard& cb)
{
    Matris<shared_ptr<ChessPiece>> board(8);
    for (int i = 0; i < 64; i++)
    {
        char sign;
        is >> sign;
        int x = i%8, y = i/8;
        switch(sign)
        {
            case '.':
            board(x,y) = nullptr;
            break;
            case 'K':
            board(x,y) = make_shared<King>(x,y,true,&cb);
            break;
            case 'k':
            board(x,y) = make_shared<King>(x,y,false,&cb);
            break;
            case 'N':
            board(x,y) = make_shared<Knight>(x,y,true,&cb);
            break;
            case 'n':
            board(x,y) = make_shared<Knight>(x,y,false,&cb);
            break;
            case 'P':
            board(x,y) = make_shared<Pawn>(x,y,true,&cb);
            break;
            case 'p':
            board(x,y) = make_shared<Pawn>(x,y,false,&cb);
            break;
            default:
            cerr << "oops, that is not supposed to happen. Or it isn't implemented yet\n";
            break;
        }
    }
    
    cb.state = move(board);
    return cb;
}

ostream& operator<<(ostream& os, ChessBoard& cb)
{
    for (int x = 0; x < 8; x++)
    {
        for (int y = 0; y < 8; y++)
        {
            const ChessPiece* piece = cb.getPiece(y,x);
            os << ((piece == nullptr) ? "." : piece->print(true));
        }
        os << "\n";
    }
    return os;
}

ostream& operator<<(ostream& os, const ChessMove& cm)
{
    os << cm.piece->print(true) << ": (" << cm.from_x << "," << cm.from_y << ")->(" << cm.to_x << "," << cm.to_y << ")";
    return os;
}

ostream& operator<<(ostream& os, const vector<ChessMove>& v)
{
    os << "[\n";
    for (int i = 0; i < v.size(); ++i) {
        os << "\t" << v[i] << "\n";
    }
    os << "]";
    return os;
}