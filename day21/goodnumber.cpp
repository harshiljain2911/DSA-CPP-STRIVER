class Solution {
public:

    long long MOD = 1e9 + 7;

    long long power(long long x, long long n) {

        long long ans = 1;

        while(n > 0) {

            if(n & 1) //(n & 1) -> condition for odd checking
            {
                ans = (ans * x) % MOD;
            }

            x = (x * x) % MOD;

            n >>= 1; // this means n= n/2
        }

        return ans;
    }

    int countGoodNumbers(long long n) {

        long long even = (n + 1) / 2;
        long long odd = n / 2;

        long long evenPart = power(5, even);
        long long oddPart = power(4, odd);

        return (evenPart * oddPart) % MOD;
    }
};
