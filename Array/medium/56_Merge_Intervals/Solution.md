# Solution for problem 56_Merge_Intervals

The edge case is when the length of vector smaller than two, just return the input itself.

A brute force way is to use two for loop to traverse the array, fix one element and see if the rest can combine with it. This method has time complexity of O(N^2).

Can we do faster?

So for a interval, it has two properties, the begin time and the end time. So how about sorting according to the begining time first and then look at the ending time. The sorting time complexity is O(NlogN). Now let's look at two intervals, `in1` and `in2` and in1 has smaller begining time. When will these two intervals need to combine? Yes, in1 end after in2 begin! So we just check if the end of in1 is bigger or equal to the begining of in2.

We also need two variables to store the current merged intervals. Let's say `left` and `right`. So for example,

```c
Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
```

We first sort the input, then left=1 and right=3. Then traverse the array from the second element.

Next is [2,6]. because right is bigger than 2, combine them, update `right = max(right, 6)=6`, keep going,

Next is [8,10]. Because right is smaller than 8, so do not combine it, we can push back the current left and right to the result variable. Then update the left = 8 and right = 10.

Next is [15, 18]. Right is smaller than 15, so do the same thing as before, push back the current left and right to the result variable. Then update the left = 15 and right = 18.

At last, there is one element remains, so push back the current left and right to the result variable. Done.



The time complexity of the traverse is O(N), and the sorting is O(NlogN), so the time complexity is O(NlogN).