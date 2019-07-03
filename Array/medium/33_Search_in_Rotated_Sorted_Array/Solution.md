# Solution for problem 33_Search_in_Rotated_Sorted_Array

If the array is not rotated, we would use binary search algorithm to solve it. The problem explaination says we should do it in O(logN) time, so we may consider using binary search. However, the rotated array makes the cases more complicated.

I think the point of this problem is to devide the problem into categories. The condition would be more complex than the original one.

So because we use the binary search. First is to find the middle index. and update the left or right index recursively. So because the array is rotated, the middle number. could be larger or smaller to the left number. Initially, left index is 0 and right index is length-1.

1. if the middle number is larger or equal to the left most number in subarray.

we check the target number. If it is larger than middle number, the target could be in the right half array. If it is less than middle number but larger than or equal to left number, the target could be in the left half array. If it is smaller than left number, the target could be in the right half array.

2. If the middle number is smaller than the left most number in subarray.

we check the target number. If it is bigger or equal to left number, the target number could be in the left half array. if it is smaller than the middle number, the target number could be in the left half array. if it is bigger than the middle number and smaller than the right number, the target number could be in the right half array.



The difficulty of this problem is to deal with the edge cases and edge conditions appropriately. This needs practice and no short cut way. 

The time complexity is O(logN).