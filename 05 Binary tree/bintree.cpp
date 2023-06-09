#include"bintree.h"
#include<stdexcept>
#include<algorithm>
#include<cmath>

using namespace std;

void insert(Node * & p, int key, double to_be_inserted)
{ 
    if (p == nullptr) p = new Node{key, to_be_inserted, nullptr, nullptr};
    else if (key == p->key) p->data = to_be_inserted;
    else if (key < p->key) insert(p->left, key, to_be_inserted);
    else insert(p->right, key, to_be_inserted);
}
Node * getMaxNode(Node * p)
{
    Node * current = p;
    while(current->left != nullptr) current = current->left;
    return current;
}
Node * & getNode(Node * & p, Node * & prev, const int & key)
{
    if (p == nullptr) throw out_of_range("Can't find key");
    else if (key == p->key) return p;
    else if (key < p->key)
    {
        prev = p;
        getNode(p->left, prev, key);
    }
    else
    {
        prev = p;
        getNode(p->right, prev, key);
    }
}
#include<iostream>
void remove(Node * & p, const int & key)
{
    Node * parent;
    Node * & affectedNode = getNode(p, parent, key);
    if(affectedNode->left != nullptr && affectedNode->right != nullptr)
    {
        Node * moveNode = getMaxNode(affectedNode->right);  
        int tempData = moveNode->data;
        int tempKey = moveNode->key;
        remove(affectedNode, moveNode->key);
        affectedNode->data = tempData;
        affectedNode->key = tempKey;
    }
    else if(affectedNode->left != nullptr)
    {
        if(parent->left == affectedNode)
        {
            Node * temp = affectedNode->left;
            affectedNode->left = nullptr;
            delete_tree(affectedNode);
            parent->left = temp;
        }
        else
        {
            Node * temp = affectedNode->left;
            affectedNode->left = nullptr;
            delete_tree(affectedNode);
            parent->right = temp;
        }
    }
    else if(affectedNode->right != nullptr)
    {
        if(parent->left == affectedNode)
        {
            Node * temp = affectedNode->right;
            affectedNode->right = nullptr;
            delete_tree(affectedNode);
            parent->left = temp;
        }
        else
        {
            Node * temp = affectedNode->right;
            affectedNode->right = nullptr;
            delete_tree(affectedNode);
            parent->right = temp;
        }
    }
    else delete_tree(affectedNode);
}
const double & find(Node * p, const int & to_be_found)
{
    if(p == nullptr) throw out_of_range("Can't find key");
    if(p->key == to_be_found) return p->data;
    if(to_be_found < p->key) return find(p->left, to_be_found);
    if(to_be_found > p->key) return find(p->right, to_be_found);
}
double & edit(Node * p, const int & to_be_changed)
{
    if(p == nullptr) throw out_of_range("Can't find key");
    if(p->key == to_be_changed) return p->data;
    if(to_be_changed < p->key) return edit(p->left, to_be_changed);
    if(to_be_changed > p->key) return edit(p->right, to_be_changed);
}
void delete_tree(Node * & p)
{
    if(p == nullptr) return;
    delete_tree(p->left);
    delete_tree(p->right);
    delete p;
    p = nullptr;
}
unsigned int recMax_height(Node * p)
{
    if(p == nullptr) return 0;
    return max(recMax_height(p->left), recMax_height(p->right))+1;
}
unsigned int max_height(Node * p)
{
    if(p == nullptr) return -1;
    return max(recMax_height(p->left), recMax_height(p->right));
}
unsigned int recMin_height(Node * p)
{
    if(p == nullptr) return 0;
    return min(recMin_height(p->left), recMin_height(p->right))+1;
}
unsigned int min_height(Node * p)
{
    if(p == nullptr) return -1;
    unsigned int lMin = recMin_height(p->left);
    unsigned int rMin = recMin_height(p->right);
    if(lMin == 0) return rMin;
    if(rMin == 0) return lMin;
    return min(lMin, rMin);
}
unsigned int size(Node * p)
{
    if(p == nullptr) return 0;
    return size(p->left) + size(p->right) + 1;
}
bool recBalance(Node * p, unsigned int& height) {
    if (p == NULL) {
        height = 0;
        return true;
    }

    unsigned int leftH = 0, rightH = 0;
    bool leftBalanced = recBalance(p->left, leftH);
    bool rightBalanced = recBalance(p->right, rightH);
    height = max(leftH, rightH) + 1;

    return abs(((int)leftH - (int)rightH)) < 2 && leftBalanced && rightBalanced;
}
bool is_balanced(Node * p)
{
    unsigned int height = 0;
    return recBalance(p, height);
}