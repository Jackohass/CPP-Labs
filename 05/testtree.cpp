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
CxxTest::StaticSuiteDescription suiteDescription_MyTestSuite( "testtree.h", 7, "MyTestSuite", suite_MyTestSuite, Tests_MyTestSuite );

static class TestDescription_suite_MyTestSuite_testInsert0 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testInsert0() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 10, "testInsert0" ) {}
 void runTest() { suite_MyTestSuite.testInsert0(); }
} testDescription_suite_MyTestSuite_testInsert0;

static class TestDescription_suite_MyTestSuite_testInsert1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testInsert1() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 20, "testInsert1" ) {}
 void runTest() { suite_MyTestSuite.testInsert1(); }
} testDescription_suite_MyTestSuite_testInsert1;

static class TestDescription_suite_MyTestSuite_testInsert1Overwrite : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testInsert1Overwrite() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 33, "testInsert1Overwrite" ) {}
 void runTest() { suite_MyTestSuite.testInsert1Overwrite(); }
} testDescription_suite_MyTestSuite_testInsert1Overwrite;

static class TestDescription_suite_MyTestSuite_testInsertMore : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testInsertMore() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 47, "testInsertMore" ) {}
 void runTest() { suite_MyTestSuite.testInsertMore(); }
} testDescription_suite_MyTestSuite_testInsertMore;

static class TestDescription_suite_MyTestSuite_testFind0 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testFind0() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 66, "testFind0" ) {}
 void runTest() { suite_MyTestSuite.testFind0(); }
} testDescription_suite_MyTestSuite_testFind0;

static class TestDescription_suite_MyTestSuite_testFindRoot : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testFindRoot() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 71, "testFindRoot" ) {}
 void runTest() { suite_MyTestSuite.testFindRoot(); }
} testDescription_suite_MyTestSuite_testFindRoot;

static class TestDescription_suite_MyTestSuite_testFindMiddle : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testFindMiddle() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 84, "testFindMiddle" ) {}
 void runTest() { suite_MyTestSuite.testFindMiddle(); }
} testDescription_suite_MyTestSuite_testFindMiddle;

static class TestDescription_suite_MyTestSuite_testFindLeaf : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testFindLeaf() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 97, "testFindLeaf" ) {}
 void runTest() { suite_MyTestSuite.testFindLeaf(); }
} testDescription_suite_MyTestSuite_testFindLeaf;

static class TestDescription_suite_MyTestSuite_testFindNothing : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testFindNothing() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 110, "testFindNothing" ) {}
 void runTest() { suite_MyTestSuite.testFindNothing(); }
} testDescription_suite_MyTestSuite_testFindNothing;

static class TestDescription_suite_MyTestSuite_testEdit0 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testEdit0() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 124, "testEdit0" ) {}
 void runTest() { suite_MyTestSuite.testEdit0(); }
} testDescription_suite_MyTestSuite_testEdit0;

static class TestDescription_suite_MyTestSuite_testEditRoot : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testEditRoot() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 129, "testEditRoot" ) {}
 void runTest() { suite_MyTestSuite.testEditRoot(); }
} testDescription_suite_MyTestSuite_testEditRoot;

static class TestDescription_suite_MyTestSuite_testEditMiddle : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testEditMiddle() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 144, "testEditMiddle" ) {}
 void runTest() { suite_MyTestSuite.testEditMiddle(); }
} testDescription_suite_MyTestSuite_testEditMiddle;

static class TestDescription_suite_MyTestSuite_testEditLeaf : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testEditLeaf() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 159, "testEditLeaf" ) {}
 void runTest() { suite_MyTestSuite.testEditLeaf(); }
} testDescription_suite_MyTestSuite_testEditLeaf;

static class TestDescription_suite_MyTestSuite_testEditNothing : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testEditNothing() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 174, "testEditNothing" ) {}
 void runTest() { suite_MyTestSuite.testEditNothing(); }
} testDescription_suite_MyTestSuite_testEditNothing;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
