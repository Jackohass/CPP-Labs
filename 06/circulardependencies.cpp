#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <functional>
#include <thread>

using namespace std;

struct BhasA;

struct AhasB {
    AhasB(shared_ptr<BhasA> b) : m_b(b)  {
        resource = new int[4];
    };

    weak_ptr<BhasA> m_b;
    int * resource;

    ~AhasB() {delete [] resource;}
    AhasB(const AhasB &) = delete;
    void operator=(const AhasB &) = delete;
};

struct BhasA {
    BhasA() {resource = new int[4];};

    shared_ptr<AhasB> m_a;
    int * resource;

    ~BhasA() {delete [] resource;}
    BhasA(const BhasA &) = delete;
    void operator=(const BhasA &) = delete;
};

struct B {
    B() { b = new int[4]; }

    int * b;
    ~B() { delete [] b; }
    B(const B &) = delete;
    void operator= (const B & ) = delete;
};

int main()
{
    shared_ptr<BhasA> bptr(new BhasA);
    shared_ptr<AhasB> aptr(new AhasB(bptr));
    bptr->m_a=aptr;

    unique_ptr<B, function<void(B*)>> pb1(new B[2], [](B* p)
    {
        delete[] p;
    });
    return 0;
}