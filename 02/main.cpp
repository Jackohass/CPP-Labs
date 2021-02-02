#include"matris.h"

using namespace std;

template<class T>
void MatrisFactory(Matris<T>& m, initializer_list<T> list)
{
    int index = 0;
    for (size_t i = 0; i < m.rows(); i++)
    {
        for (size_t j = 0; j < m.cols(); j++)
        {
            m(j,i) = list.begin()[index];
            index++;
        }
    }
}

int main()
{
    Matris<int> m0;
    Matris<int> ml = {
        0,1,2,3,
        4,5,6,7,
        8,9,10,11,
        12,13,14,15
    };
    Matris<int> m20(3,2);
    cout << m20 << endl;
    Matris<int> m21(2,3);
    cout << m21 << endl;
    m20(0,0) = 2;
    m20(1,0) = 3;
    m20(2,0) = 4;
    m20(0,1) = 1;
    m20(1,1) = 0;
    m20(2,1) = 0;
    cout << m20 << endl;

    m21(0,0) = 0;
    m21(1,0) = 1000;
    m21(0,1) = 1;
    m21(1,1) = 100;
    m21(0,2) = 0;
    m21(1,2) = 10;
    cout << m21 << endl;

    m20 *= m21;
    cout << m20 << endl;

    Matris<int> mP0(3,3);
    MatrisFactory(mP0,{0,1,2,3,4,5,6,7,8});
    Matris<int> mP1(3,3);
    MatrisFactory(mP1,{0,1,2,3,4,5,6,7,8});
    Matris<int> mP2(3,3);
    MatrisFactory(mP2,{0,1,2,3,4,5,6,7,8});
    Matris<int> mP3(3,3);
    MatrisFactory(mP3,{0,1,2,3,4,5,6,7,8});
    Matris<int> mPT = mP0+mP1+mP2+mP3;
    cout << mPT << mP0 << mP1 << mP2 << mP3 << endl;

    cout << m0.end() << endl;
    cout << ml << endl;
    cout << "(0,0): " << ml(0,0) << endl;
    cout << "(0,1): " << ml(0,1) << endl;
    cout << "(2,0): " << ml(2,0) << endl;
    cout << "(0,3): " << ml(0,3) << endl;
    ml(2,2) = 2;
    cout << "(2,2): " << ml(2,2) << endl;

    Matris<int> mI0(3,3);
    MatrisFactory(mI0,{0,1,2,3,4,5,6,7,8});
    Matris<int> mI1(3,3);
    MatrisFactory(mI1,{0,1,2,3,4,5,6,7,8});
    Matris<int> mI2(3,3);
    MatrisFactory(mI2,{0,1,2,3,4,5,6,7,8});
    Matris<int> mI3(3,3);
    MatrisFactory(mI3,{0,1,2,3,4,5,6,7,8});
    if(mI0 == mI1) cout << "mI0 equals mI1" << endl;
    if(!(mI0 != mI1)) cout << "mI0 still equals mI1" << endl;
    

    mI0.insert_column(1);
    cout << mI0 << endl;
    mI1.insert_column(2);
    cout << mI1 << endl;
    mI2.insert_column(3);
    cout << mI2 << endl;
    mI3.insert_column(4);
    cout << mI3 << endl;
    

    return 0;
}