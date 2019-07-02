# Solution for problem 747_Largest_Number_At_Least_Twice_of_Others

This problem is quite simple, just find the largest one and the second largest one, and compare these two numbers.

One tricky point is to omit the equal numbers. For example, `[2,2,2]` should return 0. because the biggest number is 2, and there is no other different numbers. so return the first 2's index which is 0.

So, specifically we need two variables(`first` and `second`) to store the largest number and second largest number, and a variable(`index`) to store the index of largest number. After traversing the array, check whether the largest number is at least twice as much of the second largest number.

For example. 

`[1,2,3,4]`

At first, `first=array[0] = 1` and `second = INT_MIN`. `index = 0`.

Next, 2 is larger than `first`, so `first = 2, second = 1, index = 1`.

Next, 3  is larger than `first`, so `first = 3, second = 2, index = 2`.

Next, 4  is larger than `first`, so `first = 4, second = 3, index = 3`.

Check, `first` is smaller than twice of `second`, so return -1.