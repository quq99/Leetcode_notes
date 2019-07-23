# Solution for problem 50_Pow_x_n

The idea is simple, we need to multiple x for n times. The brute force way is just multiple it on by one. However this method is not a good one, and it would cause too much time.

So can we go faster?

The core issue of this problem is how to manage these n times. Basically we have n steps to go, but we also noticed that there are many duplicate steps. For example, Pow(3, 10) multiple 3 for 10 times, we can devide them to some chunks, for example 2, 2, 2, 2, 2. Pair two 3 together, first get 3*3, them we have 9. and we just need to multiple 9 5 times. This is much shorter times of multiplications. And we can go further, because we can arrange 2,2,2,2,2 to 4,4,2. so 9\*9 is 81. Them we do 81\*81\*9, we can only have 3 times. So you are really close to the idea, right?

Yes, just cut the n into half size, and do it recursively. And the edge case is when n is 0, return 1. Then there are two cases, when n can be divided to two parts, return half size times half size. If can not be divided into two parts, then half size times half size times x.

Also, we can do it iteratively. we init tmp variable to be x, and count the multiple times. Each time we multiple itself and count times 2. If count exceeds the n, we times the tmp variable to our result, subtract n by count and restore tmp and count again, until n become 0.

For example, pow(2, 10)

n = 10, tmp = 2, count = 1. check count*2 with n, it is smaller than n. so count = count * 2 = 2. tmp times itself. tmp = 4. check count*2 with n, it is smaller than n. so count = count * 2 = 4. tmp times itself. tmp = 16. check count*2 with n, it is smaller than n. so count = count * 2 = 8. tmp times itself. tmp = 256. check count*2 with n, it is bigger than n. so update result = tmp, and n = 10 - 8 = 2.

Next, n = 2, tmp = 2, count =1. check count*2 with n, it is smaller than n. so count = count * 2 = 2. tmp times itself. tmp = 4. check count*2 with n, it is bigger than n. so update result = result * tmp = 1024. And n is 0. end loop



Because each time we devide into 2 part, so T(N) = 2T(N/2) + O(1). so time complexity is O(logN).

