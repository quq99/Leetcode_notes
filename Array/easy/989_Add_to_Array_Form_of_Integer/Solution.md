# Solution for problem 989_Add_to_Array_Form_of_Integer

This problem is very similar to problem 66 and problem 2. The point is to consider all the cases. Apart from the examples given in problem explaination, an example is K have more bits than array. So we need to check K and flag when we finish the loop. There are several possible ways to solve the problem.

The basic idea is similar to problem 66 and problem 2. We need to check the flag and each time devide K by 10. And from low bits to high bits. If the sum of current bits is larger than 9, we set flag to 1 and go to next bit. when we run out of K or array, we stop the loop. At last check the K and flag to see if we need more bits.

For example, 

```c
Input: A = [2,1,5], K = 1806
Output: [2,0,2,1]
```

At first, flag equals 0, from the low bit to high bit,

`5+6=11`, so `flag = 1` and the last bit is `11%10 = 1`. K is now `1806/10=180`

Next, `0+1=1` add flag `1+1=2`, so set this bit to `2`. Set `flag=0`. K is now `18`.

Next, `2+8=10`, so set this bit to `10%10=0` and `flag=1`. K is now `1`.

We run out of the A. End the loop.

Then check K and flag, if either of them is not 0, we need add bits to the top of our result. So K is 1 and flag is 1. add them `1+1=2` set new bit to `2`. Now flag is 0 and `K=1/10=0` so both them are 0, done. The result is `2 0 2 1`.



The time complexity is O(N). If K is really really large, then the final step--adding number to the top of array would be costly -- O(M^2) (M is length of K minus length of A). In that case, we can use an new vector, and push the number to its back, and after finishing it, reverse the vector. This method would cost addition space complexity, but time complexity is O(N).