# Solution for problem 414_Third_Maximum_Number

It is really easy to draw a method using three variables to store three maximum number. And update the number when traversing the array. Specifically, 

* when the number is bigger than maximum number, update three number(nums[i] to first, first to second, second to third); 

* when the number is bigger than the second maximum number, update two number(nums[i] to second, second to third); 

* when the number is bigger than the third maximum number, update one number(nums[i] to third); 
* when the number is equal to maximum or second maximum number, omit it.



The key point of this problem is to handle edge cases.

Here is an example

```c
Input: [1, 2, INT_MIN, INT_MIN]

Output: INT_MIN
```



I use a `count` variable to count the times of updates. But in this example, when we meet `INT_MIN`, we also need to increase `count` and only increase it once.

The rest is simple, please look at the `.cpp` code.