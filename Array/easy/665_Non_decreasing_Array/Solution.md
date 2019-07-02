# Solution for problem 665_Non_decreasing_Array

First think about test cases, this is the tricky part of the question.

* Case 1: Non decreasing. For example, `[2, 3, 4]`

* Case 2: Need to decrease one element to be non-decreasing. eg. `[2, 5, 3, 4]`

* Case 3: Need to increase one element to be non-decreasing. eg.`[3, 1, 4, 5]`

* Case 4: Need to modify more than one element to be non-decreasing. eg. `[2, 5, 2, 4, 2]`



Once I devide the cases, the solution is not hard to get.

So we need a variable `count` to count the number of modifies. When we see an element that is smaller than previous element, `count++`. When count is bigger than 1 we have case 4, we can end the for loop. If we don't meet that element, we are in Case 1. So there left Case 2 and 3.

And now we would deal with the first time we see an element that is smaller than previous element, say the ith(Let's make i start from 0) element `array[i]`. If `i==1`, we just modify the first element to be equal to array[i]. If `i>=2`, we need to consider whether it is Case 2 or Case 3: if Case 2 happens, we need to modify `array[i-1]`, just let it equal to `array[i]`; if Case 3 happens, we need to modify `array[i]`, just let it equal to the previous element. So all Cases done. Then just `return count < 2;`

Because we only trace the array once, the time complexity is O(N).