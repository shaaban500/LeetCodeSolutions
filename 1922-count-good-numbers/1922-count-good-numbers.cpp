class Solution {
public:
    const long long mod = 1000000007;
    int countGoodNumbers(long long n) 
    {
        return power(4, n / 2, mod) * power(5, (n + 1) / 2, mod) % mod;
    }

    long long power(long long x, long long y, long long p)
    {
        long long res = 1;
        x = x % p;
        if(!x) return 0;

        while(y > 0)
        {
            if(y & 1) res = (res*x) % p;
            y = y >> 1; 
            x = (x * x) % p;
        }
        return res;
    }

};
