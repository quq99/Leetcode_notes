# Solution for problem 167_Two_Sum_II_Input_array_is_sorted

We have already know "Two Sum". In this problem, the array is sorted, and

> You may assume that each input would have *exactly* one solution and you may not use the *same* element twice.

So, we do not need to check the input size. 

Then, we need to pay attension to the property of the input array-- It is sorted! So how can we utilize this feature?

we need to find two indexs, so this remind us to use two pointers. And we noticed that if we move one of the pointer to the next element, the sum will increase. While to the previous element, the sum will decrease. Good! So next, how do we choose the start point?

Let's consider the normal case we have to consider subarray `array[i,j]`, and we have pointer i and j in index i and j. There are two cases(we ignore the case that i and j is the answer), sum of array[i] and array[j] is bigger than target number and sum of array[i] and array[j] is smaller than target number. 

Case 1: if sum of array[i] and array[j] is bigger than target number. then if we fix j, any index on the right of i will not work, because thay will be greater than the sum of array[i] and array[j]. So we just need to move j left. and then consider subarray `array[i,j-1]`.

Case 2: if sum of array[i] and array[j] is smaller than target number. then if we fix i, any index on the left of j will not work, because thay will be smaller than the sum of array[i] and array[j]. So we just need to move i right and then consider subarray `array[i+1,j]`.

So, in the begining, i is 0 and j is sizeof(array)-1.

Because we only have to sweep the array once, the time complexity is O(N).

Example,

`Input: numbers = [2,7,11,15], target = 9`

First, `i=0, j=3`, 2+15 is bigger than 9, so `j=j-1`,

`i=0,j=2`,2+11 is bigger than 9, so again `j=j-1`

`i=0,j=1` now 2+7=9, ok.





Another way is to fix one index at one point and use binary search to find the other index.

```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int len = numbers.size();
        if (len < 2) return {};
        for (int i = 0; i < len-1; i++) {
            // each time fix left index as i
            // and use binary search to find the right index
            int l = i + 1;
            int r = len - 1;
            while (l <= r) {
                int mid = l + ( r - l) / 2;
                int remain = target - numbers[i];
                if (numbers[mid] == remain) return {i+1, mid+1};
                else if (numbers[mid] < remain) {
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }
        }
        return {};
    }
};
```



The run time is O(NlogN).