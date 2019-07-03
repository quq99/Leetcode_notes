# Solution for problem 11_Container_With_Most_Water





Let's say the two pointers point to elements are `left` and `right`. Because we want to just sweep the array in O(N) time, an idea is let them start from the begining and end element and move them  towards the middle. And if we want to reduce the time from O(N^2) to O(N), there must exists some cases that we do not need to check given the status we have. So let's take an example to see if we can find some interesting properties.

 

![img](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/17/question_11.jpg)

The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.



First, pointers are in begining and end. `left=1 and right=7`. In the original method(O(N^2) method) we need to first fix `left` and traverse `right` from 7 to 8. and then check `left = 8 and right = 7` and do the similar things again. But wait, when left=1 and right=7, do we have to check `right` from 7 to 8? We know 7 is bigger than 1, when we move `right` from 7 to 8, because we take the minimum height of two numbers, it would not be bigger than 1, and the width is decreaing along with we move `right` from 7 to 8, so the product of width times minimum of two elements would not be bigger than what we get in  `left=1 and right=7`. So we just move `left` from 1 to the next number 8. This is the key point in this question. The point is we can reduce the unnecessary traverse by check the `left and right` values, and move the **smaller one** to the next/previous element. 

For example, in the example above

we use `max_v` to maintain the result and `current` store the current volume of water. `left and right` is the index(in the explaination above I use them as value). Array name is `A`.

First, left = 0 and right = 8. Current = (8-0) * min(A[left], A[right]) = 8 * 1 = 8, max_v = 8. A[left] is the smaller one, so increase left.

Next, left = 1 and right = 8. Current = (8-1) * min(A[left], A[right]) = 7 * 7 = 49, max_v = 49. A[right] is the smaller one, so decrease right.

Next, left = 1 and right = 7. Current = (7-1) * min(A[left], A[right]) = 6 * 3 = 18, max_v = 49. A[left] is the smaller one, so decrease right.

Next, left = 1 and right = 6. Current = (6-1) * min(A[left], A[right]) = 5 * 8 = 40, max_v = 49. A[left] A[right] are equal so it does not matter, increase left.

Next, left = 2 and right = 6. Current = (6-2) * min(A[left], A[right]) = 4 * 6 = 24, max_v = 49. A[left] is the smaller one, so increase left.

Next, left = 3 and right = 6. Current = (6-3) * min(A[left], A[right]) = 3 * 2 = 6, max_v = 49. A[left] is the smaller one, so increase left.

Next, left = 4 and right = 6. Current = (6-4) * min(A[left], A[right]) = 2 * 5 = 10, max_v = 49. A[left] is the smaller one, so increase left.

Next, left = 5 and right = 6. Current = (6-5) * min(A[left], A[right]) = 1 * 4 = 4, max_v = 49. A[left] is the smaller one, so increase left. Left == right, done.

Max_v is 49.



We only traverse the array once, the time complexity is O(N).