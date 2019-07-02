# Solution for problem 15_3sum

First edge case, length smaller than 3, return empty vector.

This problem is very similar to the "Two sum" problem. So we may think about using two pointers. And we think of converting this problem to the problem we are familiar with. The difference is now the target number is changing. This means we should traverse the array. So first sort the array, this will take O(NlogN). When we at array[i], first get the target number which is `-array[i]`, then for the subarray `array[i+1,..., length-1]`, use the same technique in "Two sum" problem. 

The next problem is we need to erase the duplication. This part is a little bit tricky. I first think of using a set structure in c++ to store the results, and at end copy the elements to an vector and return it. This is inefficient and time consuming. A better way is just omit the duplicated element in array. Specifically, when dealing with the subarray `array[i+1,..., length-1]` , jump the duplicate number, and at the outer loop, again jump the same target number. We can use while loop to do this.

Note that, then the target is smaller than 0(the current number is bigger than 0), because the array is already sorted, so the rest element can not add up to negative, so end the loop and return.

For example, 

```c
Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
```

Suppose the array name is `nums`.

First, sort the array, get `[-4, -1, -1, 0, 1, 2]`.

Then traverse the array. First `i = 0`,  target is `-nums[0] = 4`. suppose the two pointer are `left` and `right`. then left = i+1 = 1 and right = length-1=5. nums[1]+nums[5] is smaller to target. So next, left = 2. nums[left] is equal to the previous one, so jump to next element, left = 3, nums[3]+nums[5] is smaller to target, continue increasing left to 4, nums[4]+nums[5] is smaller to target, next left is increased to 5, then end this part.

Next, `i=1`, target is `-nums[1] = 1`. then left = 2 and right = 5. nums[2]+nums[5] is equal to target, so push back {nums[1], nums[left], nums[right]} to result variable. Ie {-1, -1, 2}. Then left increases and right decreases. Left = 3 and right = 4. nums[3]+nums[4] is equal to target, so push back {nums[1], nums[left], nums[right]} to result variable. Ie {-1, 0, 1}. Increase left and decrease right. end this part.

Next, `i=2`, target is `-nums[2] = 1` so ignore this part, jump to next i.

Next `i=3`, target is 0, left = 4 and right = 5. nums[4] + nums[5] is not equal to 0. Update right, end this part.

Next `i=4`, i is bigger than length - 3. so end loop.



The time complexity is O(N^2).