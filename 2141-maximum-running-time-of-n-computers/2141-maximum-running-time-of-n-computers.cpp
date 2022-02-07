class Solution {
public:
    bool check(vector<int>& a, long long mid, long long n)
    {
        long long sum = 0;
        for(int i = 0 ; i < a.size() ; i++)
            sum += min(mid , 1LL * a[i]);
        
        return (sum >= mid * n);
    }
    
    long long maxRunTime(int n, vector<int>& batteries) 
    {
        long long sum = 0;
        for(int i = 0 ; i < batteries.size() ; i++)
            sum += 1LL * batteries[i];
        
        long long l = 0, r = sum / n, ans = 0;
        
        while(l <= r)
        { 
            long long mid = (l + r) / 2;
            if(check(batteries, mid, n))ans = mid, l = mid + 1;
            else r = mid - 1;
        }
        
        return ans;
    }
};