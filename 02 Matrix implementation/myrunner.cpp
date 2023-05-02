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
#include "matristest.h"

static MyTestSuite suite_MyTestSuite;

static CxxTest::List Tests_MyTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_MyTestSuite( "matristest.h", 5, "MyTestSuite", suite_MyTestSuite, Tests_MyTestSuite );

static class TestDescription_suite_MyTestSuite_testMatrisConstructor0Args : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMatrisConstructor0Args() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 8, "testMatrisConstructor0Args" ) {}
 void runTest() { suite_MyTestSuite.testMatrisConstructor0Args(); }
} testDescription_suite_MyTestSuite_testMatrisConstructor0Args;

static class TestDescription_suite_MyTestSuite_testMatrisConstructor1Arg0 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMatrisConstructor1Arg0() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 15, "testMatrisConstructor1Arg0" ) {}
 void runTest() { suite_MyTestSuite.testMatrisConstructor1Arg0(); }
} testDescription_suite_MyTestSuite_testMatrisConstructor1Arg0;

static class TestDescription_suite_MyTestSuite_testMatrisConstructor2Args00 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMatrisConstructor2Args00() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 22, "testMatrisConstructor2Args00" ) {}
 void runTest() { suite_MyTestSuite.testMatrisConstructor2Args00(); }
} testDescription_suite_MyTestSuite_testMatrisConstructor2Args00;

static class TestDescription_suite_MyTestSuite_testMatrisConstructorListEmpty : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMatrisConstructorListEmpty() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 29, "testMatrisConstructorListEmpty" ) {}
 void runTest() { suite_MyTestSuite.testMatrisConstructorListEmpty(); }
} testDescription_suite_MyTestSuite_testMatrisConstructorListEmpty;

static class TestDescription_suite_MyTestSuite_testMatrisConstructorListNonEvenSquare : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMatrisConstructorListNonEvenSquare() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 36, "testMatrisConstructorListNonEvenSquare" ) {}
 void runTest() { suite_MyTestSuite.testMatrisConstructorListNonEvenSquare(); }
} testDescription_suite_MyTestSuite_testMatrisConstructorListNonEvenSquare;

static class TestDescription_suite_MyTestSuite_testMatrisConstructorListEvenSquare : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMatrisConstructorListEvenSquare() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 40, "testMatrisConstructorListEvenSquare" ) {}
 void runTest() { suite_MyTestSuite.testMatrisConstructorListEvenSquare(); }
} testDescription_suite_MyTestSuite_testMatrisConstructorListEvenSquare;

static class TestDescription_suite_MyTestSuite_testMatrisConstructorCopy : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMatrisConstructorCopy() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 44, "testMatrisConstructorCopy" ) {}
 void runTest() { suite_MyTestSuite.testMatrisConstructorCopy(); }
} testDescription_suite_MyTestSuite_testMatrisConstructorCopy;

static class TestDescription_suite_MyTestSuite_testMatrisConstructorMove : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMatrisConstructorMove() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 50, "testMatrisConstructorMove" ) {}
 void runTest() { suite_MyTestSuite.testMatrisConstructorMove(); }
} testDescription_suite_MyTestSuite_testMatrisConstructorMove;

static class TestDescription_suite_MyTestSuite_testMatrisOperCopy : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMatrisOperCopy() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 63, "testMatrisOperCopy" ) {}
 void runTest() { suite_MyTestSuite.testMatrisOperCopy(); }
} testDescription_suite_MyTestSuite_testMatrisOperCopy;

static class TestDescription_suite_MyTestSuite_testMatrisOperMove : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMatrisOperMove() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 70, "testMatrisOperMove" ) {}
 void runTest() { suite_MyTestSuite.testMatrisOperMove(); }
} testDescription_suite_MyTestSuite_testMatrisOperMove;

static class TestDescription_suite_MyTestSuite_testMatrisOperPlusScalarAssign : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMatrisOperPlusScalarAssign() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 83, "testMatrisOperPlusScalarAssign" ) {}
 void runTest() { suite_MyTestSuite.testMatrisOperPlusScalarAssign(); }
} testDescription_suite_MyTestSuite_testMatrisOperPlusScalarAssign;

static class TestDescription_suite_MyTestSuite_testMatrisOperPlusMatrisAssign : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMatrisOperPlusMatrisAssign() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 90, "testMatrisOperPlusMatrisAssign" ) {}
 void runTest() { suite_MyTestSuite.testMatrisOperPlusMatrisAssign(); }
} testDescription_suite_MyTestSuite_testMatrisOperPlusMatrisAssign;

static class TestDescription_suite_MyTestSuite_testMatrisOperMinusScalarAssign : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMatrisOperMinusScalarAssign() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 98, "testMatrisOperMinusScalarAssign" ) {}
 void runTest() { suite_MyTestSuite.testMatrisOperMinusScalarAssign(); }
} testDescription_suite_MyTestSuite_testMatrisOperMinusScalarAssign;

static class TestDescription_suite_MyTestSuite_testMatrisOperMinusMatrisAssign : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMatrisOperMinusMatrisAssign() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 105, "testMatrisOperMinusMatrisAssign" ) {}
 void runTest() { suite_MyTestSuite.testMatrisOperMinusMatrisAssign(); }
} testDescription_suite_MyTestSuite_testMatrisOperMinusMatrisAssign;

static class TestDescription_suite_MyTestSuite_testMatrisOperMultScalarAssign : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMatrisOperMultScalarAssign() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 113, "testMatrisOperMultScalarAssign" ) {}
 void runTest() { suite_MyTestSuite.testMatrisOperMultScalarAssign(); }
} testDescription_suite_MyTestSuite_testMatrisOperMultScalarAssign;

static class TestDescription_suite_MyTestSuite_testMatrisOperMultMatrisAssign : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMatrisOperMultMatrisAssign() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 120, "testMatrisOperMultMatrisAssign" ) {}
 void runTest() { suite_MyTestSuite.testMatrisOperMultMatrisAssign(); }
} testDescription_suite_MyTestSuite_testMatrisOperMultMatrisAssign;

static class TestDescription_suite_MyTestSuite_testMatrisOperPlusScalar : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMatrisOperPlusScalar() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 132, "testMatrisOperPlusScalar" ) {}
 void runTest() { suite_MyTestSuite.testMatrisOperPlusScalar(); }
} testDescription_suite_MyTestSuite_testMatrisOperPlusScalar;

static class TestDescription_suite_MyTestSuite_testMatrisOperPlusMatrisChain : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMatrisOperPlusMatrisChain() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 138, "testMatrisOperPlusMatrisChain" ) {}
 void runTest() { suite_MyTestSuite.testMatrisOperPlusMatrisChain(); }
} testDescription_suite_MyTestSuite_testMatrisOperPlusMatrisChain;

static class TestDescription_suite_MyTestSuite_testMatrisOperPlusMatris : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMatrisOperPlusMatris() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 153, "testMatrisOperPlusMatris" ) {}
 void runTest() { suite_MyTestSuite.testMatrisOperPlusMatris(); }
} testDescription_suite_MyTestSuite_testMatrisOperPlusMatris;

static class TestDescription_suite_MyTestSuite_testMatrisOperMinusScalar : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMatrisOperMinusScalar() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 161, "testMatrisOperMinusScalar" ) {}
 void runTest() { suite_MyTestSuite.testMatrisOperMinusScalar(); }
} testDescription_suite_MyTestSuite_testMatrisOperMinusScalar;

static class TestDescription_suite_MyTestSuite_testMatrisOperMinusMatris : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMatrisOperMinusMatris() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 167, "testMatrisOperMinusMatris" ) {}
 void runTest() { suite_MyTestSuite.testMatrisOperMinusMatris(); }
} testDescription_suite_MyTestSuite_testMatrisOperMinusMatris;

static class TestDescription_suite_MyTestSuite_testMatrisOperMultScalar : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMatrisOperMultScalar() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 174, "testMatrisOperMultScalar" ) {}
 void runTest() { suite_MyTestSuite.testMatrisOperMultScalar(); }
} testDescription_suite_MyTestSuite_testMatrisOperMultScalar;

static class TestDescription_suite_MyTestSuite_testMatrisOperMultMatris : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMatrisOperMultMatris() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 180, "testMatrisOperMultMatris" ) {}
 void runTest() { suite_MyTestSuite.testMatrisOperMultMatris(); }
} testDescription_suite_MyTestSuite_testMatrisOperMultMatris;

static class TestDescription_suite_MyTestSuite_testMatrisOperFunc : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMatrisOperFunc() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 191, "testMatrisOperFunc" ) {}
 void runTest() { suite_MyTestSuite.testMatrisOperFunc(); }
} testDescription_suite_MyTestSuite_testMatrisOperFunc;

static class TestDescription_suite_MyTestSuite_testMatrisOperFuncConst : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMatrisOperFuncConst() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 197, "testMatrisOperFuncConst" ) {}
 void runTest() { suite_MyTestSuite.testMatrisOperFuncConst(); }
} testDescription_suite_MyTestSuite_testMatrisOperFuncConst;

static class TestDescription_suite_MyTestSuite_testMatrisOperEquals : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMatrisOperEquals() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 212, "testMatrisOperEquals" ) {}
 void runTest() { suite_MyTestSuite.testMatrisOperEquals(); }
} testDescription_suite_MyTestSuite_testMatrisOperEquals;

static class TestDescription_suite_MyTestSuite_testMatrisOperNotEquals : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMatrisOperNotEquals() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 218, "testMatrisOperNotEquals" ) {}
 void runTest() { suite_MyTestSuite.testMatrisOperNotEquals(); }
} testDescription_suite_MyTestSuite_testMatrisOperNotEquals;

static class TestDescription_suite_MyTestSuite_testMatrisRows : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMatrisRows() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 225, "testMatrisRows" ) {}
 void runTest() { suite_MyTestSuite.testMatrisRows(); }
} testDescription_suite_MyTestSuite_testMatrisRows;

static class TestDescription_suite_MyTestSuite_testMatrisCols : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMatrisCols() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 231, "testMatrisCols" ) {}
 void runTest() { suite_MyTestSuite.testMatrisCols(); }
} testDescription_suite_MyTestSuite_testMatrisCols;

static class TestDescription_suite_MyTestSuite_testMatrisReset : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMatrisReset() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 238, "testMatrisReset" ) {}
 void runTest() { suite_MyTestSuite.testMatrisReset(); }
} testDescription_suite_MyTestSuite_testMatrisReset;

static class TestDescription_suite_MyTestSuite_testMatrisIdentity : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMatrisIdentity() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 246, "testMatrisIdentity" ) {}
 void runTest() { suite_MyTestSuite.testMatrisIdentity(); }
} testDescription_suite_MyTestSuite_testMatrisIdentity;

static class TestDescription_suite_MyTestSuite_testMatrisInsert_row : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMatrisInsert_row() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 257, "testMatrisInsert_row" ) {}
 void runTest() { suite_MyTestSuite.testMatrisInsert_row(); }
} testDescription_suite_MyTestSuite_testMatrisInsert_row;

static class TestDescription_suite_MyTestSuite_testMatrisAppend_row : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMatrisAppend_row() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 286, "testMatrisAppend_row" ) {}
 void runTest() { suite_MyTestSuite.testMatrisAppend_row(); }
} testDescription_suite_MyTestSuite_testMatrisAppend_row;

static class TestDescription_suite_MyTestSuite_testMatrisRemove_row : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMatrisRemove_row() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 315, "testMatrisRemove_row" ) {}
 void runTest() { suite_MyTestSuite.testMatrisRemove_row(); }
} testDescription_suite_MyTestSuite_testMatrisRemove_row;

static class TestDescription_suite_MyTestSuite_testMatrisInsert_column : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMatrisInsert_column() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 338, "testMatrisInsert_column" ) {}
 void runTest() { suite_MyTestSuite.testMatrisInsert_column(); }
} testDescription_suite_MyTestSuite_testMatrisInsert_column;

static class TestDescription_suite_MyTestSuite_testMatrisAppend_column : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMatrisAppend_column() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 367, "testMatrisAppend_column" ) {}
 void runTest() { suite_MyTestSuite.testMatrisAppend_column(); }
} testDescription_suite_MyTestSuite_testMatrisAppend_column;

static class TestDescription_suite_MyTestSuite_testMatrisRemove_column : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMatrisRemove_column() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 396, "testMatrisRemove_column" ) {}
 void runTest() { suite_MyTestSuite.testMatrisRemove_column(); }
} testDescription_suite_MyTestSuite_testMatrisRemove_column;

static class TestDescription_suite_MyTestSuite_testMatrisBeginEnd : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMatrisBeginEnd() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 420, "testMatrisBeginEnd" ) {}
 void runTest() { suite_MyTestSuite.testMatrisBeginEnd(); }
} testDescription_suite_MyTestSuite_testMatrisBeginEnd;

static class TestDescription_suite_MyTestSuite_testMatrisInputOutput : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMatrisInputOutput() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 432, "testMatrisInputOutput" ) {}
 void runTest() { suite_MyTestSuite.testMatrisInputOutput(); }
} testDescription_suite_MyTestSuite_testMatrisInputOutput;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
