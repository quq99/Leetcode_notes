# Solution for problem 79_Word_Search

This problem want to find a route or a path that matches the given word.

It is easy to think about using DFS and backtracking method. First we need to find the first match character and get the position, then start with that character, we use DFS to the four direction, and check all the possible route.

So I need an additional function to check the route. I write a helper function. This function will call itself recursively. To use the recursive method, this function will first check the current character, if it satisfies it will call the recursive procedure of next four possible directions. The parameter of the helper function will have: 

> input matrix, 
>
> the word, 
>
> the index of current character in the word, 
>
> the position of the candidate character in input matrix(two parameters indicating row and column).

If the index is equal to the length of word it means we reach the end of the word so return true;

If the position is out of boundaries we return false

If the current character in the word is not equal to the candidate character in input matrix, it means this path failed, we also return false.

Then we check the rest of the word and call the function recursively.

Another thing we need to consider is when we check the current character and it meets the requirement, we need to mark it as read. Just change its value to some special character. But because we have recursive procedure, and we will do some backtracking, so each time when we return we want the input matrix be unchanged.

Because the helper function will change the values of the input matrix. First I think that for the parameter of input matrix, I don't use reference or pointer. But this will cause a problem of using too much memory because each time I call this helper function I have to copy the matrix. So I make a minor change in the helper function. When I note the current element to mark it as read, I make a copy of this character, and after call the recursive procedure and before return, I restore the current character to the original element. So in this way I can set the parameter to be reference of the input matrix which would save a lot of memory.



The worse case is to traverse every character in the input matrix, so time complexity is O(MN), M is row number, N is column number.