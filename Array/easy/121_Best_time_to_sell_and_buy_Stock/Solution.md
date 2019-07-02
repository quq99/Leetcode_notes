# Solution for problem 121_ Best_Time_to_Buy_and_Sell_Stock

First, test case. We just use the test case provided by leetcode



```
Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.
```



From the example we know that this problem does not want you to just get maximum and minimum value and subtract them. In this example, the output is 5, and you can not just subtract 7 and 1. It is because in this problem you have to buy before sell. 

After some thinking, we can easily know that we have to know two value, the buy value `min_val` and the sell value `max_val`.

And I think the point of this problem is behind the fact "you have to buy before sell". So we noticed the sell time is behind the buy time. And we want to buy at a low price and sell at a high price. So, it is clear. We just do it step by step, each time we meet with a lower price, we reset both `min_val` and  `max_val`. Also we need a tmp value to record the output we have. 

So, in this example, first, we initialize  `min_val` and  `max_val` to be the value of first element 7 and tmp value to be `max_val - min_val`. Then we sweep the array, the next element is 1, so it is smaller than `min_val`, we reset  `min_val` and  `max_val` to be the value of 1. Then the next is 5, so we have new `max_val`, and we update `max_val = 5`, now we need to calculate tmp, it is `5-1=4` and is bigger than the previous tmp, so we again update tmp to be 4. Next, we have the element 3, now, 3 is not a new minimum or maximum, so we skip it. Next, we have 6, 6 is bigger than `max_val`, so we update `max_val=6` and `max_val - min_val = 6-1=5`, it is bigger than 4, so we update tmp to be 5. The last is 4, and is not a new minimum or maximum, so we skip it. 

Note, sometimes we update `max_val`, it does not mean the tmp will always be updated. Because when we have new `min_val` we will reset the max and min value. So we have:



```c
res = max(res, max_val - min_val)
```

 

Because we trace the array once, the time complexity is $O(N)$.

