# Solution for problem 532_K-diff_Pairs_in_an_Array  

Actually, there are two cases, k=0 and k>0.

* Case 1: when `k==0`, the problem can be transfered to find the elements that appear more than once.

* Case 2: when `k>0`, we need to check each element if there are other elements in the array such that their difference is k. Because pair(i, j) and pair(j,i) count as the same pair, we only need to consider if there exists other element in the array which is greater than the one we check by k.

There are many ways to do this. I use the `Hash Map`. 

First use a hash table to store the elements and their frequency.

Then, we track all the elements in the hash table. Note that as I explained above, we need to consider two cases, when k==0, we only to check if the frequency is bigger than 1; when k>0, we need to check if there is the corresponding element in the hash table.

So, take example 2 and example 3,

**Example 2:**

```
Input:[1, 2, 3, 4, 5], k = 1
Output: 4
Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).
```

The hash table would be:

`<1,1>, <2,1>, <3,1>, <4,1>, <5,1>`

The k is bigger than 0, we are in case 2.

First, `1`, check if `1+k = 1+ 1 = 2` is in the array, the answer is yes, so count++.

Then `2`, check if `3` is in the array, yes, so count == 2;

Next `3`, check if `4` is in the array, yes, so count == 3;

Next `4`, check if `5` is in the array, yes, so count == 4;

At last, `5`, check if `6` is in the array, no, so count ==4.



**Example 3:**

```
Input: [1, 3, 1, 5, 4], k = 0
Output: 1
Explanation: There is one 0-diff pair in the array, (1, 1).
```

The hash table would be:

`<1,2>, <3,1>, <4,1>, <5,1>`

The k is 0, we are in case 1.

just check if the frequency is bigger than 1.

First `1`, the map value(frequency) is 2, satisfy, so count == 1;

Then `3`, the value is 1, no, count ==1;

Next `4`, the value is 1, no, count ==1;

Finally `5`, the value is 1, no, count ==1;



The time complexity and space complexity are both O(N).