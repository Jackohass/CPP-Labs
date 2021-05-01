#include<cxxtest/TestSuite.h>
#include"bintree.h"
#include<stdexcept>
#include<iostream>

using namespace std;

class MyTestSuite : public CxxTest::TestSuite 
{
public:
    void testDelete0( void )
    {
        Node* data = nullptr;
        insert(data,0,12);
        delete_tree(data);

        TS_ASSERT(data == nullptr);
    }
    void testDelete1( void )
    {
        Node* data = nullptr;
        delete_tree(data);

        TS_ASSERT(data == nullptr);
    }
    void testDeleteRoot( void )
    {
        Node* data = nullptr;
        insert(data,0,12);
        insert(data,2,22);
        insert(data,-2,32);
        insert(data,1,42);
        insert(data,3,52);
        insert(data,-1,62);
        insert(data,-3,72);
        
        delete_tree(data);

        TS_ASSERT(data == nullptr);
    }
    void testDeleteMiddle( void )
    {
        Node* data = nullptr;
        insert(data,0,12);
        insert(data,2,22);
        insert(data,-2,32);
        insert(data,1,42);
        insert(data,3,52);
        insert(data,-1,62);
        insert(data,-3,72);

        delete_tree(data->right);

        TS_ASSERT(data != nullptr);
        TS_ASSERT(data->right == nullptr);
        delete_tree(data);
    }
    void testDeleteLeaf( void )
    {
        Node* data = nullptr;
        insert(data,0,12);
        insert(data,2,22);
        insert(data,-2,32);
        insert(data,1,42);
        insert(data,3,52);
        insert(data,-1,62);
        insert(data,-3,72);

        delete_tree(data->right->left);

        TS_ASSERT(data != nullptr);
        TS_ASSERT(data->right != nullptr);
        TS_ASSERT(data->right->left == nullptr);
        delete_tree(data);
    }

    void testInsert0( void )
    {
        Node* data = nullptr;
        insert(data,0,22);
        
        TS_ASSERT(data->key == 0);
        TS_ASSERT(data->data == 22);
        TS_ASSERT(data->left == nullptr);
        TS_ASSERT(data->right == nullptr);
        delete_tree(data);
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
        delete_tree(data);
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
        delete_tree(data);
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
        delete_tree(data);
    }

    void testFind0( void )
    {
        Node* data = nullptr;
        TS_ASSERT_THROWS(find(data, 0), out_of_range);
    }
    void testFind1( void )
    {
        Node* data = nullptr;
        insert(data,0,12);

        TS_ASSERT(find(data,0) == 12);
        delete_tree(data);
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
        delete_tree(data);
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
        delete_tree(data);
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

        TS_ASSERT(find(data,1) == 42);
        delete_tree(data);
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
        delete_tree(data);
    }

    void testEdit0( void )
    {
        Node* data = nullptr;
        TS_ASSERT_THROWS(edit(data, 0), out_of_range);
    }
    void testEdit1( void )
    {
        Node* data = nullptr;
        insert(data,0,12);

        edit(data,0) = 2;

        TS_ASSERT(data->data == 2);
        delete_tree(data);
    }
    void testEditRoot( void )
    {
        Node* data = nullptr;
        insert(data,0,12);
        insert(data,2,22);
        insert(data,-2,32);
        insert(data,1,42);
        insert(data,3,52);
        insert(data,-1,62);
        insert(data,-3,72);
        
        edit(data,0) = 2;

        TS_ASSERT(data->data == 2);
        delete_tree(data);
    }
    void testEditMiddle( void )
    {
        Node* data = nullptr;
        insert(data,0,12);
        insert(data,2,22);
        insert(data,-2,32);
        insert(data,1,42);
        insert(data,3,52);
        insert(data,-1,62);
        insert(data,-3,72);

        edit(data,2) = 33;

        TS_ASSERT(find(data,2) == 33);
        delete_tree(data);
    }
    void testEditLeaf( void )
    {
        Node* data = nullptr;
        insert(data,0,12);
        insert(data,2,22);
        insert(data,-2,32);
        insert(data,1,42);
        insert(data,3,52);
        insert(data,-1,62);
        insert(data,-3,72);

        edit(data,1) = 55;

        TS_ASSERT(find(data,1) == 55);
        delete_tree(data);
    }
    void testEditNothing( void )
    {
        Node* data = nullptr;
        insert(data,0,12);
        insert(data,2,22);
        insert(data,-2,32);
        insert(data,1,42);
        insert(data,3,52);
        insert(data,-1,62);
        insert(data,-3,72);

        TS_ASSERT_THROWS(edit(data, 32), out_of_range);
        delete_tree(data);
    }

    void testMaxHeight0( void )
    {
        Node* data = nullptr;
        TS_ASSERT(max_height(data) == -1);
    }
    void testMaxHeight1( void )
    {
        Node* data = nullptr;
        insert(data,0,12);

        TS_ASSERT(max_height(data) == 0);
        delete_tree(data);
    }
    void testMaxHeightRoot( void )
    {
        Node* data = nullptr;
        insert(data,0,12);
        insert(data,-4,22);
        insert(data,-2,32);
        insert(data,-5,42);
        insert(data,8,52);
        insert(data,4,62);
        insert(data,2,62);
        insert(data,5,62);
        insert(data,1,62);

        TS_ASSERT(max_height(data) == 4);
        delete_tree(data);
    }
    void testMaxHeightMiddle( void )
    {
        Node* data = nullptr;
        insert(data,0,12);
        insert(data,-4,22);
        insert(data,-2,32);
        insert(data,-5,42);
        insert(data,8,52);
        insert(data,4,62);
        insert(data,2,62);
        insert(data,5,62);
        insert(data,1,62);

        TS_ASSERT(max_height(data->right) == 3);
        delete_tree(data);
    }
    void testMaxHeightLeaf( void )
    {
        Node* data = nullptr;
        insert(data,0,12);
        insert(data,-4,22);
        insert(data,-2,32);
        insert(data,-5,42);
        insert(data,8,52);
        insert(data,4,62);
        insert(data,2,62);
        insert(data,5,62);
        insert(data,1,62);

        TS_ASSERT(max_height(data->left->right) == 0);
        delete_tree(data);
    }

    void testMinHeight0( void )
    {
        Node* data = nullptr;
        TS_ASSERT(min_height(data) == -1);
    }
    void testMinHeight1( void )
    {
        Node* data = nullptr;
        insert(data,0,12);

        TS_ASSERT(min_height(data) == 0);
        delete_tree(data);
    }
    void testMinHeightRoot( void )
    {
        Node* data = nullptr;
        insert(data,0,12);
        insert(data,-4,22);
        insert(data,-2,32);
        insert(data,-5,42);
        insert(data,8,52);
        insert(data,4,62);
        insert(data,2,62);
        insert(data,5,62);
        insert(data,1,62);
        TS_ASSERT(min_height(data) == 1);
        delete_tree(data);
    }
    void testMinHeightMiddle( void )
    {
        Node* data = nullptr;
        insert(data,0,12);
        insert(data,-4,22);
        insert(data,-2,32);
        insert(data,-5,42);
        insert(data,8,52);
        insert(data,4,62);
        insert(data,2,62);
        insert(data,5,62);
        insert(data,1,62);
        TS_ASSERT(min_height(data->right) == 0);
        delete_tree(data);
    }
    void testMinHeightLeaf( void )
    {
        Node* data = nullptr;
        insert(data,0,12);
        insert(data,-4,22);
        insert(data,-2,32);
        insert(data,-5,42);
        insert(data,8,52);
        insert(data,4,62);
        insert(data,2,62);
        insert(data,5,62);
        insert(data,1,62);

        TS_ASSERT(min_height(data->left->right) == 0);
        delete_tree(data);
    }

private:
    #include<string>
    void printTree(Node* p)
    {
        if(p == nullptr) return;
        cout << p->key << "->" << (p->left == nullptr ? "nullptr" : to_string(p->left->key)) << endl;
        cout << p->key << "->" <<(p->right == nullptr ? "nullptr" : to_string(p->right->key)) << endl;
        printTree(p->left);
        printTree(p->right);
    }
};