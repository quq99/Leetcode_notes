# Solution for problem 1_Two_Sum



First, test case. notice to check the input array size, if it is smaller than 2, we can not find the results.

In this problem, it is straightforward to get a brute force solution. We just at each time pick one element and check all the elements after the picked one, if we find two elements add up to the value of target value, then we push these two into a vector and return.

The time complexity of this method is $O(n^2)$. And we are not satisfied with this solution. Since we have to check all the elements in the array, theoretically we can not be faster than $O(n)$. So, we may ask, if we can find out a solution that has time complexity of $O(n)$? How do we find that?

So if the time complexity is $O(n)$, this means each time when we deal with an element in the given array, we only do constant operations. And this means we need to save some information about the array elements. How can we find a element in constant time complexity? Hash Map! So we sacrifice the memory complexity to get a faster algorithm.

OK, we can easily see we can sweep the array first and store the element in the hash map, <the_value_of_the_element, the_index_of_the_element>. 

For instance, if we have an array [2, 7, 11, 15] and the target number is 9. The hash map will be: <2, 0>, <7, 1>, <11, 2>, <15, 3>. Then, we sweep the array again. This time we can use the information in the hash map to find the indices of that two numbers. We first at 2 of [2, 7, 11, 15], we calculate remain to be 9-2=7, so we check if 7 is in the hash map. And it is. we look at the hash map, the index of element 7 is 1, and the index of element 2 is 0. so we add 0 and 1 to the return vector.

In this algorithm, we have to sweep the array twice in the worst case. The time complexity is $O(n)$ and space complexity is also $O(n)$. The next question is, can we be faster?

The answer is yes. 

So how can we be faster? The next question is, can we sweep the array only once? 

If the answer is yes, how can we do that?

We want to just sweep once and we also want to push the information into hash map. So we only can push the information into hash map when we sweep the array. To be specific, we use the same example as above.

First,  at 2 of [2, 7, 11, 15], we calculate remain to be 9-2=7, so we check if 7 is in the hash map. And it is not, so we push <2, 0> into hash map. Then we go on. Next we at 7 of [2, 7, 11, 15], we calculate remain to be 9-7=2, so we check if 2 is in the hash map, and it is. so we save the index of 2 and 7 in the return vector. 

We can see in this algorithm, the time complexity is $O(n)$ and we only need to sweep the array once in the worst case.

One last question, does this algorithm guaranteed to find the solution if there exists a solution? Suppose we are at the $i_{th}$ elements of the array(we call it nums[i]), and suppose nums[i] is one of the elements that can add up to the target value. Suppose the other one is nums[j] at $j_{th}$ of the array. $i, j \in [0, length\_of\_array-1]$. If j is smaller than i, then we have <nums[j], j> already in the hash map, so we can find the solution. If j is bigger than i, then this time we will add <nums[i], i> into the hash map and continue sweeping. When we at position j,  <nums[i], i> is already in hash map, so we can still find the solution. So, we are done^_^

 