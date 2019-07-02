# Solution for problem 448_Find_All_Numbers_Disappeared_in_an_Array

First test cases. We can just use the example in problem explanation.

```
Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]
```



We can easily propose a solution by using additional array.

Just create an array to record the numbers that have appeared in input array.

we know the integers in array are between 1 and n(n is the size of array). In the example the n is 8. So we create a new array with the size of 8.

`[0, 0, 0, 0, 0, 0, 0, 0]`

And go through the input, if it is zero, set the position to be -1. For instance, the first element is 4, so the array become

`[0, 0, 0, -1, 0, 0, 0, 0]` 

The 4th position is set to be -1.

Next, 3,

`[0, 0, -1, -1, 0, 0, 0, 0]` 

Next, 2,

`[0, -1, -1, -1, 0, 0, 0, 0]` 

And when things done,

`[-1, -1, -1, -1, 0, 0, -1, -1]`

At last, go through the array above, if the value is 0, record the index, in this example, they are 4, 5. So the missing number are 5 and 6.

The time complexity of this method is O(N). However we need space complexity O(N). Can we do it without extra space?

It seems a dilemma, since we need a same size array to record the number that appears. Wait, the same size array?

Can I use the original array, so I do not need additional space? Since we only need to know whether the number appears or not, a sign is enough.

So specifically, when a number appears, say 4, we make the corresponding position number in the original array to be negative. Say 7 is the 4th number in the array, so 7 is now -7. And after going through the array, the original array becomes

`[-4,-3,-2,-7,8,2,-3,-1]`

so the 5th and 6th number(8 and 2) is non negative, so 5and 6 are the answer to this example.

The space complexity is now O(1).