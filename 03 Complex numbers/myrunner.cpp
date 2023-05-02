/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#define _CXXTEST_HAVE_EH
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main< CxxTest::ErrorPrinter >( tmp, argc, argv );
    return status;
}
bool suite_MyTestSuite_init = false;
#include "complextest.h"

static MyTestSuite suite_MyTestSuite;

static CxxTest::List Tests_MyTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_MyTestSuite( "complextest.h", 5, "MyTestSuite", suite_MyTestSuite, Tests_MyTestSuite );

static class TestDescription_suite_MyTestSuite_testComplexConstructor0Args : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testComplexConstructor0Args() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 12, "testComplexConstructor0Args" ) {}
 void runTest() { suite_MyTestSuite.testComplexConstructor0Args(); }
} testDescription_suite_MyTestSuite_testComplexConstructor0Args;

static class TestDescription_suite_MyTestSuite_testComplexConstructor1Args : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testComplexConstructor1Args() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 19, "testComplexConstructor1Args" ) {}
 void runTest() { suite_MyTestSuite.testComplexConstructor1Args(); }
} testDescription_suite_MyTestSuite_testComplexConstructor1Args;

static class TestDescription_suite_MyTestSuite_testComplexConstructor2Args : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testComplexConstructor2Args() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 26, "testComplexConstructor2Args" ) {}
 void runTest() { suite_MyTestSuite.testComplexConstructor2Args(); }
} testDescription_suite_MyTestSuite_testComplexConstructor2Args;

static class TestDescription_suite_MyTestSuite_testComplexConstructorComplexArgs : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testComplexConstructorComplexArgs() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 33, "testComplexConstructorComplexArgs" ) {}
 void runTest() { suite_MyTestSuite.testComplexConstructorComplexArgs(); }
} testDescription_suite_MyTestSuite_testComplexConstructorComplexArgs;

static class TestDescription_suite_MyTestSuite_testComplexReturnRealImag : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testComplexReturnRealImag() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 45, "testComplexReturnRealImag" ) {}
 void runTest() { suite_MyTestSuite.testComplexReturnRealImag(); }
} testDescription_suite_MyTestSuite_testComplexReturnRealImag;

static class TestDescription_suite_MyTestSuite_testComplexChangeRealImag : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testComplexChangeRealImag() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 52, "testComplexChangeRealImag" ) {}
 void runTest() { suite_MyTestSuite.testComplexChangeRealImag(); }
} testDescription_suite_MyTestSuite_testComplexChangeRealImag;

static class TestDescription_suite_MyTestSuite_testComplexEqualNoChain : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testComplexEqualNoChain() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 61, "testComplexEqualNoChain" ) {}
 void runTest() { suite_MyTestSuite.testComplexEqualNoChain(); }
} testDescription_suite_MyTestSuite_testComplexEqualNoChain;

static class TestDescription_suite_MyTestSuite_testComplexEqualChain : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testComplexEqualChain() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 74, "testComplexEqualChain" ) {}
 void runTest() { suite_MyTestSuite.testComplexEqualChain(); }
} testDescription_suite_MyTestSuite_testComplexEqualChain;

static class TestDescription_suite_MyTestSuite_testComplexPlusEqualScalar : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testComplexPlusEqualScalar() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 103, "testComplexPlusEqualScalar" ) {}
 void runTest() { suite_MyTestSuite.testComplexPlusEqualScalar(); }
} testDescription_suite_MyTestSuite_testComplexPlusEqualScalar;

static class TestDescription_suite_MyTestSuite_testComplexPlusEqualComplex : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testComplexPlusEqualComplex() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 111, "testComplexPlusEqualComplex" ) {}
 void runTest() { suite_MyTestSuite.testComplexPlusEqualComplex(); }
} testDescription_suite_MyTestSuite_testComplexPlusEqualComplex;

static class TestDescription_suite_MyTestSuite_testComplexMinusEqualScalar : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testComplexMinusEqualScalar() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 124, "testComplexMinusEqualScalar" ) {}
 void runTest() { suite_MyTestSuite.testComplexMinusEqualScalar(); }
} testDescription_suite_MyTestSuite_testComplexMinusEqualScalar;

static class TestDescription_suite_MyTestSuite_testComplexMinusEqualComplex : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testComplexMinusEqualComplex() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 132, "testComplexMinusEqualComplex" ) {}
 void runTest() { suite_MyTestSuite.testComplexMinusEqualComplex(); }
} testDescription_suite_MyTestSuite_testComplexMinusEqualComplex;

static class TestDescription_suite_MyTestSuite_testComplexDivisionEqualScalar : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testComplexDivisionEqualScalar() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 145, "testComplexDivisionEqualScalar" ) {}
 void runTest() { suite_MyTestSuite.testComplexDivisionEqualScalar(); }
} testDescription_suite_MyTestSuite_testComplexDivisionEqualScalar;

static class TestDescription_suite_MyTestSuite_testComplexDivisionEqualComplexWholeResult : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testComplexDivisionEqualComplexWholeResult() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 153, "testComplexDivisionEqualComplexWholeResult" ) {}
 void runTest() { suite_MyTestSuite.testComplexDivisionEqualComplexWholeResult(); }
} testDescription_suite_MyTestSuite_testComplexDivisionEqualComplexWholeResult;

static class TestDescription_suite_MyTestSuite_testComplexDivisionEqualComplexFloatResult : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testComplexDivisionEqualComplexFloatResult() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 166, "testComplexDivisionEqualComplexFloatResult" ) {}
 void runTest() { suite_MyTestSuite.testComplexDivisionEqualComplexFloatResult(); }
} testDescription_suite_MyTestSuite_testComplexDivisionEqualComplexFloatResult;

static class TestDescription_suite_MyTestSuite_testComplexMultiEqualScalar : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testComplexMultiEqualScalar() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 179, "testComplexMultiEqualScalar" ) {}
 void runTest() { suite_MyTestSuite.testComplexMultiEqualScalar(); }
} testDescription_suite_MyTestSuite_testComplexMultiEqualScalar;

static class TestDescription_suite_MyTestSuite_testComplexMultiEqualComplex : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testComplexMultiEqualComplex() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 187, "testComplexMultiEqualComplex" ) {}
 void runTest() { suite_MyTestSuite.testComplexMultiEqualComplex(); }
} testDescription_suite_MyTestSuite_testComplexMultiEqualComplex;

static class TestDescription_suite_MyTestSuite_testComplexUnaryPlus : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testComplexUnaryPlus() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 200, "testComplexUnaryPlus" ) {}
 void runTest() { suite_MyTestSuite.testComplexUnaryPlus(); }
} testDescription_suite_MyTestSuite_testComplexUnaryPlus;

static class TestDescription_suite_MyTestSuite_testComplexUnaryMinus : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testComplexUnaryMinus() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 210, "testComplexUnaryMinus" ) {}
 void runTest() { suite_MyTestSuite.testComplexUnaryMinus(); }
} testDescription_suite_MyTestSuite_testComplexUnaryMinus;

static class TestDescription_suite_MyTestSuite_testComplexBinaryPlusScalar : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testComplexBinaryPlusScalar() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 220, "testComplexBinaryPlusScalar" ) {}
 void runTest() { suite_MyTestSuite.testComplexBinaryPlusScalar(); }
} testDescription_suite_MyTestSuite_testComplexBinaryPlusScalar;

static class TestDescription_suite_MyTestSuite_testComplexBinaryPlusComplex : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testComplexBinaryPlusComplex() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 233, "testComplexBinaryPlusComplex" ) {}
 void runTest() { suite_MyTestSuite.testComplexBinaryPlusComplex(); }
} testDescription_suite_MyTestSuite_testComplexBinaryPlusComplex;

static class TestDescription_suite_MyTestSuite_testComplexBinaryMinusScalar : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testComplexBinaryMinusScalar() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 250, "testComplexBinaryMinusScalar" ) {}
 void runTest() { suite_MyTestSuite.testComplexBinaryMinusScalar(); }
} testDescription_suite_MyTestSuite_testComplexBinaryMinusScalar;

static class TestDescription_suite_MyTestSuite_testComplexBinaryMinusComplex : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testComplexBinaryMinusComplex() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 263, "testComplexBinaryMinusComplex" ) {}
 void runTest() { suite_MyTestSuite.testComplexBinaryMinusComplex(); }
} testDescription_suite_MyTestSuite_testComplexBinaryMinusComplex;

static class TestDescription_suite_MyTestSuite_testComplexBinaryDivisionScalar : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testComplexBinaryDivisionScalar() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 280, "testComplexBinaryDivisionScalar" ) {}
 void runTest() { suite_MyTestSuite.testComplexBinaryDivisionScalar(); }
} testDescription_suite_MyTestSuite_testComplexBinaryDivisionScalar;

static class TestDescription_suite_MyTestSuite_testScalarBinaryDivisionComplex : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testScalarBinaryDivisionComplex() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 293, "testScalarBinaryDivisionComplex" ) {}
 void runTest() { suite_MyTestSuite.testScalarBinaryDivisionComplex(); }
} testDescription_suite_MyTestSuite_testScalarBinaryDivisionComplex;

static class TestDescription_suite_MyTestSuite_testComplexBinaryDivisionComplex : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testComplexBinaryDivisionComplex() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 305, "testComplexBinaryDivisionComplex" ) {}
 void runTest() { suite_MyTestSuite.testComplexBinaryDivisionComplex(); }
} testDescription_suite_MyTestSuite_testComplexBinaryDivisionComplex;

static class TestDescription_suite_MyTestSuite_testComplexBinaryMultiScalar : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testComplexBinaryMultiScalar() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 322, "testComplexBinaryMultiScalar" ) {}
 void runTest() { suite_MyTestSuite.testComplexBinaryMultiScalar(); }
} testDescription_suite_MyTestSuite_testComplexBinaryMultiScalar;

static class TestDescription_suite_MyTestSuite_testComplexBinaryMultiComplex : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testComplexBinaryMultiComplex() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 338, "testComplexBinaryMultiComplex" ) {}
 void runTest() { suite_MyTestSuite.testComplexBinaryMultiComplex(); }
} testDescription_suite_MyTestSuite_testComplexBinaryMultiComplex;

static class TestDescription_suite_MyTestSuite_testComplexEqualsComplex : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testComplexEqualsComplex() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 355, "testComplexEqualsComplex" ) {}
 void runTest() { suite_MyTestSuite.testComplexEqualsComplex(); }
} testDescription_suite_MyTestSuite_testComplexEqualsComplex;

static class TestDescription_suite_MyTestSuite_testComplexEqualsScalar : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testComplexEqualsScalar() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 363, "testComplexEqualsScalar" ) {}
 void runTest() { suite_MyTestSuite.testComplexEqualsScalar(); }
} testDescription_suite_MyTestSuite_testComplexEqualsScalar;

static class TestDescription_suite_MyTestSuite_testComplexNotEqualsComplex : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testComplexNotEqualsComplex() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 370, "testComplexNotEqualsComplex" ) {}
 void runTest() { suite_MyTestSuite.testComplexNotEqualsComplex(); }
} testDescription_suite_MyTestSuite_testComplexNotEqualsComplex;

static class TestDescription_suite_MyTestSuite_testComplexNotEqualsScalar : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testComplexNotEqualsScalar() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 378, "testComplexNotEqualsScalar" ) {}
 void runTest() { suite_MyTestSuite.testComplexNotEqualsScalar(); }
} testDescription_suite_MyTestSuite_testComplexNotEqualsScalar;

static class TestDescription_suite_MyTestSuite_testComplexNotMemberReturnRealImag : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testComplexNotMemberReturnRealImag() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 388, "testComplexNotMemberReturnRealImag" ) {}
 void runTest() { suite_MyTestSuite.testComplexNotMemberReturnRealImag(); }
} testDescription_suite_MyTestSuite_testComplexNotMemberReturnRealImag;

static class TestDescription_suite_MyTestSuite_testComplexIntAbsolute0 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testComplexIntAbsolute0() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 395, "testComplexIntAbsolute0" ) {}
 void runTest() { suite_MyTestSuite.testComplexIntAbsolute0(); }
} testDescription_suite_MyTestSuite_testComplexIntAbsolute0;

static class TestDescription_suite_MyTestSuite_testComplexIntAbsolute1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testComplexIntAbsolute1() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 401, "testComplexIntAbsolute1" ) {}
 void runTest() { suite_MyTestSuite.testComplexIntAbsolute1(); }
} testDescription_suite_MyTestSuite_testComplexIntAbsolute1;

static class TestDescription_suite_MyTestSuite_testComplexIntAbsolute2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testComplexIntAbsolute2() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 407, "testComplexIntAbsolute2" ) {}
 void runTest() { suite_MyTestSuite.testComplexIntAbsolute2(); }
} testDescription_suite_MyTestSuite_testComplexIntAbsolute2;

static class TestDescription_suite_MyTestSuite_testComplexIntAbsolute3 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testComplexIntAbsolute3() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 413, "testComplexIntAbsolute3" ) {}
 void runTest() { suite_MyTestSuite.testComplexIntAbsolute3(); }
} testDescription_suite_MyTestSuite_testComplexIntAbsolute3;

static class TestDescription_suite_MyTestSuite_testComplexIntAbsolute4 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testComplexIntAbsolute4() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 419, "testComplexIntAbsolute4" ) {}
 void runTest() { suite_MyTestSuite.testComplexIntAbsolute4(); }
} testDescription_suite_MyTestSuite_testComplexIntAbsolute4;

static class TestDescription_suite_MyTestSuite_testComplexIntAbsolute5 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testComplexIntAbsolute5() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 425, "testComplexIntAbsolute5" ) {}
 void runTest() { suite_MyTestSuite.testComplexIntAbsolute5(); }
} testDescription_suite_MyTestSuite_testComplexIntAbsolute5;

static class TestDescription_suite_MyTestSuite_testComplexFloatAbsolute0 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testComplexFloatAbsolute0() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 431, "testComplexFloatAbsolute0" ) {}
 void runTest() { suite_MyTestSuite.testComplexFloatAbsolute0(); }
} testDescription_suite_MyTestSuite_testComplexFloatAbsolute0;

static class TestDescription_suite_MyTestSuite_testComplexFloatAbsolute1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testComplexFloatAbsolute1() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 437, "testComplexFloatAbsolute1" ) {}
 void runTest() { suite_MyTestSuite.testComplexFloatAbsolute1(); }
} testDescription_suite_MyTestSuite_testComplexFloatAbsolute1;

static class TestDescription_suite_MyTestSuite_testComplexFloatAbsolute2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testComplexFloatAbsolute2() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 443, "testComplexFloatAbsolute2" ) {}
 void runTest() { suite_MyTestSuite.testComplexFloatAbsolute2(); }
} testDescription_suite_MyTestSuite_testComplexFloatAbsolute2;

static class TestDescription_suite_MyTestSuite_testComplexFloatAbsolute3 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testComplexFloatAbsolute3() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 449, "testComplexFloatAbsolute3" ) {}
 void runTest() { suite_MyTestSuite.testComplexFloatAbsolute3(); }
} testDescription_suite_MyTestSuite_testComplexFloatAbsolute3;

static class TestDescription_suite_MyTestSuite_testComplexFloatAbsolute4 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testComplexFloatAbsolute4() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 455, "testComplexFloatAbsolute4" ) {}
 void runTest() { suite_MyTestSuite.testComplexFloatAbsolute4(); }
} testDescription_suite_MyTestSuite_testComplexFloatAbsolute4;

static class TestDescription_suite_MyTestSuite_testComplexFloatAbsolute5 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testComplexFloatAbsolute5() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 461, "testComplexFloatAbsolute5" ) {}
 void runTest() { suite_MyTestSuite.testComplexFloatAbsolute5(); }
} testDescription_suite_MyTestSuite_testComplexFloatAbsolute5;

static class TestDescription_suite_MyTestSuite_testComplexLessThan : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testComplexLessThan() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 467, "testComplexLessThan" ) {}
 void runTest() { suite_MyTestSuite.testComplexLessThan(); }
} testDescription_suite_MyTestSuite_testComplexLessThan;

static class TestDescription_suite_MyTestSuite_testComplexInputOutput : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testComplexInputOutput() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 474, "testComplexInputOutput" ) {}
 void runTest() { suite_MyTestSuite.testComplexInputOutput(); }
} testDescription_suite_MyTestSuite_testComplexInputOutput;

static class TestDescription_suite_MyTestSuite_testComplexLiteral_i0 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testComplexLiteral_i0() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 488, "testComplexLiteral_i0" ) {}
 void runTest() { suite_MyTestSuite.testComplexLiteral_i0(); }
} testDescription_suite_MyTestSuite_testComplexLiteral_i0;

static class TestDescription_suite_MyTestSuite_testComplexLiteral_i1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testComplexLiteral_i1() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 495, "testComplexLiteral_i1" ) {}
 void runTest() { suite_MyTestSuite.testComplexLiteral_i1(); }
} testDescription_suite_MyTestSuite_testComplexLiteral_i1;

static class TestDescription_suite_MyTestSuite_testComplexLiteral_i2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testComplexLiteral_i2() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 502, "testComplexLiteral_i2" ) {}
 void runTest() { suite_MyTestSuite.testComplexLiteral_i2(); }
} testDescription_suite_MyTestSuite_testComplexLiteral_i2;

static class TestDescription_suite_MyTestSuite_testComplexLiteral_i3 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testComplexLiteral_i3() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 509, "testComplexLiteral_i3" ) {}
 void runTest() { suite_MyTestSuite.testComplexLiteral_i3(); }
} testDescription_suite_MyTestSuite_testComplexLiteral_i3;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
