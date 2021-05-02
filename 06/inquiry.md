# Inquiry
## Answers
#### What did you learn in this assignement?
In this assignement I learnt about abou lambda functions, memory handling, weak_ptr & unqiue_ptr.
I also learnt about concurrency in C++ and with it mutex, conditional variables and threads.

#### What is a capture list in a lambda expression?
The capture list defines what variables that are accessible inside of the lambda function.
I imagine it as a list of parameters for a normal function.

#### What does & mean inside the capture list?
It means that the variable is passed as a reference, which means we can change the value of the variable in the list inside of the lambda function.

#### When could capturing data by reference [&] be useful?
When you want to change the value of the variable inside of the function.
An example could when we maybe want to make a lambda function for the Binary tree nodes in lab 05.

#### What does {4} in the code below do?
```
        A * p = new A {4} ;
```
It means that we set the integer inside of the struct `A` to be 4.

#### Why is it a compile error to call foo with a unique_ptr without a move?
```
        foo(pa);
```
Because the purpose of a unique_ptr is that it is sole owner and the only one that manages its object through a pointer,
that deletes this object when the unique_ptr goes out of scope.
To pass `pa` without move means that we would have 2 `unique_ptr`s which goes against the meaning of the class.
And even if we ignored that it would mean that the object managed by the 2 pointers would be deleted when the function `foo()` finishes, 
leaving the first unique_ptr to have nothing to manage.
So need to use `move()` so we move the ownership of the object to the unique_ptr inside of `foo()`.

#### Was there ever a memory leak when calling foo2 with a shared pointer?
I never had a memory leak when I didn't use move and when I use it. I have the output files to show that it didn't detect any leaks:
* [Without move](valgrind-smartpointersNoMove.txt)
* [With move](valgrind-smartpointersWithMove.txt)
However when I used the shared_pointer for the part of the assignment about weak_ptr's then it would get memory errors.
When I used move it would get problems.
```c++
foo2(move(sa));
weak_ptr<A> wa = sa;
cout << wa.lock()->data << endl;
```

When I didn't use move, it worked.
```c++
foo2(sa);
weak_ptr<A> wa = sa;
cout << wa.lock()->data << endl;
```

I think it is because `move()` "moves from" the passed object. So that would mean that in `move(sa)` that sa would be null after we moved it.
Which we see if we print out its value after we have called `move()`

#### What is the use of a weak_ptr?
To give temporary ownership of objects.
So in a way it can be used to track other objects and also be used to accessed only if it exists, 
as it may be deleted at any moment outside our scope.
It can also be used to break reference cycles that are formed from objects managed by shared_ptr:s.

#### How do you create a unique_ptr with a special deleter?


#### What is _decltype_ ?


#### What is std::function?

### Concurrency
#### What is [this] in the lambda function sent to the condition_variable's wait-method? Why is [this] needed?


#### Why is the lock a local variable? What happens when the variable goes out of scope?

#### What is the difference between [unique_lock](http://en.cppreference.com/w/cpp/thread/unique_lock) and [lock_guard](http://en.cppreference.com/w/cpp/thread/lock_guard)

#### Do the integers _hyenasInside_, _gnusInside_ need be [atomic](http://en.cppreference.com/w/cpp/atomic/atomic)?

#### Describe how .wait and .notifyall() works. Is any call blocking, and what does blocking mean?

#### Write code that iterates over an unordered_map and prints each key and value

#### When printing an unordered_map, why is the items not printed in the order they were inserted?

#### In what order would the items be printed if a map was used instead of an unordered_map?

#### How did you implement turning on/off trace outputs? Compile time, runtime or both? Ellaborate over your decision

#### What information did you print out in your trace output from the watercave? Ellaborate over your decision

#### Do you prefer initializing your thread with a function or function object (functor)