# Inquiry
## Answers
#### What did you learn from this assignment?
I learnt about memory handling and references.
I also learnt a lot about testing and especially testing how good ones algorithm is.

#### What was hardest to implement in this assignment?
The `remove` function.
I struggled with references there and where the pointers were pointing and why some of the nodes didn't get removed.
There was also a problem where some nodes didn't get deleted.

#### If the signature of _insert_ was changed like below, changing the key of _p_ would not have the desired effect, why is that?
```
void insert(Node * p, int key, double value) {   // reference to pointer removed
  if ( p == nullptr ) {
     p = new Node();
     p -> key = key;   // ???
     // ...
```
That is because of references.
We have the ability to change the value of the variable outside its definition like this because we have a reference.
But now that we have changed and it is no longer a reference, we don't actually change the variable outside this function.

#### Are you able to pass a value, such as 17, to a _const int & parameter_ ?
Yes we are able to.
What it means is that we can't change the value of `parameter` inside of the function, so it will *const*antly be 17 inside of the function.

#### How do you check if two objects are equal if they only have operator< and not operator==?
If they follow the same rules as numbers and the operator does indeed compare less than, then I believe you can check it in two conditions:

`!(a < b) && !(b < a)`

If neither is bigger than the other, nor are they smaller than the other, then it must mean they are equal to each other.

#### Does _a < b_ and _!(b < a)_ compare the same thing?
No they do not.
`a < b` only compares if a is smaller than b.
`!(b < a)` compares if they might be `a < b`, but also if they might be equal to each other (`a < b`). Where if it is either it will return true.
That means that `!(b < a)` compare the same thing as `a <= b`.

#### Write down data from your test runs
##### Tests according to instructions:
* Average height: 31.00
* Highest maximum height: 31
* Average minimum height: 1.00
* Lowest minimum height: 1
* Average difference between minimum and maximum height: 30.00
* Greatest difference between minimum and maximum height: 30
* Greatest difference between minimum and maximum height in the same tree: 30
* Lowest difference between minimum and maximum height: 30
* Lowest difference between minimum and maximum height in the same tree: 30

##### Improved tests:
* Average height: 29.81
* Highest maximum height: 40
* Average minimum height: 4.07
* Lowest minimum height: 1
* Average difference between minimum and maximum height: 25.74
* Greatest difference between minimum and maximum height: 39
* Greatest difference between minimum and maximum height in the same tree: 36
* Lowest difference between minimum and maximum height: 19
* Lowest difference between minimum and maximum height in the same tree: 20
