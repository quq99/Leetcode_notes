# Solution for problem 277_Find_the_Celebrity

If `ith` column is all 1 and `ith` row is all 0(except [i,i] itself), then i is the celebrity. So we can easily find a O(N^2) algorithm, just traverse the 2D array, find the column that all 1(suppose it is ith column) and check the corresponding ith row.

Can we do it faster?

Suppose we want to find i. And we know the i is unique, so if we find some row that has 1 (except [i,i]), then this row can not be celebrity. So when we check the column, we can reject some row, for example, when we check column 0, we have [0, 0] is 1, [1, 0] is 1, [2, 0] is 1, then we know row 1(omit [1,1]) and row 2(omit [2,2]) has 1,  so they can not be celebrity. Suppose we check [0,0] to [i-1,0] are all 1 but [i, 0] is 0, ok now column 0 is done, it can not be celebrity, Next check column 1? No, we do not need to check column 1, why? Remember previously we reject row 1 and 2? so we can just omit them and start from i column and check from [i, i]. So follow this method, we just need to check N times and get one candidate, at last check the cadidate row and colum once. The total running time is O(N).

So having known the method, we can convert it to coding procedure.

* go through the 0 to n - 1, initial the candidate to be 0 and i from 1 to n-1.

1. if `i` know the candidate, then i will not be celebrity just continue.
2. if `i` do not know the candidate, then the candidate will not be the celebrity, because everyone know the celebrity. For `i` itself, `i` may be celebrity so set `i` to be candidate. At last there is only one candidate

* Traverse the 0 to n-1 again.

1. Check the candidate, if all the other people know him/her and he/she does not know others, return candidate; else return -1.