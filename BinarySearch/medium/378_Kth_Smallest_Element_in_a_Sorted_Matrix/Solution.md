# Solution for problem 378_Kth_Smallest_Element_in_a_Sorted_Matrix

The key point for any binary search is to figure out the "Search Space". For me, I think there are two kind of "Search Space" -- index and range(the range from the smallest number to the biggest number). Most usually, when the array is sorted in one direction, we can use index as "search space", when the array is unsorted and we are going to find a specific number, we can use "range".

The reason why we did not use index as "search space" for this problem is the matrix is sorted in two directions, we can not find a linear way to map the number and its index.

The next is the condition, it is easy to figure out that when the range is the smallest to the biggest element in the 2D array, the condition should be the number of elements which is smaller than the middle element in our binary search.  If the number is smaller than k, then we increase lower bound, else decrease upper bound util we find the exact number that is equal to k. Then the middle number is what we need. And because it is sorted. we can use the following code to calculate it.

```c++
for(int i = 0; i < matrix.length; i++) {
     while(j >= 0 && matrix[i][j] > mid) j--;
     count += (j + 1);
}
```

