# Solution for problem 243_Shortest_Word_Distance

First look at the example, the word1 and word2 may appears several times. Let's make an example,

```c
[0, 0, 1, 1, 2, 2, 1, 0, 0, 2, 0, 1]
```

0 represent other words, 1 stands for word1 and 2 for word2.

a straightforward way is to store all position of 1 and 2, and use two for loop to calculate their distance. However this is not a beautiful solution. Can we do it faster, can we do it by just sweep the array once?

We may need two variable to indicate the index of word1 and word2 each time we meet one of them. And each time when we meet one of them, we update index of that variable and calculate the distance of two indexs. We also need another variable to store the minimum value of the distances we have calculated so far. 

The point of this method is each time we meet a new word1 or word2 and we update the corresponding index, we can guarantee the other index is the biggest one we have. This can give us the local optimal.

For example, I use `index1` and `index2` for word1 and word2's positions. I use '' to indicate where we are when go through the array.

```c
['0', 0, 1, 1, 2, 2, 1, 0, 0, 2, 0, 1]

index1 = -1, index2 = -1
min_val = INT_MAX
```



```
[0, '0', 1, 1, 2, 2, 1, 0, 0, 2, 0, 1]

index1 = -1, index2 = -1
min_val = INT_MAX
```



```
[0, 0, '1', 1, 2, 2, 1, 0, 0, 2, 0, 1]

index1 = 2, index2 = -1
min_val = INT_MAX
// we haven't meet a word2 yet,
// so do not update min_val
```



```
[0, 0, 1, '1', 2, 2, 1, 0, 0, 2, 0, 1]

index1 = 3, index2 = -1
min_val = INT_MAX
```



```
[0, 0, 1, 1, '2', 2, 1, 0, 0, 2, 0, 1]

index1 = 3, index2 = 4
min_val = 1
```



```
[0, 0, 1, 1, 2, '2', 1, 0, 0, 2, 0, 1]

index1 = 3, index2 = 5
min_val = min(1,2) = 1
```



```
[0, 0, 1, 1, 2, 2, '1', 0, 0, 2, 0, 1]

index1 = 6, index2 = 5
min_val = 1
```



```
[0, 0, 1, 1, 2, 2, 1, '0', 0, 2, 0, 1]

index1 = 6, index2 = 5
min_val = 1
```



```
[0, 0, 1, 1, 2, 2, 1, 0, '0', 2, 0, 1]

index1 = 6, index2 = 5
min_val = 1
```



```
[0, 0, 1, 1, 2, 2, 1, 0, 0, '2', 0, 1]

index1 = 6, index2 = 9
min_val = min(3, 1) = 1
```



```
[0, 0, 1, 1, 2, 2, 1, 0, 0, 2, '0', 1]

index1 = 6, index2 = 9
min_val = 1
```



```
[0, 0, 1, 1, 2, 2, 1, 0, 0, 2, 0, '1']

index1 = 11, index2 = 9
min_val = min(2, 1) = 1
```



The time complexity is O(N).