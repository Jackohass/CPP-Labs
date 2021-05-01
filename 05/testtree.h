#include<cxxtest/TestSuite.h>
#include"bintree.h"
#include<stdexcept>

using namespace std;

class MyTestSuite : public CxxTest::TestSuite 
{
public:
    void testInsert0( void )
    {
        Node* data = nullptr;
        insert(data,0,22);
        
        TS_ASSERT(data->key == 0);
        TS_ASSERT(data->data == 22);
        TS_ASSERT(data->left == nullptr);
        TS_ASSERT(data->right == nullptr);
    }
    void testInsert1( void )
    {
        Node* data = nullptr;
        insert(data,0,22);
        insert(data,1,22);
        
        Node* temp = data->right;
        TS_ASSERT(data->right != nullptr);
        TS_ASSERT(temp->key == 1);
        TS_ASSERT(temp->data == 22);
        TS_ASSERT(temp->left == nullptr);
        TS_ASSERT(temp->right == nullptr);
    }
    void testInsert1Overwrite( void )
    {
        Node* data = nullptr;
        insert(data,0,22);
        insert(data,1,22);
        insert(data,1,32);
        
        Node* temp = data->right;
        TS_ASSERT(data->right != nullptr);
        TS_ASSERT(temp->key == 1);
        TS_ASSERT(temp->data == 32);
        TS_ASSERT(temp->left == nullptr);
        TS_ASSERT(temp->right == nullptr);
    }
    void testInsertMore( void )
    {
        Node* data = nullptr;
        insert(data,0,22);
        insert(data,2,22);
        insert(data,-2,22);
        insert(data,1,22);
        insert(data,3,22);
        insert(data,-1,22);
        insert(data,-3,22);
        
        Node* temp = data->right->left;
        TS_ASSERT(data->right != nullptr);
        TS_ASSERT(temp->key == 1);
        TS_ASSERT(temp->data == 22);
        TS_ASSERT(temp->left == nullptr);
        TS_ASSERT(temp->right == nullptr);
    }

    void testFind0( void )
    {
        Node* data = nullptr;
        TS_ASSERT_THROWS(find(data, 0), out_of_range);
    }
    void testFindRoot( void )
    {
        Node* data = nullptr;
        insert(data,0,12);
        insert(data,2,22);
        insert(data,-2,32);
        insert(data,1,42);
        insert(data,3,52);
        insert(data,-1,62);
        insert(data,-3,72);

        TS_ASSERT(find(data,0) == 12);
    }
    void testFindMiddle( void )
    {
        Node* data = nullptr;
        insert(data,0,12);
        insert(data,2,22);
        insert(data,-2,32);
        insert(data,1,42);
        insert(data,3,52);
        insert(data,-1,62);
        insert(data,-3,72);

        TS_ASSERT(find(data,2) == 22);
    }
    void testFindLeaf( void )
    {
        Node* data = nullptr;
        insert(data,0,12);
        insert(data,2,22);
        insert(data,-2,32);
        insert(data,1,42);
        insert(data,3,52);
        insert(data,-1,62);
        insert(data,-3,72);

        TS_ASSERT(find(data,3) == 52);
    }
    void testFindNothing( void )
    {
        Node* data = nullptr;
        insert(data,0,12);
        insert(data,2,22);
        insert(data,-2,32);
        insert(data,1,42);
        insert(data,3,52);
        insert(data,-1,62);
        insert(data,-3,72);

        TS_ASSERT_THROWS(find(data, 32), out_of_range);
    }

private:

};