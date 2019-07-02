# Solution for problem 1002_Find_Common_Characters

This is a good problem, it teaches us how to transfer the problem into what we know.

First pay attention to the explaination in the problem statement.

> return a list of all characters that ***show up in all strings*** within the list **(including duplicates)**. 

So the problem actually want us to get the intersection of all the strings.

Since the characters are all lowercase, we can use an array `arr` of size 26 to store the minimum frequency of characters in each element(string) in the input array. And because we want to know the intersection of all the strings in the input array, we also need a tmp array to store the local(for each string) information. After we trace each string, we store the frequency in the tmp array and update the `arr`. 

Once we have the `arr`, the rest is just a for loop.

For example, 

**Example 2:**

```
Input: ["cool","lock","cook"]
Output: ["c","o"]
```

we use `arr` as global array and `arr2` as the tmp array. They both have size 26 represent 26 characters in English.

First, "cool", the `arr2` became 

`[0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]`

`arr` is the same as arr2.

Next, "lock",  `arr2` became 

`[0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]`

then update  `arr` , for each element in `arr` 

`arr[i] = min(arr[i], arr2[i])`

 `arr` became 

`[0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]`

At last, "cook",  `arr2` became 

`[0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]`

So `arr` now became

`[0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]`

So we get "c" and "o". 



The time complexity is O(N).