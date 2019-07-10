# Solution for problem 695_Max_Area_of_Island

The edge case is when size of array is 0. 

Then it is just a typical DFS problem, traverse the array, if find one, doing the DFS through four direction, and when meet an element, set it to 0. This problem is very typical, so it can be used to training your fundamental knowledge about algorithms.

Because you will traverse the array once, if row size is M and column size is N, then time complexity is O(MN).

