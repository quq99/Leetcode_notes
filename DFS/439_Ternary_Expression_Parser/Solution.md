# Solution for problem 439_Ternary_Expression_Parser

The input is guarranteed to be valid, so there is no edge cases.

Because we are going to parser nested ternary expressions, we can consider using recursive method. (actually there is a algorithm simply just using stack which is really cool, I will illustrate it latter).

Although we can nest ternary expression to get more complicated one, the basis of expression are still the same. That is to say, the expression still contain three parts: condition ? Exp1 : Exp2. So the idea of recursion method is straightforward: check out the "?" and then using Exp1 or Exp2 as the new input string.  