# Solution for problem 75_Sort_Colors

Let's look at the follow up. The first is simple. As for the second, we can use two pointers and swap then when encountering with 0 or 2. and update the pointer.



Suppose we have three pointers, points to current number--`curr`, rightmost 0--`p0` and leftmost 2--`p2`. 

The idea of solution is to move `curr` pointer along the array, if `nums[curr] = 0` - swap it with `nums[p0]`, if `nums[curr] = 2` - swap it with `nums[p2]`.

**Algorithm**

- Initialise the rightmost boundary of zeros : `p0 = 0`. During the algorithm execution `nums[idx < p0] = 0`.
- Initialise the leftmost boundary of twos : `p2 = n - 1`. During the algorithm execution `nums[idx > p2] = 2`.
- Initialise the index of current element to consider : `curr = 0`.
- While `curr <= p2` :
  - If `nums[curr] = 0` : swap `curr`th and `p0`th elements and move both pointers to the right.
  - If `nums[curr] = 2` : swap `curr`th and `p2`th elements. Move pointer `p2` to the left.
  - If `nums[curr] = 1` : move pointer `curr` to the right.



Attention! when nums[curr]==2, just move pointer `p2`, because we do not know the current pointer `curr` now is 0 or not, so we need to check it at next loop.