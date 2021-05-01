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
#include "testtree.h"

static MyTestSuite suite_MyTestSuite;

static CxxTest::List Tests_MyTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_MyTestSuite( "testtree.h", 8, "MyTestSuite", suite_MyTestSuite, Tests_MyTestSuite );

static class TestDescription_suite_MyTestSuite_testDelete0 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testDelete0() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 11, "testDelete0" ) {}
 void runTest() { suite_MyTestSuite.testDelete0(); }
} testDescription_suite_MyTestSuite_testDelete0;

static class TestDescription_suite_MyTestSuite_testDelete1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testDelete1() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 19, "testDelete1" ) {}
 void runTest() { suite_MyTestSuite.testDelete1(); }
} testDescription_suite_MyTestSuite_testDelete1;

static class TestDescription_suite_MyTestSuite_testDeleteRoot : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testDeleteRoot() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 26, "testDeleteRoot" ) {}
 void runTest() { suite_MyTestSuite.testDeleteRoot(); }
} testDescription_suite_MyTestSuite_testDeleteRoot;

static class TestDescription_suite_MyTestSuite_testDeleteMiddle : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testDeleteMiddle() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 41, "testDeleteMiddle" ) {}
 void runTest() { suite_MyTestSuite.testDeleteMiddle(); }
} testDescription_suite_MyTestSuite_testDeleteMiddle;

static class TestDescription_suite_MyTestSuite_testDeleteLeaf : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testDeleteLeaf() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 58, "testDeleteLeaf" ) {}
 void runTest() { suite_MyTestSuite.testDeleteLeaf(); }
} testDescription_suite_MyTestSuite_testDeleteLeaf;

static class TestDescription_suite_MyTestSuite_testInsert0 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testInsert0() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 77, "testInsert0" ) {}
 void runTest() { suite_MyTestSuite.testInsert0(); }
} testDescription_suite_MyTestSuite_testInsert0;

static class TestDescription_suite_MyTestSuite_testInsert1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testInsert1() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 88, "testInsert1" ) {}
 void runTest() { suite_MyTestSuite.testInsert1(); }
} testDescription_suite_MyTestSuite_testInsert1;

static class TestDescription_suite_MyTestSuite_testInsert1Overwrite : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testInsert1Overwrite() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 102, "testInsert1Overwrite" ) {}
 void runTest() { suite_MyTestSuite.testInsert1Overwrite(); }
} testDescription_suite_MyTestSuite_testInsert1Overwrite;

static class TestDescription_suite_MyTestSuite_testInsertMore : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testInsertMore() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 117, "testInsertMore" ) {}
 void runTest() { suite_MyTestSuite.testInsertMore(); }
} testDescription_suite_MyTestSuite_testInsertMore;

static class TestDescription_suite_MyTestSuite_testFind0 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testFind0() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 137, "testFind0" ) {}
 void runTest() { suite_MyTestSuite.testFind0(); }
} testDescription_suite_MyTestSuite_testFind0;

static class TestDescription_suite_MyTestSuite_testFind1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testFind1() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 142, "testFind1" ) {}
 void runTest() { suite_MyTestSuite.testFind1(); }
} testDescription_suite_MyTestSuite_testFind1;

static class TestDescription_suite_MyTestSuite_testFindRoot : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testFindRoot() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 150, "testFindRoot" ) {}
 void runTest() { suite_MyTestSuite.testFindRoot(); }
} testDescription_suite_MyTestSuite_testFindRoot;

static class TestDescription_suite_MyTestSuite_testFindMiddle : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testFindMiddle() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 164, "testFindMiddle" ) {}
 void runTest() { suite_MyTestSuite.testFindMiddle(); }
} testDescription_suite_MyTestSuite_testFindMiddle;

static class TestDescription_suite_MyTestSuite_testFindLeaf : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testFindLeaf() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 178, "testFindLeaf" ) {}
 void runTest() { suite_MyTestSuite.testFindLeaf(); }
} testDescription_suite_MyTestSuite_testFindLeaf;

static class TestDescription_suite_MyTestSuite_testFindNothing : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testFindNothing() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 192, "testFindNothing" ) {}
 void runTest() { suite_MyTestSuite.testFindNothing(); }
} testDescription_suite_MyTestSuite_testFindNothing;

static class TestDescription_suite_MyTestSuite_testEdit0 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testEdit0() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 207, "testEdit0" ) {}
 void runTest() { suite_MyTestSuite.testEdit0(); }
} testDescription_suite_MyTestSuite_testEdit0;

static class TestDescription_suite_MyTestSuite_testEdit1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testEdit1() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 212, "testEdit1" ) {}
 void runTest() { suite_MyTestSuite.testEdit1(); }
} testDescription_suite_MyTestSuite_testEdit1;

static class TestDescription_suite_MyTestSuite_testEditRoot : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testEditRoot() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 222, "testEditRoot" ) {}
 void runTest() { suite_MyTestSuite.testEditRoot(); }
} testDescription_suite_MyTestSuite_testEditRoot;

static class TestDescription_suite_MyTestSuite_testEditMiddle : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testEditMiddle() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 238, "testEditMiddle" ) {}
 void runTest() { suite_MyTestSuite.testEditMiddle(); }
} testDescription_suite_MyTestSuite_testEditMiddle;

static class TestDescription_suite_MyTestSuite_testEditLeaf : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testEditLeaf() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 254, "testEditLeaf" ) {}
 void runTest() { suite_MyTestSuite.testEditLeaf(); }
} testDescription_suite_MyTestSuite_testEditLeaf;

static class TestDescription_suite_MyTestSuite_testEditNothing : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testEditNothing() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 270, "testEditNothing" ) {}
 void runTest() { suite_MyTestSuite.testEditNothing(); }
} testDescription_suite_MyTestSuite_testEditNothing;

static class TestDescription_suite_MyTestSuite_testMaxHeight0 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMaxHeight0() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 285, "testMaxHeight0" ) {}
 void runTest() { suite_MyTestSuite.testMaxHeight0(); }
} testDescription_suite_MyTestSuite_testMaxHeight0;

static class TestDescription_suite_MyTestSuite_testMaxHeight1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMaxHeight1() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 290, "testMaxHeight1" ) {}
 void runTest() { suite_MyTestSuite.testMaxHeight1(); }
} testDescription_suite_MyTestSuite_testMaxHeight1;

static class TestDescription_suite_MyTestSuite_testMaxHeightRoot : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMaxHeightRoot() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 298, "testMaxHeightRoot" ) {}
 void runTest() { suite_MyTestSuite.testMaxHeightRoot(); }
} testDescription_suite_MyTestSuite_testMaxHeightRoot;

static class TestDescription_suite_MyTestSuite_testMaxHeightMiddle : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMaxHeightMiddle() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 314, "testMaxHeightMiddle" ) {}
 void runTest() { suite_MyTestSuite.testMaxHeightMiddle(); }
} testDescription_suite_MyTestSuite_testMaxHeightMiddle;

static class TestDescription_suite_MyTestSuite_testMaxHeightLeaf : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMaxHeightLeaf() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 330, "testMaxHeightLeaf" ) {}
 void runTest() { suite_MyTestSuite.testMaxHeightLeaf(); }
} testDescription_suite_MyTestSuite_testMaxHeightLeaf;

static class TestDescription_suite_MyTestSuite_testMinHeight0 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMinHeight0() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 347, "testMinHeight0" ) {}
 void runTest() { suite_MyTestSuite.testMinHeight0(); }
} testDescription_suite_MyTestSuite_testMinHeight0;

static class TestDescription_suite_MyTestSuite_testMinHeight1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMinHeight1() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 352, "testMinHeight1" ) {}
 void runTest() { suite_MyTestSuite.testMinHeight1(); }
} testDescription_suite_MyTestSuite_testMinHeight1;

static class TestDescription_suite_MyTestSuite_testMinHeightRoot : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMinHeightRoot() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 360, "testMinHeightRoot" ) {}
 void runTest() { suite_MyTestSuite.testMinHeightRoot(); }
} testDescription_suite_MyTestSuite_testMinHeightRoot;

static class TestDescription_suite_MyTestSuite_testMinHeightMiddle : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMinHeightMiddle() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 375, "testMinHeightMiddle" ) {}
 void runTest() { suite_MyTestSuite.testMinHeightMiddle(); }
} testDescription_suite_MyTestSuite_testMinHeightMiddle;

static class TestDescription_suite_MyTestSuite_testMinHeightLeaf : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMinHeightLeaf() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 390, "testMinHeightLeaf" ) {}
 void runTest() { suite_MyTestSuite.testMinHeightLeaf(); }
} testDescription_suite_MyTestSuite_testMinHeightLeaf;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
