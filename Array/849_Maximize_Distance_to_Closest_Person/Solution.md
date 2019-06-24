# Solution for the problem 849_Maximize_Distance_to_Closest_Person

The edge case is [0]. You should return 1.

And you should consider the cases that begin with 0 or end with zero.

So, first get the first appears 1, and init `max_len` and position of 1 `pos1`.

Then, do the loop, from pos1 to end. each time when you meet a 1, check the `max_len` and update the `pos1`.

At last, if the array end with 0s, do not forget to check `max_len` and pos1 again. This step is very easy to forget.

For example, 

```c
Input: [0,1,0,0,0,1,0,1,0]
Output: 2
```

First, get `pos1` equals 1, and `max_len` equals 1.

then traverse from `pos1+1` to `end`. If 0, omit it.

until we reach 1, `i=5`, so we update `max_len=(i-pos1)/2 = 2`, and update `pos1 = i = 5`

Then continue, omit 0,

Next `i=7`, this time, `max_len` is bigger than `(i-pos1)/2`, so do not update `max_len`, just update `pos1=7`. 

Then continue, omit 0.

Because the array end with 0s, we need to do one more check. this time, `max_len` is bigger than `(i-pos1)/2`, so do not update `max_len`.

At last, return `max_len`.

Because we just traverse array once, the time complexity is O(N).