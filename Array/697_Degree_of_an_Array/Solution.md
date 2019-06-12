# Solution for problem 697_Degree_of_an_Array

First look at the example. We should notice that the maximum frequency elements may not unique. For example ,

```
Input: [1, 2, 2, 3, 1, 2, 1]
Output: 5
Explanation: 
The input array has a degree of 3 because both elements 1 and 2 appear three times.
Of the subarrays that have the same degree:
[2, 2, 3, 1, 2]
The shortest length is 5. So return 5.
```

First, we need to find the degree, then look at the elements that appear exactly "degree" times. At last compute their intervals. 

So, how can we do this? Because the maximum frequency elements may not unique, so we can not just use a vriable to record it. So it seems we need to use some more advanced data structure. We may need `Hash Table` to store the information. And it is natural to let the keys to be the element, but how to design the value?

Let's think about what informations do we need. To get the degree of the array, we need the frequency of each element. For example in the above example, we need to know the frequency of element 1, 2, 3. And because we need to calculate the length, it is better to store the begin index and end index of that element in the array. There are many data structure that can represent that value in hash table. I use an array that has len 3. The first value in array represent the count of the element, the second element in array represent the begin index of that element, and the last element stands for the end index of the element.

For example, when we finish sweeping the array, what we have is a hash table that looks like this:

`<1, [3, 0, 6]>, <2, [3, 1, 5]>, <3, [1, 3, 3]>`

It means that `1` appears 3 times, start from index 0 and end in 6 of the array; `2` appears 3 times, start from 1 and end in 5; `3` appears only once and at index 3. The degree of the array is "3".

The next step is easy, we just check the element that has degree frequency, and use a tmp variable to record the minmum length of (end_index - start_index + 1).