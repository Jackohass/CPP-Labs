## Questions to answer
#### What did you learn from this assignment?
I learnt about shared pointers and how virtual classes work.
I also learnt about protected visibility, inheritance and especially about the diamond of death.

#### What was most difficult to do in this assignment?
It was creating the AI and make it so it doesn't crash. Most of my problems came from me making typos and misunderstanding the documentation of string.compare().
However, I did have a bit of problems with diamond of death.
One of those problems was that it didn't set the all the x's & y's in the queen class to be correct and only set one of them.
I solved this by creating a virtual class that would change the x & y that ChessPiece had a simple implementation of.
But Queen overrides it with its own where it sets all its relevant x's & y's to be the correct value.

#### The code relies on virtual functions. Could the code have been written without virtual functions?
I have a hard time imagining writing this program without using virtual functions.
My reasoning being that we need the dynamic table for virtual functions to have the matrix of pointers.
If we were able to create this program without having the matrix of pointers, then we probably do not need the virtual functions.

#### Could ChessPiece have been an abstract class?
Yes, I believe it could have been an abstract class. As we never actually create a specific object of the type ChessPiece.
We always create an object from one of its child classes.

#### There was no separate unit test for each function in this assignment, instead you tested several functions at once with different boards. What are the benefits and drawbacks for this kind of testing compared to unit tests?
I think that these kinds of tests are more abstract and looks at the bigger picture of the program.
Also with these sorts of tests you get to test how the system interacts with the rest of the system and where this can cause bugs.

#### What is the problem with a diamond inheritance?
That there is an ambiguity that shows up from having 2 inheritances that inherits from the same base class.
There are questions of which functions we should use from each.

#### Did you encounter any problem with protected member variables and, if so, how did you solve them?
I had three major problems:
* I couldn't access the text representations of the each piece so I created a print function so to pass the protected representations.
* I couldn't access the variable `isWhite` from another ChessPiece object so I created a superclass `validMove` that each class calls when it comes to that part where it needs to check if there is another piece and if it is white or not,
* A lot of my functions in Chessboard used a lot of the member functions from ChessPiece so I Made All of Chessboard, in other words the class itself, a friend of ChessPiece

#### Create a queen object and try to set the unnecessaryInt in ChessPiece. What happens?
What happens is that the program doesn't know which `unnecessaryInt` to set.
It will have option between taking the `unnecessaryInt` from `Rook` or `Bishop`, so it sends an error saying it is ambiguous which variable we mean.

#### Think about if it would be better if the queen had a bishop and a rock (as members) instead of inherited from them?
I think it would be better.
Because they would only be relevant when we need to call their respective `moves` methods and `validMove` function.
This would allow is to skip the problems that comes with the Diamond of death.

#### How many test boards will you need to be sure your functions work correctly?
I am not 100% sure. But I know for sure that to be 100% sure that it works correctly, you would have to try every possible combination.
However, that would take too long.
I used the tables given to use plus some more of my own. They were mostly tables with only one type to test each scenario they could be in and see that it is correct.
Then I also added a few more that I thought would be useful to test where there is a mix of pieces.
