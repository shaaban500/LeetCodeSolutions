class Solution {
public:
 
    string s;
    const int mod = 1e9 + 7;
    int dp[100005], n;
    
    int countTexts(string pressedKeys) 
    {
        s = pressedKeys;
        n = pressedKeys.size();
        memset(dp, -1, sizeof dp);
        return solve(0);
    }
    

    int solve(int i)
    {
        if(i == n)
            return 1;
        
        int &ret = dp[i];
        if(ret != -1) 
            return ret;
        
        int sz = (s[i] == '7' || s[i] == '9') ? 4 : 3;
        ret = 0;
        for(int j = i ; j < i + sz && j < n ; j++)
        {
            ret += solve(j + 1);
            ret %= mod;
            if(j + 1 < n && s[j] != s[j + 1])
                break;
        }

        return ret;
    }
};
