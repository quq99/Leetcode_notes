// Pow.cpp

// iterative
class Pow1 {
    public:
        double myPow(double x, int n) {
            long long N = n;
            if (N < 0) {
                x = 1 / x;
                N = -N;
            }
            long count = 0; // count will times 2, int may overflow.
            double tmp = x;
            double res = 1;
            while (N > 0) {
                tmp = x;
                count = 1;
                while (count << 1 <= N) {
                    tmp = tmp * tmp;
                    count <<= 1;
                }
                res *= tmp;
                N -= count;
            }
            return res;
        }
};

// recursive
class Pow2 {
    public:
        double myPow(double x, int n) {
            long long N = n;
            if (N < 0) {
                x = 1 / x;
                N = -N;
            }
            return helper(x, N);
        }

        double helper(double x, long long N) {
            if (N == 0) return 1.0;
            double half = helper(x, N/2);
            if (N % 2 == 0) {
                return half * half;
            }
            else {
                return half * half * x;
            }
        }
};
