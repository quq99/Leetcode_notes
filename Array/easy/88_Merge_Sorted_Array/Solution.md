# Solution for problem 88_Merge_Sorted_Array

First we notice the problem explaination:



> You may assume that *nums1* has enough space (size that is greater or equal to *m* + *n*) to hold additional elements from *nums2*.



We can get two important informations. First, we have to do in-place sort on *nums1*. Second, the time complexity is O(N) and space complexity is constant. Third, the ending part of *nums1* is all zeros.

Because we may move the elements in *nums1* to the end part of *nums1*, if we compare from the start element of *nums1*, and insert the element of *nums2* into *nums1*, we may have to move all the element behind that element. So in that case we can not solve it in O(N).

So the question became, how can be reduce the movement in *nums1*. we noticed the ending part (from index m to index m+n-1, suppose index start from 0) are all zeros. And it provides a good tmp memory for us! And here is the point, let's change the direction! Let's do it from end to start in *nums1* and compare the bigger element first! 

For example, 

```
Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]
```

We need a pointer to indicate where we are now, let's call it `tar`. we will use '' to indicate the tar pointed element.

we first compare 3 and 6, then 6 is bigger, `tar` is last one, `tar=5`. now nums1 became 

`[1,2,3,0,0,'6']`

then we compare 3 and the nums2's second last element 5, 5 is bigger,  `tar` is second last one, `tar=4`

`[1,2,3,0,'5',6]`

next, compare 3 and 2, 3 is bigger,  `tar` is `tar=3`

`[1,2,3,'3',5,6]`

Now, compare 2 and 2, so we will move 2 to `tar=2`

`[1,2,'2',3,5,6]`

because *nums2* is done, we can end the process and return *nums1*.