# Inquiry

Write your answers below and include the questions. Do copy relevant code to your answers so that both questions and answers are in context 

## Answers
### Matrix
#### What did you learn from this assignment?
I learnt about:
* const functions
* operator overloading
* move assignment
* L-values and R-values
* Explicit
* Implementation of a class template.
* Throwing errors
* Assertions
* Adresses

#### What was hardest to implement in this assignment?
The things that I spent the most time implementing was the operator overloadings, particularly the ones that assign.

#### How many methods/functions have you implemented?
Including constructors, it is 46 methods and functions.

#### How many methods/functions have you tested?
I have tested every public method/function, even the constructors. I have 39 tests in total.

#### Describe and motivate how your implementation of operator= works
I have 2 versions of the operator=. One for copy and the other for move.
Both versions will do nothing if it is trying to assign itself to itself and will delete the old array.

The copy version makes a new inner array and then copies each element into this new inner array.
The this array and its size is assigned to the matrix being assigned to.

The move version just assigns the attributes of the matrix being moved to the matrix being moved to.
We then assign all the attributes of the matrix being moved, except the array which we assign to nullptr, we set to zero.

#### When do you need to resize in your code?
I need resize whenever the matrix changes. So that means that I need to resize in the functions:
* insert_row
* append_row
* remove_row
* insert_column
* append_column
* remove_column
Technically it also resizes whenever it gets assigned a new matrix:
* copy operators
* move operators
* addition assignment
* subtractions assignment
* multiplication assignment

#### Why do you need to implement a const-version of the accessor operator?
We need it if we wanna access elements from a const Matrix.

#### Is it possible to call std::sort() to sort your matrix using begin() and end()?
Yes, it will sort row-wise.

#### What other kind of iterators, besides random access iterators, are there in C++? 
There are input/output iterators, forward iterators and bidirectional iterators.
