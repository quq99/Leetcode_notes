// TaskScheduler.cpp

#include<vector>
#include<algorithm>
using std::vector;
using std::max;

class TaskScheduler {
    public:
        int leastInterval(vector<char>& tasks, int n) {
            if (tasks.size()==0 || n==0) return tasks.size();
            int count[26] = {};
            int maxCount = 0; // number of most frequent task in tasks
            int n_sameMax = 0; // if the task that has maxCount is not unique, count the number
            for (auto task: tasks) {
                count[task-'A']++;
                if (maxCount == count[task-'A']) {
                    n_sameMax++;
                }
                else if (maxCount < count[task-'A']) {
                    maxCount = count[task-'A'];
                    n_sameMax = 1;
                }
            }

            // AB? ? ? AB ? ? AB ? ? AB
            int emptySlot = maxCount - 1;
            int tasksNeedToManage = emptySlot * (n + 1) + n_sameMax;
            return max((int)tasks.size(), tasksNeedToManage);

        }
};
