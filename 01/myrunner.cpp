/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
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
#include "mytest.h"

static MyTestSuite suite_MyTestSuite;

static CxxTest::List Tests_MyTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_MyTestSuite( "mytest.h", 4, "MyTestSuite", suite_MyTestSuite, Tests_MyTestSuite );

static class TestDescription_suite_MyTestSuite_testCount_if_followed_by : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testCount_if_followed_by() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 7, "testCount_if_followed_by" ) {}
 void runTest() { suite_MyTestSuite.testCount_if_followed_by(); }
} testDescription_suite_MyTestSuite_testCount_if_followed_by;

static class TestDescription_suite_MyTestSuite_test2Count_if_followed_by : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test2Count_if_followed_by() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 15, "test2Count_if_followed_by" ) {}
 void runTest() { suite_MyTestSuite.test2Count_if_followed_by(); }
} testDescription_suite_MyTestSuite_test2Count_if_followed_by;

static class TestDescription_suite_MyTestSuite_testOCount_if_followed_by : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testOCount_if_followed_by() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 23, "testOCount_if_followed_by" ) {}
 void runTest() { suite_MyTestSuite.testOCount_if_followed_by(); }
} testDescription_suite_MyTestSuite_testOCount_if_followed_by;

static class TestDescription_suite_MyTestSuite_test4Count_if_followed_by : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test4Count_if_followed_by() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 31, "test4Count_if_followed_by" ) {}
 void runTest() { suite_MyTestSuite.test4Count_if_followed_by(); }
} testDescription_suite_MyTestSuite_test4Count_if_followed_by;

static class TestDescription_suite_MyTestSuite_test0Count_if_followed_by : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test0Count_if_followed_by() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 39, "test0Count_if_followed_by" ) {}
 void runTest() { suite_MyTestSuite.test0Count_if_followed_by(); }
} testDescription_suite_MyTestSuite_test0Count_if_followed_by;

static class TestDescription_suite_MyTestSuite_test1Count_if_followed_by : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test1Count_if_followed_by() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 47, "test1Count_if_followed_by" ) {}
 void runTest() { suite_MyTestSuite.test1Count_if_followed_by(); }
} testDescription_suite_MyTestSuite_test1Count_if_followed_by;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
