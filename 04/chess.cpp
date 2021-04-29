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
int ChessBoard::getNumWhite() {return numWhite;}
int ChessBoard::getNumBlack() {return numBlack;}
const ChessPiece* ChessBoard::getPiece(int x, int y) const {return state(x,y).get();}
ChessPiece* ChessBoard::getPiece(int x, int y) {return state(x,y).get();}

int ChessPiece::validMove(int to_x, int to_y)
{
    if(to_x < 0 || to_y < 0 || to_x > 7 || to_y > 7) return 0;
    const ChessPiece* piece = board->getPiece(to_x,to_y);
    if(piece != nullptr)
    {
        return piece->isWhite != isWhite ? 2 : 0;
    }
    return 1;
}
string ChessPiece::utfRepresentation() const {return ".";};     // may be implemented as string
char ChessPiece::latin1Representation() const {return '.';}
void ChessPiece::changePos(int toX, int toY)
{
    x = toX;
    y = toY;
}
ChessPiece::ChessPiece(int xPos, int yPos, bool isWhity, ChessBoard * boardy)
: x{xPos}, y{yPos}, isWhite{isWhity}, board{boardy} {}
bool ChessPiece::capturingMove(int to_x, int to_y)
{
    return validMove(to_x, to_y) == 2;
}
bool ChessPiece::nonCapturingMove(int to_x, int to_y)
{
    return validMove(to_x, to_y) == 1;
}
vector<ChessMove> ChessPiece::capturingMoves() {return vector<ChessMove>();}
vector<ChessMove> ChessPiece::nonCapturingMoves() {return vector<ChessMove>();}
string ChessPiece::print(bool utf) const
{
    return utf ? utfRepresentation() : string(1, latin1Representation());
}

int King::validMove(int to_x, int to_y)
{
    int deltaX = abs(x-to_x);
    int deltaY = abs(y-to_y);
    if(deltaX+deltaY == 1 || deltaX*deltaY == 1)
    {
        return ChessPiece::validMove(to_x, to_y);
    }
    return 0;
}
string King::utfRepresentation() const {return (isWhite ? "♔" : "♚");}
char King::latin1Representation() const {return (isWhite ? 'K' : 'k');}
King::King(int xPos, int yPos, bool isWhity, ChessBoard * boardy) : ChessPiece(xPos, yPos, isWhity, boardy) {}
vector<ChessMove> King::capturingMoves()
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
vector<ChessMove> King::nonCapturingMoves()
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
        if(nonCapturingMove(moves[i][0], moves[i][1])) toReturn.push_back(ChessMove{x,y,moves[i][0],moves[i][1],this});
    }
    return toReturn;
}

int Knight::validMove(int to_x, int to_y)
{
    int deltaX = abs(x-to_x);
    int deltaY = abs(y-to_y);
    if(pow(deltaX,2)+pow(deltaY,2) == 5)
    {
        return ChessPiece::validMove(to_x, to_y);
    }
    return 0;
}
string Knight::utfRepresentation() const {return (isWhite ? "♘" : "♞");}
char Knight::latin1Representation() const {return (isWhite ? 'N' : 'n');}
Knight::Knight(int xPos, int yPos, bool isWhity, ChessBoard * boardy) : ChessPiece(xPos, yPos, isWhity, boardy) {}
vector<ChessMove> Knight::capturingMoves()
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
vector<ChessMove> Knight::nonCapturingMoves()
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

int Pawn::validMove(int to_x, int to_y)
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
string Pawn::utfRepresentation() const {return (isWhite ? "♙" : "♟︎");}
char Pawn::latin1Representation() const {return (isWhite ? 'P' : 'p');}
Pawn::Pawn(int xPos, int yPos, bool isWhity, ChessBoard * boardy) : ChessPiece(xPos, yPos, isWhity, boardy) {}
vector<ChessMove> Pawn::capturingMoves()
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
vector<ChessMove> Pawn::nonCapturingMoves()
{
    vector<ChessMove> toReturn;
    toReturn.reserve(2);
    if(isWhite)
    {
        if(nonCapturingMove(x, y-1))
        {
            toReturn.push_back(ChessMove{x,y,x,y-1,this});
            if(y == 6 && nonCapturingMove(x, y-2)) toReturn.push_back(ChessMove{x,y,x,y-2,this});
        } 
        
    }
    else
    {
        if(nonCapturingMove(x, y+1))
        {
            toReturn.push_back(ChessMove{x,y,x,y+1,this});
            if(y == 1 && nonCapturingMove(x, y+2)) toReturn.push_back(ChessMove{x,y,x,y+2,this});
        }
    }
    return toReturn;
}

int Rook::validMove(int to_x, int to_y)
{
    if((to_x == x) || (to_y == y))
    {
        return ChessPiece::validMove(to_x, to_y);
    }
    return 0;
}
string Rook::utfRepresentation() const {return (isWhite ? "♖" : "♜");}
char Rook::latin1Representation() const {return (isWhite ? 'R' : 'r');}
Rook::Rook(int xPos, int yPos, bool isWhity, ChessBoard * boardy) : ChessPiece(xPos, yPos, isWhity, boardy) {}
vector<ChessMove> Rook::capturingMoves()
{
    const int num = 4;
    vector<ChessMove> toReturn;
    toReturn.reserve(num);
    int toY = y+1;
    while (toY < 8)
    {
        switch(validMove(x, toY))
        {
            case 0:
            toY = 8;
            break;
            case 2:
            toReturn.push_back(ChessMove{x,y,x,toY,this});
            toY = 8;
            break;
        }
        toY++;
    }
    toY = y-1;
    while (toY > -1)
    {
        switch(validMove(x, toY))
        {
            case 0:
            toY = -1;
            break;
            case 2:
            toReturn.push_back(ChessMove{x,y,x,toY,this});
            toY = -1;
            break;
        }
        toY--;
    }
    int toX = x+1;
    while (toX < 8)
    {
        switch(validMove(toX, y))
        {
            case 0:
            toX = 8;
            break;
            case 2:
            toReturn.push_back(ChessMove{x,y,toX,y,this});
            toX = 8;
            break;
        }
        toX++;
    }
    toX = x-1;
    while (toX > -1)
    {
        switch(validMove(toX, y))
        {
            case 0:
            toX = -1;
            break;
            case 2:
            toReturn.push_back(ChessMove{x,y,toX,y,this});
            toX = -1;
            break;
        }
        toX--;
    }
    return toReturn;
}
vector<ChessMove> Rook::nonCapturingMoves()
{
    const int num = 14;
    vector<ChessMove> toReturn;
    toReturn.reserve(num);
    int toY = y+1;
    while (toY < 8)
    {
        switch(validMove(x, toY))
        {
            case 0:
            toY = 8;
            break;
            case 2:
            toY = 8;
            break;
            case 1:
            toReturn.push_back(ChessMove{x,y,x,toY,this});
            break;
        }
        toY++;
    }
    toY = y-1;
    while (toY > -1)
    {
        switch(validMove(x, toY))
        {
            case 0:
            toY = -1;
            break;
            case 2:
            toY = -1;
            break;
            case 1:
            toReturn.push_back(ChessMove{x,y,x,toY,this});
            break;
        }
        toY--;
    }
    int toX = x+1;
    while (toX < 8)
    {
        switch(validMove(toX, y))
        {
            case 0:
            toX = 8;
            break;
            case 2:
            toX = 8;
            break;
            case 1:
            toReturn.push_back(ChessMove{x,y,toX,y,this});
            break;
        }
        toX++;
    }
    toX = x-1;
    while (toX > -1)
    {
        switch(validMove(toX, y))
        {
            case 0:
            toX = -1;
            break;
            case 2:
            toX = -1;
            break;
            case 1:
            toReturn.push_back(ChessMove{x,y,toX,y,this});
            break;
        }
        toX--;
    }
    return toReturn;
}

int Bishop::validMove(int to_x, int to_y)
{
    int deltaX = abs(x-to_x);
    int deltaY = abs(y-to_y);
    if(deltaX == deltaY)
    {
        return ChessPiece::validMove(to_x, to_y);
    }
    return 0;
}
string Bishop::utfRepresentation() const {return (isWhite ? "♗" : "♝");}
char Bishop::latin1Representation() const {return (isWhite ? 'B' : 'b');}
Bishop::Bishop(int xPos, int yPos, bool isWhity, ChessBoard * boardy) : ChessPiece(xPos, yPos, isWhity, boardy) {}
vector<ChessMove> Bishop::capturingMoves()
{
    const int num = 4;
    vector<ChessMove> toReturn;
    toReturn.reserve(num);
    int toY = y+1;
    int toX = x+1;
    while (toY < 8 && toX < 8)
    {
        switch(validMove(toX, toY))
        {
            case 0:
            toY = 8;
            break;
            case 2:
            toReturn.push_back(ChessMove{x,y,toX,toY,this});
            toY = 8;
            break;
        }
        toX++;
        toY++;
    }
    toY = y+1;
    toX = x-1;
    while (toY < 8 && toX > -1)
    {
        switch(validMove(toX, toY))
        {
            case 0:
            toY = 8;
            break;
            case 2:
            toReturn.push_back(ChessMove{x,y,toX,toY,this});
            toY = 8;
            break;
        }
        toX--;
        toY++;
    }
    toY = y-1;
    toX = x+1;
    while (toY > -1 && toX < 8)
    {
        switch(validMove(toX, toY))
        {
            case 0:
            toY = -1;
            break;
            case 2:
            toReturn.push_back(ChessMove{x,y,toX,toY,this});
            toY = -1;
            break;
        }
        toX++;
        toY--;
    }
    toY = y-1;
    toX = x-1;
    while (toY > -1 && toX > -1)
    {
        switch(validMove(toX, toY))
        {
            case 0:
            toY = -1;
            break;
            case 2:
            toReturn.push_back(ChessMove{x,y,toX,toY,this});
            toY = -1;
            break;
        }
        toX--;
        toY--;
    }
    return toReturn;
}
vector<ChessMove> Bishop::nonCapturingMoves()
{
    const int num = 14;
    vector<ChessMove> toReturn;
    toReturn.reserve(num);
    int toY = y+1;
    int toX = x+1;
    while (toY < 8 && toX < 8)
    {
        switch(validMove(toX, toY))
        {
            case 0:
            toY = 8;
            break;
            case 2:
            toY = 8;
            break;
            case 1:
            toReturn.push_back(ChessMove{x,y,toX,toY,this});
            break;
        }
        toX++;
        toY++;
    }
    toY = y+1;
    toX = x-1;
    while (toY < 8 && toX > -1)
    {
        switch(validMove(toX, toY))
        {
            case 0:
            toY = 8;
            break;
            case 2:
            toY = 8;
            break;
            case 1:
            toReturn.push_back(ChessMove{x,y,toX,toY,this});
            break;
        }
        toX--;
        toY++;
    }
    toY = y-1;
    toX = x+1;
    while (toY > -1 && toX < 8)
    {
        switch(validMove(toX, toY))
        {
            case 0:
            toY = -1;
            break;
            case 2:
            toY = -1;
            break;
            case 1:
            toReturn.push_back(ChessMove{x,y,toX,toY,this});
            break;
        }
        toX++;
        toY--;
    }
    toY = y-1;
    toX = x-1;
    while (toY > -1 && toX > -1)
    {
        switch(validMove(toX, toY))
        {
            case 0:
            toY = -1;
            break;
            case 2:
            toY = -1;
            break;
            case 1:
            toReturn.push_back(ChessMove{x,y,toX,toY,this});
            break;
        }
        toX--;
        toY--;
    }
    return toReturn;
}

int Queen::validMove(int to_x, int to_y)
{
    return Rook::validMove(to_x, to_y) + Bishop::validMove(to_x, to_y);
}
string Queen::utfRepresentation() const {return (Rook::isWhite ? "♕" : "♛");}
char Queen::latin1Representation() const {return (Rook::isWhite ? 'Q' : 'q');}
Queen::Queen(int xPos, int yPos, bool isWhity, ChessBoard * boardy) : Bishop(xPos, yPos, isWhity, boardy), Rook(xPos, yPos, isWhity, boardy) {}
void Queen::changePos(int toX, int toY)
{
    Bishop::x = toX;
    Bishop::y = toY;
    Rook::x = toX;
    Rook::y = toY;
}
vector<ChessMove> Queen::capturingMoves()
{
    const int num = 8;
    vector<ChessMove> partR = Rook::capturingMoves();
    cout << "cmq: " << partR << endl;
    vector<ChessMove> partB = Bishop::capturingMoves();
    cout << "cmq: " << partB << endl;
    vector<ChessMove> toReturn(partR.size() + partB.size());
    copy(partR.begin(), partR.end(), toReturn.begin());
    copy(partB.begin(), partB.end(), toReturn.begin()+partR.size());
    return toReturn;
}
vector<ChessMove> Queen::nonCapturingMoves()
{
    const int num = 28;
    vector<ChessMove> partR = Rook::nonCapturingMoves();
    cout << "ncmq: " << partR << endl;
    vector<ChessMove> partB = Bishop::nonCapturingMoves();
    cout << "ncmq: " << partB << endl;
    vector<ChessMove> toReturn(partR.size() + partB.size());
    copy(partR.begin(), partR.end(), toReturn.begin());
    copy(partB.begin(), partB.end(), toReturn.begin()+partR.size());
    
    return toReturn;
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
