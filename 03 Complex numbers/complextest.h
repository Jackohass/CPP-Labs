#include<cxxtest/TestSuite.h>
#include"complex.h"
#include<fstream>

class MyTestSuite : public CxxTest::TestSuite 
{
public:
  // void testMatrisConstructorListNonEvenSquare( void )
  // {
  //   TS_ASSERT_THROWS(middlemanConstructorThrow(), out_of_range);
  // }
  void testComplexConstructor0Args( void )
  {
    Complex data;
    
    TS_ASSERT(data.real() == 0);
    TS_ASSERT(data.imag() == 0);
  }
  void testComplexConstructor1Args( void )
  {
    Complex data(4);
    
    TS_ASSERT(data.real() == 4);
    TS_ASSERT(data.imag() == 0);
  }
  void testComplexConstructor2Args( void )
  {
    Complex data(2,4);
    
    TS_ASSERT(data.real() == 2);
    TS_ASSERT(data.imag() == 4);
  }
  void testComplexConstructorComplexArgs( void )
  {
    Complex data0(2,4);
    Complex data1(data0);
    data0.real(1);
    data0.imag(1);
    
    TS_ASSERT(data0.real() == 1);
    TS_ASSERT(data0.imag() == 1);
    TS_ASSERT(data1.real() == 2);
    TS_ASSERT(data1.imag() == 4);
  }
  void testComplexReturnRealImag( void )
  {
    Complex data(2,4);
    
    TS_ASSERT(data.real() == 2);
    TS_ASSERT(data.imag() == 4);
  }
  void testComplexChangeRealImag( void )
  {
    Complex data(2,4);
    data.real(3);
    data.imag(9);

    TS_ASSERT(data.real() == 3);
    TS_ASSERT(data.imag() == 9);
  }
  void testComplexEqualNoChain( void )
  {
    Complex data0(2,4);
    Complex data1;
    data1 = data0;
    data0.real(1);
    data0.imag(1);
    
    TS_ASSERT(data0.real() == 1);
    TS_ASSERT(data0.imag() == 1);
    TS_ASSERT(data1.real() == 2);
    TS_ASSERT(data1.imag() == 4);
  }
  void testComplexEqualChain( void )
  {
    Complex data0(2,4);
    Complex data1(3,9);
    Complex data2(5,25);
    Complex data3;
    data3 = data0 = data1 = data2;
    
    TS_ASSERT(data0 == data1);
    TS_ASSERT(data2 == data1);
    TS_ASSERT(data2 == data3);

    data0.real(1);
    data0.imag(1);
    data1.real(4);
    data1.imag(2);
    data2.real(9);
    data2.imag(3);
    data3.real(25);
    data3.imag(5);
    TS_ASSERT(data0.real() == 1);
    TS_ASSERT(data0.imag() == 1);
    TS_ASSERT(data1.real() == 4);
    TS_ASSERT(data1.imag() == 2);
    TS_ASSERT(data2.real() == 9);
    TS_ASSERT(data2.imag() == 3);
    TS_ASSERT(data3.real() == 25);
    TS_ASSERT(data3.imag() == 5);
  }
  void testComplexPlusEqualScalar( void )
  {
    Complex data0(2,4);
    data0 += 1;
    
    TS_ASSERT(data0.real() == 3);
    TS_ASSERT(data0.imag() == 4);
  }
  void testComplexPlusEqualComplex( void )
  {
    Complex data0(2,4);
    Complex data1(3,9);
    data1 += data0;
    data0.real(1);
    data0.imag(1);
    
    TS_ASSERT(data0.real() == 1);
    TS_ASSERT(data0.imag() == 1);
    TS_ASSERT(data1.real() == 5);
    TS_ASSERT(data1.imag() == 13);
  }
  void testComplexMinusEqualScalar( void )
  {
    Complex data0(2,4);
    data0 -= 1;
    
    TS_ASSERT(data0.real() == 1);
    TS_ASSERT(data0.imag() == 4);
  }
  void testComplexMinusEqualComplex( void )
  {
    Complex data0(2,4);
    Complex data1(3,9);
    data1 -= data0;
    data0.real(2);
    data0.imag(2);
    
    TS_ASSERT(data0.real() == 2);
    TS_ASSERT(data0.imag() == 2);
    TS_ASSERT(data1.real() == 1);
    TS_ASSERT(data1.imag() == 5);
  }
  void testComplexDivisionEqualScalar( void )
  {
    Complex data0(2,4);
    data0 /= 2;
    
    TS_ASSERT(data0.real() == 1);
    TS_ASSERT(data0.imag() == 2);
  }
  void testComplexDivisionEqualComplexWholeResult( void )
  {
    Complex data0(2,4);
    Complex data1(4,8);
    data1 /= data0;
    data0.real(2);
    data0.imag(2);
    
    TS_ASSERT(data0.real() == 2);
    TS_ASSERT(data0.imag() == 2);
    TS_ASSERT(data1.real() == 2);
    TS_ASSERT(data1.imag() == 0);
  }
  void testComplexDivisionEqualComplexFloatResult( void )
  {
    Complex data0(2,1);
    Complex data1(4,8);
    data1 /= data0;
    data0.real(2);
    data0.imag(2);
    
    TS_ASSERT(data0.real() == 2);
    TS_ASSERT(data0.imag() == 2);
    TS_ASSERT(data1.real() == 3.2);
    TS_ASSERT(data1.imag() == 2.4);
  }
  void testComplexMultiEqualScalar( void )
  {
    Complex data0(2,4);
    data0 *= 2;
    
    TS_ASSERT(data0.real() == 4);
    TS_ASSERT(data0.imag() == 8);
  }
  void testComplexMultiEqualComplex( void )
  {
    Complex data0(2,1);
    Complex data1(4,2);
    data1 *= data0;
    data0.real(2);
    data0.imag(2);
    
    TS_ASSERT(data0.real() == 2);
    TS_ASSERT(data0.imag() == 2);
    TS_ASSERT(data1.real() == 6);
    TS_ASSERT(data1.imag() == 8);
  }
  void testComplexUnaryPlus( void )
  {
    Complex data0(2,1);
    Complex data1 = +data0;
    
    TS_ASSERT(data0.real() == 2);
    TS_ASSERT(data0.imag() == 1);
    TS_ASSERT(data1.real() == 2);
    TS_ASSERT(data1.imag() == 1);
  }
  void testComplexUnaryMinus( void )
  {
    Complex data0(2,1);
    Complex data1 = -data0;
    
    TS_ASSERT(data0.real() == 2);
    TS_ASSERT(data0.imag() == 1);
    TS_ASSERT(data1.real() == -2);
    TS_ASSERT(data1.imag() == -1);
  }
  void testComplexBinaryPlusScalar( void )
  {
    Complex data0(2,1);
    Complex data1 = data0+2;
    data0.real(0);
    data0.imag(0);

    
    TS_ASSERT(data0.real() == 0);
    TS_ASSERT(data0.imag() == 0);
    TS_ASSERT(data1.real() == 4);
    TS_ASSERT(data1.imag() == 1);
  }
  void testComplexBinaryPlusComplex( void )
  {
    Complex data0(2,1);
    Complex data1(1,2);
    Complex data2 = data0+data1;
    data0.real(0);
    data0.imag(0);
    data1.real(1);
    data1.imag(1);
    
    TS_ASSERT(data0.real() == 0);
    TS_ASSERT(data0.imag() == 0);
    TS_ASSERT(data1.real() == 1);
    TS_ASSERT(data1.imag() == 1);
    TS_ASSERT(data2.real() == 3);
    TS_ASSERT(data2.imag() == 3);
  }
  void testComplexBinaryMinusScalar( void )
  {
    Complex data0(2,1);
    Complex data1 = data0-2;
    data0.real(1);
    data0.imag(1);

    
    TS_ASSERT(data0.real() == 1);
    TS_ASSERT(data0.imag() == 1);
    TS_ASSERT(data1.real() == 0);
    TS_ASSERT(data1.imag() == 1);
  }
  void testComplexBinaryMinusComplex( void )
  {
    Complex data0(2,1);
    Complex data1(1,2);
    Complex data2 = data0-data1;
    data0.real(0);
    data0.imag(0);
    data1.real(1);
    data1.imag(1);
    
    TS_ASSERT(data0.real() == 0);
    TS_ASSERT(data0.imag() == 0);
    TS_ASSERT(data1.real() == 1);
    TS_ASSERT(data1.imag() == 1);
    TS_ASSERT(data2.real() == 1);
    TS_ASSERT(data2.imag() == -1);
  }
  void testComplexBinaryDivisionScalar( void )
  {
    Complex data0(2,4);
    Complex data1 = data0/2;
    data0.real(1);
    data0.imag(1);

    
    TS_ASSERT(data0.real() == 1);
    TS_ASSERT(data0.imag() == 1);
    TS_ASSERT(data1.real() == 1);
    TS_ASSERT(data1.imag() == 2);
  }
  void testScalarBinaryDivisionComplex( void )
  {
    Complex data0(2,1);
    Complex data1 = 4/data0;
    data0.real(1);
    data0.imag(1);
    
    TS_ASSERT(data0.real() == 1);
    TS_ASSERT(data0.imag() == 1);
    TS_ASSERT(data1.real() == 1.6);
    TS_ASSERT(data1.imag() == 0.8);
  }
  void testComplexBinaryDivisionComplex( void )
  {
    Complex data0(4,8);
    Complex data1(2,1);
    Complex data2 = data0/data1;
    data0.real(0);
    data0.imag(0);
    data1.real(1);
    data1.imag(1);
    
    TS_ASSERT(data0.real() == 0);
    TS_ASSERT(data0.imag() == 0);
    TS_ASSERT(data1.real() == 1);
    TS_ASSERT(data1.imag() == 1);
    TS_ASSERT(data2.real() == 3.2);
    TS_ASSERT(data2.imag() == 2.4);
  }
  void testComplexBinaryMultiScalar( void )
  {
    Complex data0(2,1);
    Complex data1 = data0*2;
    data0.real(1);
    data0.imag(1);

    
    TS_ASSERT(data0.real() == 1);
    TS_ASSERT(data0.imag() == 1);
    TS_ASSERT(data1.real() == 4);
    TS_ASSERT(data1.imag() == 2);
    data1 = 2*data0;
    TS_ASSERT(data1.real() == 2);
    TS_ASSERT(data1.imag() == 2);
  }
  void testComplexBinaryMultiComplex( void )
  {
    Complex data0(2,1);
    Complex data1(4,2);
    Complex data2 = data0*data1;
    data0.real(0);
    data0.imag(0);
    data1.real(1);
    data1.imag(1);
    
    TS_ASSERT(data0.real() == 0);
    TS_ASSERT(data0.imag() == 0);
    TS_ASSERT(data1.real() == 1);
    TS_ASSERT(data1.imag() == 1);
    TS_ASSERT(data2.real() == 6);
    TS_ASSERT(data2.imag() == 8);
  }
  void testComplexEqualsComplex( void )
  {
    Complex data0(2,1);
    Complex data1(2,1);
    
    TS_ASSERT(data0 == data1);
    TS_ASSERT(data1 == data0);
  }
  void testComplexEqualsScalar( void )
  {
    Complex data0(2,0);
    
    TS_ASSERT(data0 == 2);
    TS_ASSERT(2 == data0);
  }
  void testComplexNotEqualsComplex( void )
  {
    Complex data0(2,1);
    Complex data1(3,1);
    
    TS_ASSERT(data0 != data1);
    TS_ASSERT(data1 != data0);
  }
  void testComplexNotEqualsScalar( void )
  {
    Complex data0(2,1);
    Complex data1(3,0);
    
    TS_ASSERT(data0 != 2);
    TS_ASSERT(2 != data0);
    TS_ASSERT(data1 != 2);
    TS_ASSERT(2 != data1);
  }
  void testComplexNotMemberReturnRealImag( void )
  {
    Complex data(2,4);
    
    TS_ASSERT(real(data) == 2);
    TS_ASSERT(imag(data) == 4);
  }
  void testComplexIntAbsolute0( void )
  {
    Complex data(3,4);
    
    TS_ASSERT(abs(data) == 5);
  }
  void testComplexIntAbsolute1( void )
  {
    Complex data(-3,-4);
    
    TS_ASSERT(abs(data) == 5);
  }
  void testComplexIntAbsolute2( void )
  {
    Complex data(3,0);
    
    TS_ASSERT(abs(data) == 3);
  }
  void testComplexIntAbsolute3( void )
  {
    Complex data(-3,0);
    
    TS_ASSERT(abs(data) == 3);
  }
  void testComplexIntAbsolute4( void )
  {
    Complex data(0,4);
    
    TS_ASSERT(abs(data) == 4);
  }
  void testComplexIntAbsolute5( void )
  {
    Complex data(0,-4);
    
    TS_ASSERT(abs(data) == 4);
  }
  void testComplexFloatAbsolute0( void )
  {
    Complex data(2,1.5);
    
    TS_ASSERT(abs(data) == 2.5);
  }
  void testComplexFloatAbsolute1( void )
  {
    Complex data(-2,-1.5);
    
    TS_ASSERT(abs(data) == 2.5);
  }
  void testComplexFloatAbsolute2( void )
  {
    Complex data(2,0);
    
    TS_ASSERT(abs(data) == 2);
  }
  void testComplexFloatAbsolute3( void )
  {
    Complex data(-2,0);
    
    TS_ASSERT(abs(data) ==2);
  }
  void testComplexFloatAbsolute4( void )
  {
    Complex data(0,1.5);
    
    TS_ASSERT(abs(data) == 1.5);
  }
  void testComplexFloatAbsolute5( void )
  {
    Complex data(0,-1.5);
    
    TS_ASSERT(abs(data) == 1.5);
  }
  void testComplexLessThan( void )
  {
    Complex data0(2,4);
    Complex data1(3,4);
    
    TS_ASSERT(data0 == (data0 < data1));
  }
  void testComplexInputOutput( void )
  {
    ofstream fout("testData");
    Complex cO(-12,4);
    fout << cO;
    fout.close();

    ifstream fin("testData");
    Complex cI(8,-2);
    fin >> cI;
    fin.close();

    TS_ASSERT(cO == cI);
  }
  void testComplexLiteral_i0( void )
  {
    Complex data0 = 1+1_i;
    
    TS_ASSERT(data0.real() == 1);
    TS_ASSERT(data0.imag() == 1);
  }
  void testComplexLiteral_i1( void )
  {
    Complex data1 = 2-1_i;
    
    TS_ASSERT(data1.real() == 2);
    TS_ASSERT(data1.imag() == -1);
  }
  void testComplexLiteral_i2( void )
  {
    Complex data2 = 5.2+2.1_i;

    TS_ASSERT(data2.real() == 5.2);
    TS_ASSERT(data2.imag() == 2.1);
  }
  void testComplexLiteral_i3( void )
  {
    Complex data3 = 4.01-2.1_i;

    TS_ASSERT(data3.real() == 4.01);
    TS_ASSERT(data3.imag() == -2.1);
  }

private:
  void printComplex(Complex c)
  {
      printf("%f + %fi\n", c.real(), c.imag());
  }
};