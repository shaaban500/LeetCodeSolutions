class Solution {
public:
    long long minimumRemoval(vector<int>& beans)
    {
        int n = beans.size();
        long long sum1, sum2;
        long long ans = 1e18;
        vector<long long> prefix(n + 1,0);
        
        prefix[n] = 1e18;
        prefix[0] = beans[0];

        for(int i = 1 ; i < n ; i++)
            prefix[i] = prefix[i - 1] + 1LL * beans[i];
        
        sort(beans.begin(), beans.end());

        for(int i = 1 ; i <= 100000 ; i++)
        {
            int  l = lower_bound(beans.begin(), beans.end(), i) - beans.begin();
            
            if(l == n) continue;
            
            sum1 = (l)? prefix[l - 1] : 0;
            sum2 = prefix[n -1] - sum1;
                        
            ans = min(ans, sum1 + sum2 - 1LL * i *(n - l));
        }
        
        return ans;
        
    }
};