#include"chess.h"
#include <cctype>

vector<ChessMove> ChessBoard::capturingMoves(bool isWhite)
{
    vector<vector<ChessMove>> list(16);
    list.reserve(16);
    int count = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int y = 0; y < 8; y++)
        {
            ChessPiece* piece = state(y,i).get();
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
    vector<vector<ChessMove>> list;
    list.reserve(16);
    int count = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int y = 0; y < 8; y++)
        {
            ChessPiece* piece = state(y,i).get();
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

shared_ptr<ChessPiece> retPiece(char piece, int x, int y, ChessBoard* cb)
{
    switch(piece)
    {
        case '.':
        return nullptr;
        break;
        case 'K':
        return make_shared<King>(x,y,true,cb);
        break;
        case 'k':
        return make_shared<King>(x,y,false,cb);
        break;
        case 'N':
        return make_shared<Knight>(x,y,true,cb);
        break;
        case 'n':
        return make_shared<Knight>(x,y,false,cb);
        break;
        case 'P':
        return make_shared<Pawn>(x,y,true,cb);
        break;
        case 'p':
        return make_shared<Pawn>(x,y,false,cb);
        break;
        case 'R':
        return make_shared<Rook>(x,y,true,cb);
        break;
        case 'r':
        return make_shared<Rook>(x,y,false,cb);
        break;
        case 'B':
        return make_shared<Bishop>(x,y,true,cb);
        break;
        case 'b':
        return make_shared<Bishop>(x,y,false,cb);
        break;
        case 'Q':
        return dynamic_pointer_cast<Bishop>(make_shared<Queen>(x,y,true,cb));
        break;
        case 'q':
        return dynamic_pointer_cast<Rook>(make_shared<Queen>(x,y,false,cb));
        break;
        default:
        cerr << "oops, that is not supposed to happen. Or it isn't implemented yet\n" << piece << " is not implemented" << endl;
        return nullptr;
        break;
    }
}

bool ChessBoard::isPawnPromotion(ChessMove chessMove)
{
    shared_ptr<ChessPiece> movedPiece = state(chessMove.from_x, chessMove.from_y);
    cout << "isPawnPromotion0 " << movedPiece << endl;
    cout << "(" << chessMove.from_x << "," << chessMove.from_y << ")->(" << chessMove.to_x << "," << chessMove.to_y << ")" << endl;
    cout << "(" << chessMove.piece->x << "," << chessMove.piece->y << ")" << endl;
    cout << chessMove.piece->print(false) << endl;
    cout << "isPawnPromotion1\n" << *this << endl;
    cout << movedPiece.get()->print(false) << endl;
    return (!movedPiece.get()->print(false).compare("P") && chessMove.to_y == 7) || 
        (!movedPiece.get()->print(false).compare("p") && chessMove.to_y == 0);
}

void ChessBoard::move_piece(ChessMove chessMove)
{
    shared_ptr<ChessPiece> movedPiece = state(chessMove.from_x, chessMove.from_y);
    if(state(chessMove.to_x, chessMove.to_y) != nullptr)
    {
        shared_ptr<ChessPiece> removedPiece = state(chessMove.to_x, chessMove.to_y);
        numBlack -= !removedPiece.get()->isWhite;
        numWhite -= removedPiece.get()->isWhite;
        removedPiece = nullptr;
        state(chessMove.to_x, chessMove.to_y) = nullptr;
    }
    movedPiece.get()->changePos(chessMove.to_x, chessMove.to_y);
    
    state(chessMove.to_x, chessMove.to_y) = movedPiece;
    state(chessMove.from_x, chessMove.from_y) = nullptr;
    if(
        (!movedPiece.get()->print(false).compare("P") && chessMove.to_y == 7) ||
        (!movedPiece.get()->print(false).compare("p") && chessMove.to_y == 0)
    )
    {
        char sign;
        cout << "What do you want your pawn to promote to? >";
        cin >> sign;
        switch(sign)
        {
            case 'N':
            case 'n':
            case 'R':
            case 'r':
            case 'B':
            case 'b':
            case 'Q':
            case 'q':
            break;
            default:
            sign = 'q';
            break;
        }
        if(movedPiece.get()->isWhite)
        {
            cout << "AhW" << endl;
            sign = toupper(sign);
        }
        else
        {
            cout << "AhB" << endl;
            sign = tolower(sign);
        }
        state(chessMove.to_x, chessMove.to_y) = nullptr;
        state(chessMove.to_x, chessMove.to_y) = retPiece(sign, chessMove.to_x, chessMove.to_y, this);
    }
}

void ChessBoard::move_piecePromotion(ChessMove chessMove, char sign)
{
    shared_ptr<ChessPiece> movedPiece = state(chessMove.from_x, chessMove.from_y);
    if(state(chessMove.to_x, chessMove.to_y) != nullptr)
    {
        shared_ptr<ChessPiece> removedPiece = state(chessMove.to_x, chessMove.to_y);
        numBlack -= !removedPiece.get()->isWhite;
        numWhite -= removedPiece.get()->isWhite;
        removedPiece = nullptr;
        state(chessMove.to_x, chessMove.to_y) = nullptr;
    }
    movedPiece.get()->x = chessMove.to_x;
    movedPiece.get()->y = chessMove.to_y;
    state(chessMove.to_x, chessMove.to_y) = movedPiece;
    state(chessMove.from_x, chessMove.from_y) = nullptr;
    if(
        (!movedPiece.get()->print(false).compare("P") && chessMove.to_y == 7) ||
        (!movedPiece.get()->print(false).compare("p") && chessMove.to_y == 0)
    )
    {
        switch(sign)
        {
            case 'N':
            case 'n':
            case 'R':
            case 'r':
            case 'B':
            case 'b':
            case 'Q':
            case 'q':
            break;
            default:
            sign = 'q';
            break;
        }
        if(movedPiece.get()->isWhite)
        {
            cout << "AhW" << endl;
            sign = toupper(sign);
        }
        else
        {
            cout << "AhB" << endl;
            sign = tolower(sign);
        }
        state(chessMove.to_x, chessMove.to_y) = nullptr;
        state(chessMove.to_x, chessMove.to_y) = retPiece(sign, chessMove.to_x, chessMove.to_y, this);
    }
}

void ChessBoard::deepCopy(ChessBoard& cb)
{
    cb.numBlack = 0;
    cb.numWhite = 0;
    Matris<shared_ptr<ChessPiece>> board(8);
    for (int i = 0; i < 64; i++)
    {
        int x = i%8, y = i/8;
        if(state(x,y) == nullptr)
        {
            board(x,y) = nullptr;
        }
        else
        {
            shared_ptr<ChessPiece> piece = retPiece(state(x,y).get()->latin1Representation(),x,y,&cb);
            if(piece != nullptr)
            {
                cb.numBlack += !piece.get()->isWhite;
                cb.numWhite += piece.get()->isWhite;
            }
            board(x,y) = piece;
        }
        
        
    }
    cb.state = move(board);
}

ChessBoard& operator>>(istream& is, ChessBoard& cb)
{
    cb.numBlack = 0;
    cb.numWhite = 0;
    Matris<shared_ptr<ChessPiece>> board(8);
    for (int i = 0; i < 64; i++)
    {
        char sign;
        is >> sign;
        int x = i%8, y = i/8;
        shared_ptr<ChessPiece> piece = retPiece(sign,x,y,&cb);
        if(piece != nullptr)
        {
            cb.numBlack += !piece.get()->isWhite;
            cb.numWhite += piece.get()->isWhite;
        }
        board(x,y) = piece;
        
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
            os << " " << ((piece == nullptr) ? "." : piece->print(true));
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