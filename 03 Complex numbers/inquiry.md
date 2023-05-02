# Inquiry

Write your answers below and include the questions. Do copy relevant code to your answers so that both questions and answers are in context 

## Answers
#### What did you learn from this assignment?
I learnt about constexpr and how to create makefiles. I also learn about literals

#### What was the harderst part (or parts) in this assignment?
I think the hardest part was making a makefile.
I also felt that I wasn't 100% sure what was expected for me to do for all functions:
* Should I use constexpr as much as possible?
* Should I make as many as possible functions const?

#### Which of your class methods or non member functions returns a copy?
All my arithmetic operation methods and the literals.
Also my assign operation.

#### Which of your class methods or non member functions returns a reference?
The input & output operations, and also the lesser than operation.

#### How many tests do you need at minimum to test the _abs_ function?
I wrote 12 tests, but I think you need atleasts tests for these cases:
* Float numbers
* Integer numbers
* When there is only real numbers
* When there is only imaginary numbers
* Both imaginary and float numbers.
So atleast 5 tests.

#### Describe and motivate how your implementation of operator= works
The i assign the value of the Complex being called from and assign its value to be same as the values of the Complex that is passed.
Then I send a copy of the current Complex, so the operator= can be chained. I, however, do not chain the +=, -=, etc.

#### What constructors/functions are called when writing the statement Complex k = 3 + 5_i;
`operator""_i(unsigned long long int scalar)`
`Complex::Complex(double real)`
`operator+(const Complex& leftCmplx, const Complex& rightCmplx)`
`Complex::Complex(const Complex &rhs)`

#### Describe and motivate how your implementation of operator+= -= /= *= = works with regards to return value
All of these operations, except, do not return any value and therefore can't be chained.
I chose for those to not return as I felt that as a designer it would make unreadable code.
Now it is of course up to each programmer to make their own design choices, but I decided that I didn't like it at all and therefore didn't want to implement it.
And mathematically speaking it doesn't feel very sound that you say 2 values are the same a value except that you add a value to it.
I did make = chain able as in math you can say multiple values are the same.

#### What is the rule of three in C++. Look it up in a C++ book or on the web.
If you need to define a destructor, a copy constructor or a copy assignment operator, it almost certainly requires all three.

#### With regards to the rule of three, do you need to explicitly define and implement the copy-constructor in this assignment?
No I do not need to explicitly define it in this assignment. As all it does is assign one Complex variables to be the same as the other one, a shallow copy.
But a shallow copy is all we need.

#### The literal _i_ has an underscore before it. Why is that? Look it up in the [c++11 draft](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2012/n3376.pdf) section 17.6.4.3.5 and explain. Has there been any changes regarding this matter in the [new c++17 draft](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/n4659.pdf)
Because in c++11 literals that don't start with an underscore is reserved for future c++ standards.
In the c++17 standard they are still reserved for the same reason.
