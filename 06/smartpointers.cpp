#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <functional>
#include <thread>

using namespace std;

struct A {
    int data;

};

void foo(unique_ptr<A> p) {
    cout << p->data << endl;
}

void foo2(shared_ptr<A> p) {
    cout << p->data << endl;
}

int main()
{
    unique_ptr<A> pa(new A {4});
    cout << pa -> data << endl;
    foo(move(pa));

    shared_ptr<A> sa(new A {5});
    cout << sa -> data << endl;
    foo2(sa);
    //foo2(move(sa));
    cout << sa << endl;

    //weak_ptr<A> wa(new A {5});
    weak_ptr<A> wa = sa;
    cout << wa.lock()->data << endl;
    return 0;
}