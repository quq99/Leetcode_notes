# Solution for problem 55_Jump_Game

I want to convert this problem to a better understanding and interesting one.

Say a rabbit, it want to reach the destination. At each step, it will lose 1 energy(need to eat one carrot). Luckly, at each step there are some carrots(non negative number of carrots). It can choose to what it has or it can collect the carrots(but have to give up what it has), that is to say at each step the carrots it has is `max(already_have, the_carrots_at_that_step)`. If the carrots it has is 0, it can not get to next step, because each step it will loss 1 carrot. 

Does that makes this problem simple?

we have a variable `remain` record the number of carrots the rabbit has. initially `remain` is 0. traverse the array from 0 to second last element. If the carrots is smaller or equal to 0, then return false.

For example. 

[0,2,3]

First, element is 0, remain--, remain = max(remain, 0)=0, stop, return false.

[2,3,1,2]

First, element is 2, remain--, remain = max(remain, 2)=2, 

Next,element is 3, remain--, remain = max(remain, 3)=max(1,3)=3,

Next,element is 1, remain--, remain = max(remain, 2)=max(2,1)=2,

because 2 > 0, so return true.