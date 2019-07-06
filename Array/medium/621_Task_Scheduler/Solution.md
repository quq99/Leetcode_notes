# Solution for problem 621_Task_Scheduler



E.g. we have following tasks : 3 A, 2 B, 1 C. and we have n = 2. According to what we have above, we should first arrange A, and then B and C. Imagine there are "slots" and we need to arrange tasks by putting them into "slots". Then A should be put into slot 0, 3, 6 since we need to have at least n = 2 other tasks between two A. After A put into slots, it looks like this:



A ? ? A ? ? A
"?" is "empty" slots.



What comes next? should we care about other tasks? No, other tasks appear no more than A, so they are all in ?, and if there are remaining ?, we just put idle in it. How about the n is so small that we can put other task in ? and also left some tasks. In this case, we do not need idle, just add tasks to the end of A, so the result will be the size of tasks. So things done!



Here are the detail procedure:

- First count the number of occurrences of each element. Use array of size 26 to store.
- Let the max frequency seen be M for element E
- We can schedule the first M-1 occurrences of E, each E will be followed by at least N CPU cycles in between successive schedules of E
- Total CPU cycles after scheduling M-1 occurrences of E = (M-1) * (N + 1) // 1 comes for the CPU cycle for E itself
- Now schedule the final round of tasks. We will need at least 1 CPU cycle of the last occurrence of E. If there are multiple tasks with frequency M, they will all need 1 more cycle.
- Add the number of elements that all have M frequency cycle to result. we get `res`
- If we have more number of tasks than the max slots we need as computed above we will return the length of the tasks array as we need at least those many CPU cycles. Otherwise we let the idle to be the intervals. So return the `max(task.size(), res)`.



For example, if I have A and B appear 3 times, and n is 3. We do not need to care other numbers. The cpu cycles can be arranged as

A B ? ? A B ? ? A B

? is either idle or other task. we have 2 slots, each has n+1 tasks, and rest A and B at last. so the result is 2 * (3 + 1) + 2 = 10.



Time complexity is O(N).