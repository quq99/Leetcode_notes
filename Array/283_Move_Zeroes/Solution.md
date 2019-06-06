# Solution for problem 283_Move_Zeroes



Because you have to do it in-place, so the easiest way to do it is by swapping the elements. To achieve this, you need a pointer to indicate all the non zero element, and each time when you find a non zero element, swap it to the pointer's position, and then move the pointer to the next place. In this way, you can ensure each time when you move, the current position is a non zero element, and because you will sweep the whole array, so every element is in the right place.

For example, 

```Input: [0,1,0,3,12]```

Pointer initialize to 0 index, we use '' to indicate the pointer's position.

`['0',1,0,3,12]`

then we sweep the array from begining to end. First 0, skip, next 1, ok, 1 is non zero element, swap it

`['1',0,0,3,12]`

move pointer to next position.

`[1,'0',0,3,12]`

Then 0, skip. 

Then, 3, ok, swap

`[1,'3',0,0,12]`

move pointer to next position.

`[1,3,'0',0,12]`

Then, 12, ok, swap

`[1,3,'12',0,0]`

And move pointer to next position.

`[1,3,12,'0',0]`

Because we have already sweep all the elements in array, so we are done.

The time complexity is O(N).