#include"complex.h"
#include<stdio.h>
#include<iostream>

using namespace std;

void printComplex(Complex c)
{
    printf("%f + %fi\n", c.real(), c.imag());
}

int main()
{
    // Complex c = 1+5_i;
    // Complex x;
    // Complex x2 = 5;
    // Complex y(6, 2);
    // Complex z = x + y;
    // Complex k = 3 + 5_i;
    // k -= 5 + 1_i * Complex(5, 3);
    // printComplex(z);
    // std::cout << Complex(6, 6) / 6 << std::endl;
    // printComplex(c);
    // printComplex(k);
    // Complex s0 = 3+3_i;
    // Complex s1 = s0 - 2;
    // printf("s1 v1: ");
    // printComplex(s1);
    // s1 = 6 - s0;
    // printf("s1 v2: ");
    // printComplex(s1);
    // if(x2 == 5) printf("yes x2 = 5\n");
    // if(5 == x2) printf("yes x2 = 5\n");
    // printf("ayoooo\n");
    // //printComplex(Complex(6,6)/6);
    // Complex data0(2,4);
    // Complex data1(4,8);
    // data1 /= data0;
    // printComplex(data1);
    Complex k = 3 + 5_i;
    printComplex(k);
    return 0;
}