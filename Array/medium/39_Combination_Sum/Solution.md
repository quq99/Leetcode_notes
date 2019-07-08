# Solution for problem 39_Combination_Sum

When I do this problem, I encounter two problem, first is that this problem is different from TwoSum or ThreeSum problem which can be solved using two pointers. In this problem, the elements in the candidate array can be used unlimited times. The second problem is the solution set must not contain duplicated combinations. One way is to use set and each time when we push the combinations into the set we first sort them. This way, however, is so time consuming. 

Ok, for the first problem, how to solve this problem. We noticed that the candidate array's element can be used unlimited times, this is a challenge for us, but it is also a hint. We may use some recursive method to solve it and each time we decrease the target number until it is 0. So we can easily come up with a method using DFS or backtracking. 

Next, for the second problem, do we have to look up each element in the candidate array . if we sort the candidate array first and do the recursive part not from the first element in the candidate array but from the element we have now, we would not have duplicate combinations, because we ensure the combinations are at ascending order.