class Solution {
public:

    double solve(double x, long long n) {

        // base case
        if(n == 0)
            return 1;

        // even power
        if(n % 2 == 0) {
            return solve(x * x, n / 2);
        }

        // odd power
        return x * solve(x, n - 1);
    }

    double myPow(double x, int n) {

        long long N = n;

        if(N < 0) {
            x = 1 / x;
            N = -N;
        }

        return solve(x, N);
    }
};
