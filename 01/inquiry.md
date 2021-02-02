# Inquiry

Write your answers below and include the questions. Do copy relevant code to your answers so that both questions and answers are in context 

## Answers:
### g++ compiler questions
#### Where can you find the manual to g++?
On this page: https://gcc.gnu.org/onlinedocs/
You could also use the "man" command in the command line.

####  What is the purpose of _-Wall_ and _-g_, when passed as arguments to _g++_?
* With -wall we enable all warning messages from the compiler, this should usually always be passed for better code.
* With -g we compile the code with debug information, also a good practice to pass to g++.

#### What is the difference between an object file, and an executable?
- An object file can't be executed and isn't linked.

#### What in the example above is a forward declaration?
`struct B;`

#### Why is it not possible to have class A containing a B object and B containing an A object? 
Because then the class structure is based on A that then is based on B that is then based on A... and so on.
It wouldn't be able to compile as the class A would need the structure of B defined above, but B would need also need class A's structure defined above too.


### Hello world questions
#### What is the purpose of _std::cout_, _std::cerr_, and _std::clog_, respectively?
* cout is to print out to standard out (stdout).
* cerr is to print out to standard error (stderr).
* clog is to print out logging information and can be tied to the 2 others (stdlog)).

#### How does #include work?
It includes the source file it names into the current source file where the line "#include" is written.'


### unit test questions
#### Why is it important to test the boundary conditions of an implementation, especially in the case of _count_if_followed_by_?
So we are safe from off-by-one and such problems. There can also be unexpected behaviours when we send the boundary values, that might not actually crash the program.
In this test we won't crash because of the off-by-one value because the last element in a char array is a null character which is readable.   

#### Describe how your testcase tests if a pointer is accessing an element outside the range specified
test2: We check if we only look at the first 3 which should return 1, if had looked at all 4 we then it should return 2. As the function returns 2 we see that it might be counting the 4th character.
testO: Is a similar test, but if  we only look at the first 3 it should return 0.
test4: Here we check all 4 places in the data and should return 4, I used this test to see if it does check one array too much if it would cause it to have an unexpected behaviour.
test0: To check if does return 0 when the array we send in is empty and we check 0 elements.
test1: In this test we look for the specific case if does count in the null character when it looks at the whole data array.