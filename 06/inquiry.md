# Inquiry
## Answers
#### What did you learn in this assignement?


#### What is a capture list in a lambda expression?


#### What does & mean inside the capture list?


#### When could capturing data by reference [&] be useful?


#### What does {4} in the code below do?
```
        A * p = new A {4} ;
```

#### Why is it a compile error to call foo with a unique_ptr without a move?
```
        foo(pa);
```

#### Was there ever a memory leak when calling foo2 with a shared pointer?
I never had a memory leak when I didn't use move and when I use it. I have the output files to show that it didn't detect any leaks:
* [Without move](valgrind-smartpointersNoMove.txt)
* [With move](valgrind-smartpointersWithMove.txt)

#### What is the use of a weak_ptr?


#### How do you create a unique_ptr with a special deleter?


#### What is _decltype_ ?


#### What is std::function?

