# Solution for problem 34_Find_First_and_Last_Position_of_Element_in_Sorted_Array

This problem is a mutation problem of binary search. Middle, left and right are the index.

In this case, when nums[middle] equals to the target number, we should do some minor change. Take the first position of element for example, if element at `middle - 1` position is smaller than the target or middle is 0, it means the current number(nums[middle]) is the first position of element. Else, because the array is already sorted, the nums[middle-1] is equal to the target, we should consider the left half array. The Last position of element is similar. 

So this problem is teaches us how to make a change to the original algorithm. we need to know that the only difference is the original algorithm when nums[middle] == target we return, but in this problem we need to continue or return. So first figure out in what cases we should return then the rest case we just continue(left = middle+1 or right = middle - 1). 

Another way is to devide the cases into left==right and left != right two categories. And when left== right consider return, but this case you should consider more edge cases and easy to make fault, which is not recommended.