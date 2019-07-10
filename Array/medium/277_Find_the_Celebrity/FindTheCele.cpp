// FindTheCele.cpp


// Forward declaration of the knows API.
bool knows(int a, int b);

class FindTheCele {
    public:
        int findCelebrity(int n) {
            if (n<=1) return n;

            int candidate = 0;
            for (int i=1; i<n; i++) {
                // 1. if i know the candidate, then i will not be celebrity
                // just continue
                // 2. if i do not know the candidate, then the candidate will not be
                // the celebrity, because everyone know the celebrity
                // for i itself, i may be celebrity so set i to be candidate
                // at last there is only one candidate
                if (!knows(i, candidate)) {
                    candidate = i;
                }
            }
            // check the candidate
            for (int i=0; i<n; i++) {
                if (i==candidate) continue;
                if (!knows(i, candidate) || knows(candidate, i)) {
                    return -1;
                }
            }
            return candidate;
        }
};
