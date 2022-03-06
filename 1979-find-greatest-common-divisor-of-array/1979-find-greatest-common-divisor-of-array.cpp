class Solution 
{
public:
    int findGCD(vector<int>& v) 
    {
        int n = v.size();
        int mn = 1e9, mx = -1e9;
        for(int i = 0 ; i < n ; i++)
        {
            mn = min(v[i], mn);
            mx = max(v[i], mx);
        }
        return __gcd(mn, mx);
    }
};