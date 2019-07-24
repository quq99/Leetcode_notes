# Solution for problem 1011_Capacity_To_Ship_Packages_Within_D_Days

Similar as
875. Koko Eating Bananas
876. Minimize Max Distance to Gas Station



This problem, we first give a range, and check if the middle is satisfy some condition, them update the range. 

In this problem, 

The range is the maximum element in the array and the sum of the array. 

The condition is whether we can ship package in D days is we set capacity to middle of this range. To calculate the condition, we just use a for loop and update the count number when size is exceed middle, and reset the sum.