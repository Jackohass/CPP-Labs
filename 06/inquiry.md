# Inquiry
## Answers
#### What did you learn in this assignement?
In this assignment I learnt about about lambda functions, memory handling, weak_ptr & unqiue_ptr.
I also learnt about concurrency in C++ and with it mutex, conditional variables and threads.

#### What is a capture list in a lambda expression?
The capture list defines what variables that are accessible inside of the lambda function.
I imagine it as a list of parameters for a normal function.

#### What does & mean inside the capture list?
It means that the variable is passed as a reference, which means we can change the value of the variable in the list inside of the lambda function.

#### When could capturing data by reference [&] be useful?
When you want to change the value of a variable that is outside of the function, inside of the function.
An example could when we maybe want to make a lambda function for the Binary tree nodes in lab 0t.

#### What does {4} in the code below do?
```
        A * p = new A {4} ;
```
It means that we set the integer inside of the struct `A` to be 4.
If it is the struct used for the smartpointers exercises then it would specifically mean that we are setting the data field to be 4.

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
So in a way it can be used to track other objects and also be used for objects that are accessed only if it exists, 
as it may be deleted at any moment outside our scope.
It can also be used to break reference cycles that are formed from objects managed by shared_ptr:s.

#### How do you create a unique_ptr with a special deleter?
By creating a lambda function and passing it to the constructor when you create the unique_ptr.
You can also create the lambda function in the passing of the function.
Like so:
```C++
unique_ptr<B, function<void(B*)>> pb1(new B[2], [](B* p)
{
	delete[] p;
});
```

#### What is _decltype_ ?
It is to declare the type of a variable from an expression.
It is used to declare types that are impossible or hard to declare from standard notation.

#### What is std::function?
It is a class template for general functions.
So you can store most functions in this class and it is very useful when working with lambda functions.

### Concurrency
#### What is [this] in the lambda function sent to the condition_variable's wait-method? Why is [this] needed?
`this` is a pointer to the object that you are in when you are inside of one of its methods.
It is needed in this particular circumstance so we can access its data members `gnusInside` & `hyenasInside` inside of the lambda function where we check if they are zero or not.

#### Why is the lock a local variable? What happens when the variable goes out of scope?
The lock is a local variable so when the lock goes out of scope it will call the destructor.
And when it calls the desctructor (ie when it goes out of scope) it will release ownership of and unlock the mutex we passed to it, if it owned it.

#### What is the difference between [unique_lock](http://en.cppreference.com/w/cpp/thread/unique_lock) and [lock_guard](http://en.cppreference.com/w/cpp/thread/lock_guard)
A unique_lock can be unlocked and locked, whilst a lock_guard is locked in the constructor and unlocked in the destructor.

#### Do the integers _hyenasInside_, _gnusInside_ need be [atomic](http://en.cppreference.com/w/cpp/atomic/atomic)?
Yes they have to be atomic.
We need them to be atomic so that they can handle having multiple threads trying to access and change the variable.
Atomic handles this.

#### Describe how .wait and .notifyall() works. Is any call blocking, and what does blocking mean?
`wait` works in the way that it blocks the thread until the conditional variable is notified.
And even if it is notified it might still block because we can specify a condition to be met before it stops blocking.
It gets notified through `notifyall()` and `notifyone()`.
Notifyall works in the way that all conditional_variables that are waiting on the same conditional_variable that we are notifying from will awake,
and if their condition is met (if supplied) will stop blocking.
Blocking means that the thread will put on a list of threads that are waiting to be notified from the same conditional_variable.
A blocked thread will not move, nor execute any instructions.

#### Write code that iterates over an unordered_map and prints each key and value
```C++
for(const auto& n : map ) {
	std::cout << "Key:" << n.first << " Value:" << n.second << "\n";
}
```

#### When printing an unordered_map, why is the items not printed in the order they were inserted?
Because that is how unordered maps are defined.
They use hashing methods depended on the key for the order rather then the order that they were inserted.
The values are organized into buckets, where the hash of the key decides which bucket it goes in.

#### In what order would the items be printed if a map was used instead of an unordered_map?
Its order depends on the keys of the map.
In the case of keys of the type int, it would be in increasing order.

#### How did you implement turning on/off trace outputs? Compile time, runtime or both? Ellaborate over your decision
I decided that you can turn it on/off as an argument when you execute the program.
How I implemented it in code is a bool value that we set true or false depending on the argument we sent when started the program.
This bool is stored in WaterManager class and we have an if statement infront of all the traces.
Now this isn't the most fastest solution to the problem, but it was the one I could do the fastest considering the reallife time constraints I had.
Another method I could have used are conditional inclusion to decide which parts it should compile.

#### What information did you print out in your trace output from the watercave? Ellaborate over your decision
I did not add more trace output than in the example as I felt it was sufficient.

#### Do you prefer initializing your thread with a function or function object (functor)
I think depends on the circumstances.
In this situation I think I prefer initializing with a normal function as I didn't feel a need to encapsulate it like you can do with a functor.
