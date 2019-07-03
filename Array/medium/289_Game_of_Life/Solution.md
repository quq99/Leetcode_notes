# Solution for problem 289_Game_of_Life

We need to do it in-place. But if we update the current value, it will influent other elements. So actually we have to store the new value in some where. And we noticed the value is only one bit, so we consider using another bit to store it. 

Specifically, when we traverse the array, if we think the new element in current position is  1, we put this 1 in the second last bit and after finishing the traverse, just shift each element to 1 bit.

To put 1 in the second last bit, we can 

> board\[i][j] |= 2

because 2 is represent as 10 in binary format.

The time complexity is O(MN).