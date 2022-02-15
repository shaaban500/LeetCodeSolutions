class Solution {
public:
    
    double solve(double x, long long n)
    {
        if(n == 0) return 1;
        
        double res = solve(x, n / 2);
        
        if(n & 1) return res * res * x;
        else return res * res;
    }

    double myPow(double x, long long n) 
    {
        if(n >= 0) return solve(x, n);
        else return 1.0 / solve(x, -n);
    }
};