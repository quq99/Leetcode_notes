# Solution for problem 670_Maximum_Swap

We are required to swap only once. All we need to do is to find the leftmost number in the given integer such that this number is smaller than the maximum number on the right hand of this number.

For example, 

99376825

let's pick 6 first, we can find that there is a number on the right of 6 and bigger than 6--we have 8. so 6 is good, however 6 is not the leftmost number that has such feature.

The left most number is 3, and the maximum number on the right of 3 is 8. 

9 is not, because there is no number on the right of 9 that is bigger than 9. so in this example we swap 3 and 8.

So, once we noticed this trait, we just traverse the number from right to left and keep the maximum number we have. Once we meet some number that is smaller than maximum we record the position and also record the maximum position we have now(for example, 3 and 8). So we need three variables: maximum position, the position of the leftmost number, when we meet a new leftmost number the current maximum position. For example, in the previous example 99376825 when we finish the traversing, maximum position is 0(point to number 9), leftmost position is 2(point to number 3), current maximum position is 5(point to number 8).