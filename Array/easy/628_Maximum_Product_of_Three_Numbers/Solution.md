# Solution for the problem 628_Maximum_Product_of_Three_Numbers

First look at the "Note":

> 1. The length of the given array will be in range [3,104] and all elements are in the range [-1000, 1000].
> 2. Multiplication of any three numbers in the input won't exceed the range of 32-bit signed integer.



It means we do not need to consider the input size invalid. And the `Int` is big enough for our product. What is more, we need to consider the negative number. 

So, all we need to do is to find the three biggest numbers and  two smallest numbers. Then compare `max1\*max2\*max3` with `min1\*min2\*max1`. (max1 is biggest and min1 is smallest)

Once we know this, the rest things are simple, we can either sort the array first or we can sweep the array and record those 5 numbers.

If we use sort method, the time complexity is O(nlogn); and if we sweep the array, the time complexity is O(N).