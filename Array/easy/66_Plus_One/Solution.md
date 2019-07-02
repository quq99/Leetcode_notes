# Solution for problem 66_Plus_One

It is easy to create some test cases.

For example, normal cases like `234`, end with 9 `239`, and all 9 `999`.

So like we often do in math, we calculate from low bits to high bits, when the last bit is 9, we set it to 0 and consider the second last one, and repeat it until the number is not 9. If all the numbers are 9, we need to add a additional 1 to the beginning.

So when everything done, the example become `235`, `240`, `1000`.

The idea of this problem is to divide the cases into three categories.

The time complexity is O(N).