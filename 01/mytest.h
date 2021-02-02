#include <cxxtest/TestSuite.h>
#include "count_if_followed_by.h"

class MyTestSuite : public CxxTest::TestSuite 
{
public:
  void testCount_if_followed_by( void )
  {
    char const data[4] = {'a','b','a','b'};
    int  const result  = count_if_followed_by (data, 3, 'b', 'a');
    
    TS_ASSERT( result == 1 );
  }

  void test2Count_if_followed_by( void )
  {
    char const data[4] = {'a','b','a','b'};
    int  const result  = count_if_followed_by (data, 3, 'a', 'b');
    
    TS_ASSERT( result == 1 );
  }

  void testOCount_if_followed_by( void )
  {
    char const data[4] = {'G','G','X','G'};
    int  const result  = count_if_followed_by (data, 3, 'X', 'G');
    
    TS_ASSERT( result == 0 );
  }

  void test4Count_if_followed_by( void )
  {
    char const data[4] = {'x','y','x','y'};
    int  const result  = count_if_followed_by (data, 4, 'x', 'y');
    
    TS_ASSERT( result == 2 );
  }

  void test0Count_if_followed_by( void )
  {
    char const data[0] = {};
    int  const result  = count_if_followed_by (data, 0, ' ', ' ');
    
    TS_ASSERT( result == 0 );
  }

  void test1Count_if_followed_by( void )
  {
    char const data[1] = {'a'};
    int  const result  = count_if_followed_by (data, 1, 'a', '\0');
    
    TS_ASSERT( result == 0 );
  }
};