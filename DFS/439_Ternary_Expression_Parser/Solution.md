# Solution for problem 439_Ternary_Expression_Parser

The input is guarranteed to be valid, so there is no edge cases.

Because we are going to parser nested ternary expressions, we can consider using recursive method. (actually there is a algorithm simply just using stack which is really cool, I will illustrate it latter).

Although we can nest ternary expression to get more complicated one, the basis of expression are still the same. That is to say, the expression still contain three parts: condition ? Exp1 : Exp2. So the idea of recursion method is straightforward: check out the "?" and then using Exp1 or Exp2 as the new input string. If Exp1 is just a single character this method works well. However, if Exp1 is an expression, it might be hard to find the right position of ":". So we need to do some modification.

Continue with the thought above, I was think about the next best thing. How about only dealing with `Exp1 is single character rather than expression`, and if it is not, we just store the information and using recursion to deal with substrings. So let us take an example to think about it in detail. Let's take example 3.

```c
Input: "T?T?F:5:3"

Output: "F"

Explanation: The conditional expressions group right-to-left. Using parenthesis, it is read/evaluated as:

             "(T ? (T ? F : 5) : 3)"                   "(T ? (T ? F : 5) : 3)"
          -> "(T ? F : 3)"                 or       -> "(T ? F : 5)"
          -> "F"                                    -> "F"
```

So, first we have `T?T?F:5:3` , first character is `T`, followed with `?`, so store the T, and put Exp1 and Exp2 into next recursion.

Then take `T?F:5:3`, Exp1 is not a single character, because the second character is "?" rather than ":". So store T, and put Exp1 and Exp2 into next recursion.

Then take `F:5:3`, Exp1 is a character, we can deal with is now.  now look at what we have stored, they are TT. Take one of then which is T, then we need the Exp1, it is "F", so return F.

Ok, from this example we know we need an additional stack to store T or F. Next let us consider more complex example.

 ```c
Input : "F?T:F?T?1:2:F?3:4"
Output : "4"
 ```

First character is `F`, followed with `?`, so stack is |F |(right side is top), put Exp1 and Exp2 into next recursion.

Then take `T:F?T?1:2:F?3:4`, Exp1 is a single character, pop stack, get F, so put Exp2 into next recursion.

Then take `F?T?1:2:F?3:4`, Exp1 is not a single character, because the second character is "?" rather than ":". So store F, stack is now | F |, and put Exp1 and Exp2 into next recursion.

Then take `T?1:2:F?3:4`, similar to previous step, push T to stack, stack now | F T |, put Exp1 and Exp2 into next recursion.

Then take `1:2:F?3:4`, Exp1 is a single character, pop stack to get T, so we get 1 and get rid of 2, then the rest is 1 and F?3:4, concat then.

Then take `1:F?3:4`, Exp1 is a single character, pop stack to get F, so put Exp2 into next recursion. The rest is simple and I would skip them.

Now we know when Exp1 is a single character, we can pop stack to get F or T. If we get F, just put Exp2 into the next recursion. If we get T, the operation would be a little bit tricky, because we need to find Exp2 and get rid of it and then concat Exp1 with the rest string. In the example above, `1:2:F?3:4`. Exp2 is "2", but what if it is an expression like `T?T?F:5:3` how can we recognize and extract it? Because we notice that the ? and : appear as pairs, so we just use a `count` variable, init to be `1`, when meet `?` , `count++`, when meet `:`, `count--`. When `count==0` it means we find the first `:` after Exp2. 

Because we just sweep the array once, the time complexity is O(N).