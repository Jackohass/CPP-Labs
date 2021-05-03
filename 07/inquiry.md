# Inquiry
## Answers
#### In what order are the mapitems printed?
It is printed in decreasing order of weights, which are the keys for the map.
But as it looks it also seems to be in decreasing order for the values, which is useful for the greedysolution 1.

#### What is the underlying data structure std::map uses?
According to [cplusplus.com](https://www.cplusplus.com/reference/map/map/) the underlying data structure is usually a _binary search tree_.

#### Which is the first knapsackweight where the second greedy solution is better than the first?
The first knapsackweight where the second greedy solution is better is when the knapsackweight is 30,
then the first solution is better for 32.
However, at 34 the second solution is better again.
It seems to switch between which one is better.

#### What is the difference between a std::set and a std::map?
Elements are stored in key-value pairings.
So a map can have multiple identical values, while a set can't.
Values in a map can be modified, while a set's values can't be modified once added to the set.

#### What is the difference between a std::set and a std::unordered_set?
A set is ordered in increasing order, unless specified to be something else.
The set is usually implemented as a self balancing Binary search tree, while the unordered_set is usually implemented as a hashtable.
As the set is usually implemented as a binary search tree, the search time is log(n) while the unordered_set search time is on average O(1), but worst case is (n).
The insertion/deletion times are the same respectively, except that the set will sometimes have to rebalance its binary search tree so it is balanced.

#### Find five knappsack values where the optimal solution is equal to greedy solution 1
They have same values when the knappsackweight is:
* 38
* 37
* 36
* 25
* 24

#### Find five knappsack values where the optimal solution is equal to greedy solution 2
They have same values when the knappsackweight is:
* 35
* 34
* 30
* 52
* 51
