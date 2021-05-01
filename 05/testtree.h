#include<cxxtest/TestSuite.h>
#include"bintree.h"
#include<fstream>

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

private:

};