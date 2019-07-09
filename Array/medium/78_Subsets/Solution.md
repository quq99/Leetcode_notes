# Solution for problem 78_Subsets

This question also use backtracking. It is just consider or not consider the current number.

For the backtracking problem the point is to design the correct api for helper function. Generally, we need result, current tmp array, and info about candidate array. So in this problem are: result, current vector, array and the current index in array. 

And do not forget to reset the current vector after the recursive function. And I strongly recommend to do problem 39 combination sum and problem 79 word search. They are very similar and more difficult than this problem.