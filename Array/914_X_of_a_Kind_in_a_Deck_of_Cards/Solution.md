# Solution for problem 914_X_of_a_Kind_in_a_Deck_of_Cards

In this problem, we are given many cases. First, I think about using a hash map to store the frequency. I choose the smallest number and check other number's frequency to see if they are times of the smallest number, and the smallest number should be bigger than 2.

However, this method can not pass the example like `[1,1,1,1,2,2,2,2,2,2]`, we can devide it into `[1,1], [1,1], [2,2], [2,2], [2,2]`. But the method above will return false.

So, It seems we need to find the greatest common devide of the elements in hash map.

So, first create the hash map storing the element and its frequency. Second, traverse the frequency and find the greatest common devide. At last check this greatest common devide is bigger than 1.

For example, in the previous example, we have map `<1, 4> , <2, 6> ` , then take the frequency 4 and 6 calculate greatest common devide, it is 2. So check if 2 is greater than 1, yes, return true.



