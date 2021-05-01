#include"bintree.h"

void insert(Node * & p, int key, double to_be_inserted)
{
    if (p == nullptr) p = new Node{key, to_be_inserted, nullptr, nullptr};
    else if (key == p->key) p->data = to_be_inserted;
    else if (key < p->key) insert(p->left, key, to_be_inserted);
    else insert(p->right, key, to_be_inserted);
}
void remove(Node * & p, const int & key)
{
    
}
const double & find(Node * p, const int & to_be_found)
{
    
}
double & edit(Node * p, const int & to_be_changed)
{
    
}
void delete_tree(Node * & p)
{
    if(p == nullptr) return;
    delete_tree(p->left);
    delete_tree(p->right);
    delete p;
}

unsigned int max_height(Node * p)
{
    
}
unsigned int min_height(Node * p)
{
    
}
unsigned int size(Node * p)
{
    
}
bool is_balanced(Node * p)
{
    
}