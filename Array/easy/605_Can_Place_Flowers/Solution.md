# Solution for problem 605_Can_Place_Flowers

So basically if there are 3 continue 0s, it can place a flower.

The point of this problem is to find this principals. So the problem can be convert to find continue 3 zeros. 

And the other thing is considering the edge cases.

For example the front and the end, it only need two continue 0s to place a flower. 

And, if you have continue 0s (more than 3), how to reset the local count? The answer is to reset it to 1 rather than 0.

To better illustrate the progress, first look at some example,

Ex 1

```c
Input:
[1,0,0,0,0,0,1]
2

Expected: true
```

 Ex 2

```c
Input:
[0,0,1,0,1]
1

Expected: true
```

Ex 3

```c
Input:
[1,0,0,0,1,0,0]
2

Expected: true
```



So we have a global variable `count` to count the number of flowers we can plant into the Can. And `tmp_count` to count the 0s we meet, if we already meet 3 continue 0s, we reset the `tmp_count` and `count++`. 

 In Ex 1, when we are at the situation `tmp_count==3`, we need to reset `tmp_count` to be 1 and count++, In Ex2 the first 2 0s can put in a flower, so we should init the `tmp_count=1`. Also in Ex 3, it means when we end with the loop, we need to check the `tmp_count` if it is 2, it means we end in 2 continue 0s, `count++`.

So to wrap up, First we have two variables, and we need to sweep the array once. Second, the `tmp_count` should be initialize to be 1. Third, there are two cases, meet 1 or meet 0. If meet 0, then `tmp_count++`, if `tmp_count==3` we need to reset it to 1 and `count++`; If meet 1, then reset `tmp_count` to be 0.

The time complexity is O(N).

