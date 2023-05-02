#include<cxxtest/TestSuite.h>
#include"matris.h"
#include<fstream>

class MyTestSuite : public CxxTest::TestSuite 
{
public:
  void testMatrisConstructor0Args( void )
  {
    Matris<int> data;
    
    TS_ASSERT(data.rows() == 0);
    TS_ASSERT(data.cols() == 0);
  }
  void testMatrisConstructor1Arg0( void )
  {
    Matris<int> data(0);
    
    TS_ASSERT(data.rows() == 0);
    TS_ASSERT(data.cols() == 0);
  }
  void testMatrisConstructor2Args00( void )
  {
    Matris<int> data(0,0);
    
    TS_ASSERT(data.rows() == 0);
    TS_ASSERT(data.cols() == 0);
  }
  void testMatrisConstructorListEmpty( void )
  {
    Matris<int> data = {};
    
    TS_ASSERT(data.rows() == 0);
    TS_ASSERT(data.cols() == 0);
  }
  void testMatrisConstructorListNonEvenSquare( void )
  {
    TS_ASSERT_THROWS(middlemanConstructorThrow(), out_of_range);
  }
  void testMatrisConstructorListEvenSquare( void )
  {
    TS_ASSERT_THROWS_NOTHING(middlemanConstructorNoThrow());
  }
  void testMatrisConstructorCopy( void )
  {
    Matris<int> m0 = {0,1,2,3};
    Matris<int> m1 = m0;
    TS_ASSERT(m0 == m1);
  }
  void testMatrisConstructorMove( void )
  {
    Matris<int> m0 = {0,1,2,3};
    TS_ASSERT(m0.rows() == 2);
    TS_ASSERT(m0.cols() == 2);
    Matris<int> m1 = move(m0);
    TS_ASSERT(m1.rows() == 2);
    TS_ASSERT(m1.cols() == 2);
    TS_ASSERT(m0.rows() == 0);
    TS_ASSERT(m0.cols() == 0);
    TS_ASSERT(m0 != m1);
  }

  void testMatrisOperCopy( void )
  {
    Matris<int> m0 = {0,1,2,3};
    Matris<int> m1(3,3);
    m1 = m0;
    TS_ASSERT(m0 == m1);
  }
  void testMatrisOperMove( void )
  {
    Matris<int> m0 = {0,1,2,3};
    Matris<int> m1(3,3);
    TS_ASSERT(m0.rows() == 2);
    TS_ASSERT(m0.cols() == 2);
    m1 = move(m0);
    TS_ASSERT(m1.rows() == 2);
    TS_ASSERT(m1.cols() == 2);
    TS_ASSERT(m0.rows() == 0);
    TS_ASSERT(m0.cols() == 0);
    TS_ASSERT(m0 != m1);
  }
  void testMatrisOperPlusScalarAssign( void )
  {
    Matris<int> m0 = {0,1,2,3};
    Matris<int> m1 = {1,2,3,4};
    m0 += 1;
    TS_ASSERT(m0 == m1);
  }
  void testMatrisOperPlusMatrisAssign( void )
  {
    Matris<int> m0 = {0,1,2,3};
    Matris<int> m00 = {0,1,2,3};
    Matris<int> m1 = {0,2,4,6};
    m0 += m00;
    TS_ASSERT(m0 == m1);
  }
  void testMatrisOperMinusScalarAssign( void )
  {
    Matris<int> m0 = {0,1,2,3};
    Matris<int> m1 = {1,2,3,4};
    m1 -= 1;
    TS_ASSERT(m0 == m1);
  }
  void testMatrisOperMinusMatrisAssign( void )
  {
    Matris<int> m0 = {0,1,2,3};
    Matris<int> m00 = {0,1,2,3};
    Matris<int> m1 = {0,0,0,0};
    m0 -= m00;
    TS_ASSERT(m0 == m1);
  }
  void testMatrisOperMultScalarAssign( void )
  {
    Matris<int> m0 = {0,1,2,3};
    Matris<int> m1 = {0,2,4,6};
    m0 *= 2;
    TS_ASSERT(m0 == m1);
  }
  void testMatrisOperMultMatrisAssign( void )
  {
    Matris<int> m0(3,2);
    MatrisFactory(m0,{2,3,4,1,0,0});
    Matris<int> m1(2,3);
    MatrisFactory(m1,{0,1000,1,100,0,10});
    Matris<int> mres(2,2);
    MatrisFactory(mres,{3,2340,0,1000});
    m0 *= m1;
    TS_ASSERT(mres == m0);
  }

  void testMatrisOperPlusScalar( void )
  {
    Matris<int> m0 = {0,1,2,3};
    Matris<int> m1 = {1,2,3,4};
    TS_ASSERT((m0 + 1) == m1);
  }
  void testMatrisOperPlusMatrisChain( void )
  {
    Matris<int> mP0(3,3);
    MatrisFactory(mP0,{0,1,2,3,4,5,6,7,8});
    Matris<int> mP1(3,3);
    MatrisFactory(mP1,{0,1,2,3,4,5,6,7,8});
    Matris<int> mP2(3,3);
    MatrisFactory(mP2,{0,1,2,3,4,5,6,7,8});
    Matris<int> mP3(3,3);
    MatrisFactory(mP3,{0,1,2,3,4,5,6,7,8});
    Matris<int> mPT = mP0+mP1+mP2+mP3;
    Matris<int> mTrue(3,3);
    MatrisFactory(mTrue,{0,4,8,12,16,20,24,28,32});
    TS_ASSERT(mTrue == mPT);
  }
  void testMatrisOperPlusMatris( void )
  {
    Matris<int> m0 = {0,1,2,3};
    Matris<int> m00 = {0,1,2,3};
    Matris<int> m1 = {0,2,4,6};
    TS_ASSERT((m0+m00) == m1);
  }

  void testMatrisOperMinusScalar( void )
  {
    Matris<int> m0 = {0,1,2,3};
    Matris<int> m1 = {1,2,3,4};
    TS_ASSERT((m1-1) == m0);
  }
  void testMatrisOperMinusMatris( void )
  {
    Matris<int> m0 = {0,1,2,3};
    Matris<int> m00 = {0,1,2,3};
    Matris<int> m1 = {0,0,0,0};
    TS_ASSERT((m0-m00) == m1);
  }
  void testMatrisOperMultScalar( void )
  {
    Matris<int> m0 = {0,1,2,3};
    Matris<int> m1 = {0,2,4,6};
    TS_ASSERT((m0*2) == m1);
  }
  void testMatrisOperMultMatris( void )
  {
    Matris<int> m0(3,2);
    MatrisFactory(m0,{2,3,4,1,0,0});
    Matris<int> m1(2,3);
    MatrisFactory(m1,{0,1000,1,100,0,10});
    Matris<int> mres(2,2);
    MatrisFactory(mres,{3,2340,0,1000});
    TS_ASSERT(mres == (m0*m1));
  }

  void testMatrisOperFunc( void )
  {
    Matris<int> m0 = {1,2,3,4};
    m0(1,1) = 2;
    TS_ASSERT(2 == m0(1,1));
  }
  void testMatrisOperFuncConst( void )
  {
    initializer_list<int> list = {1,2,3,4};
    const Matris<int>& m = list;
    int index = 0;
    for (size_t i = 0; i < m.rows(); i++)
    {
      for (size_t j = 0; j < m.cols(); j++)
      {
        TS_ASSERT(list.begin()[index] == m(j,i));
        index++;
      }
    }
  }

  void testMatrisOperEquals( void )
  {
    Matris<int> m0 = {0,1,2,3};
    Matris<int> m1 = {0,1,2,3};
    TS_ASSERT(m0 == m1);
  }
  void testMatrisOperNotEquals( void )
  {
    Matris<int> m0 = {0,1,2,3};
    Matris<int> m1 = {0,1,2,4};
    TS_ASSERT(m0 != m1);
  }

  void testMatrisRows( void )
  {
    Matris<int> data = {0,1,2,3};
    
    TS_ASSERT(data.rows() == 2);
  }
  void testMatrisCols( void )
  {
    Matris<int> data = {0,1,2,3};
    
    TS_ASSERT(data.cols() == 2);
  }

  void testMatrisReset( void )
  {
    Matris<int> data = {0,1,2,3};
    Matris<int> zeroes(2,2);
    data.reset();
    
    TS_ASSERT(data == zeroes);
  }
  void testMatrisIdentity( void )
  {
    Matris<bool> data = {
      1,0,0,0,
      0,1,0,0,
      0,0,1,0,
      0,0,0,1
    };
    TS_ASSERT(data.identity(4) == data);
  }

  void testMatrisInsert_row( void )
  {
    Matris<int> mI0(3,3);
    MatrisFactory(mI0,{0,1,2,3,4,5,6,7,8});
    Matris<int> mI1(3,3);
    MatrisFactory(mI1,{0,1,2,3,4,5,6,7,8});
    Matris<int> mI2(3,3);
    MatrisFactory(mI2,{0,1,2,3,4,5,6,7,8});
    Matris<int> mI3(3,3);
    MatrisFactory(mI3,{0,1,2,3,4,5,6,7,8});

    Matris<int> mI0T(3,4);
    MatrisFactory(mI0T,{0,0,0,0,1,2,3,4,5,6,7,8});
    Matris<int> mI1T(3,4);
    MatrisFactory(mI1T,{0,1,2,0,0,0,3,4,5,6,7,8});
    Matris<int> mI2T(3,4);
    MatrisFactory(mI2T,{0,1,2,3,4,5,0,0,0,6,7,8});
    Matris<int> mI3T(3,4);
    MatrisFactory(mI3T,{0,1,2,3,4,5,6,7,8,0,0,0});

    mI0.insert_row(1);
    TS_ASSERT(mI0 == mI0T);
    mI1.insert_row(2);
    TS_ASSERT(mI1 == mI1T);
    mI2.insert_row(3);
    TS_ASSERT(mI2 == mI2T);
    mI3.insert_row(4);
    TS_ASSERT(mI3 == mI3T);
  }
  void testMatrisAppend_row( void )
  {
    Matris<int> mI0(3,3);
    MatrisFactory(mI0,{0,1,2,3,4,5,6,7,8});
    Matris<int> mI1(3,3);
    MatrisFactory(mI1,{0,1,2,3,4,5,6,7,8});
    Matris<int> mI2(3,3);
    MatrisFactory(mI2,{0,1,2,3,4,5,6,7,8});
    Matris<int> mI3(3,3);
    MatrisFactory(mI3,{0,1,2,3,4,5,6,7,8});

    Matris<int> mI0T(3,4);
    MatrisFactory(mI0T,{0,0,0,0,1,2,3,4,5,6,7,8});
    Matris<int> mI1T(3,4);
    MatrisFactory(mI1T,{0,1,2,0,0,0,3,4,5,6,7,8});
    Matris<int> mI2T(3,4);
    MatrisFactory(mI2T,{0,1,2,3,4,5,0,0,0,6,7,8});
    Matris<int> mI3T(3,4);
    MatrisFactory(mI3T,{0,1,2,3,4,5,6,7,8,0,0,0});

    mI0.append_row(-1);
    TS_ASSERT(mI0 == mI0T);
    mI1.append_row(0);
    TS_ASSERT(mI1 == mI1T);
    mI2.append_row(1);
    TS_ASSERT(mI2 == mI2T);
    mI3.append_row(2);
    TS_ASSERT(mI3 == mI3T);
  }
  void testMatrisRemove_row( void )
  {
    Matris<int> mI0(3,3);
    MatrisFactory(mI0,{0,1,2,3,4,5,6,7,8});
    Matris<int> mI1(3,3);
    MatrisFactory(mI1,{0,1,2,3,4,5,6,7,8});
    Matris<int> mI2(3,3);
    MatrisFactory(mI2,{0,1,2,3,4,5,6,7,8});

    Matris<int> mI0T(3,2);
    MatrisFactory(mI0T,{3,4,5,6,7,8});
    Matris<int> mI1T(3,2);
    MatrisFactory(mI1T,{0,1,2,6,7,8});
    Matris<int> mI2T(3,2);
    MatrisFactory(mI2T,{0,1,2,3,4,5});

    mI0.remove_row(0);
    TS_ASSERT(mI0 == mI0T);
    mI1.remove_row(1);
    TS_ASSERT(mI1 == mI1T);
    mI2.remove_row(2);
    TS_ASSERT(mI2 == mI2T);
  }
  void testMatrisInsert_column( void )
  {
    Matris<int> mI0(3,3);
    MatrisFactory(mI0,{0,1,2,3,4,5,6,7,8});
    Matris<int> mI1(3,3);
    MatrisFactory(mI1,{0,1,2,3,4,5,6,7,8});
    Matris<int> mI2(3,3);
    MatrisFactory(mI2,{0,1,2,3,4,5,6,7,8});
    Matris<int> mI3(3,3);
    MatrisFactory(mI3,{0,1,2,3,4,5,6,7,8});

    Matris<int> mI0T(4,3);
    MatrisFactory(mI0T,{0,0,1,2,0,3,4,5,0,6,7,8});
    Matris<int> mI1T(4,3);
    MatrisFactory(mI1T,{0,0,1,2,3,0,4,5,6,0,7,8});
    Matris<int> mI2T(4,3);
    MatrisFactory(mI2T,{0,1,0,2,3,4,0,5,6,7,0,8});
    Matris<int> mI3T(4,3);
    MatrisFactory(mI3T,{0,1,2,0,3,4,5,0,6,7,8,0});

    mI0.insert_column(1);
    TS_ASSERT(mI0 == mI0T);
    mI1.insert_column(2);
    TS_ASSERT(mI1 == mI1T);
    mI2.insert_column(3);
    TS_ASSERT(mI2 == mI2T);
    mI3.insert_column(4);
    TS_ASSERT(mI3 == mI3T);
  }
  void testMatrisAppend_column( void )
  {
    Matris<int> mI0(3,3);
    MatrisFactory(mI0,{0,1,2,3,4,5,6,7,8});
    Matris<int> mI1(3,3);
    MatrisFactory(mI1,{0,1,2,3,4,5,6,7,8});
    Matris<int> mI2(3,3);
    MatrisFactory(mI2,{0,1,2,3,4,5,6,7,8});
    Matris<int> mI3(3,3);
    MatrisFactory(mI3,{0,1,2,3,4,5,6,7,8});

    Matris<int> mI0T(4,3);
    MatrisFactory(mI0T,{0,0,1,2,0,3,4,5,0,6,7,8});
    Matris<int> mI1T(4,3);
    MatrisFactory(mI1T,{0,0,1,2,3,0,4,5,6,0,7,8});
    Matris<int> mI2T(4,3);
    MatrisFactory(mI2T,{0,1,0,2,3,4,0,5,6,7,0,8});
    Matris<int> mI3T(4,3);
    MatrisFactory(mI3T,{0,1,2,0,3,4,5,0,6,7,8,0});

    mI0.append_column(-1);
    TS_ASSERT(mI0 == mI0T);
    mI1.append_column(0);
    TS_ASSERT(mI1 == mI1T);
    mI2.append_column(1);
    TS_ASSERT(mI2 == mI2T);
    mI3.append_column(2);
    TS_ASSERT(mI3 == mI3T);
  }
  void testMatrisRemove_column( void )
  {
    Matris<int> mI0(3,3);
    MatrisFactory(mI0,{0,1,2,3,4,5,6,7,8});
    Matris<int> mI1(3,3);
    MatrisFactory(mI1,{0,1,2,3,4,5,6,7,8});
    Matris<int> mI2(3,3);
    MatrisFactory(mI2,{0,1,2,3,4,5,6,7,8});

    Matris<int> mI0T(2,3);
    MatrisFactory(mI0T,{1,2,4,5,7,8});
    Matris<int> mI1T(2,3);
    MatrisFactory(mI1T,{0,2,3,5,6,8});
    Matris<int> mI2T(2,3);
    MatrisFactory(mI2T,{0,1,3,4,6,7});

    mI0.remove_column(0);
    TS_ASSERT(mI0 == mI0T);
    mI1.remove_column(1);
    TS_ASSERT(mI1 == mI1T);
    mI2.remove_column(2);
    TS_ASSERT(mI2 == mI2T);
  }

  void testMatrisBeginEnd( void )
  {
    initializer_list<int> list = {1,2,3,4};
    const Matris<int>& m = list;
    int index = 0;
    for (int* i = m.begin(); i != m.end(); i++)
    {
      TS_ASSERT(list.begin()[index] == *i);
      index++;
    }
  }

  void testMatrisInputOutput( void )
  {
    ofstream fout("testData");
    Matris<int> mO = {0,1,2,3};
    fout << mO;
    fout.close();

    ifstream fin("testData");
    Matris<int> mI = {0,1,2,3};
    fin >> mI;
    fin.close();

    TS_ASSERT(mO == mI);
  }


private:
  void middlemanConstructorThrow()
  {
    Matris<int> data = {0,1,2,3,4,5,6,7,8};
  }
  void middlemanConstructorNoThrow()
  {
    Matris<int> data = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
  }
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
};