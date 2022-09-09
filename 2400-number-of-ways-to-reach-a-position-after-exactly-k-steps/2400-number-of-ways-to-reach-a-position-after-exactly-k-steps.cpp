class Solution 
{
public:
    int dp[1001][1001][2];
    int end, allSteps, start, mod = 1e9 + 7;
    int numberOfWays(int startPos, int endPos, int k) 
    {
        memset(dp, -1, sizeof dp);
        allSteps = k;
        end = abs(endPos - startPos);
        start = startPos;
        return solve(0, 0, 0);
    }
    
    int solve(int i, int st, bool minus)
    {
        if(st > allSteps)
            return 0;
        
        if(st == allSteps)
        {
            return i == end && !minus;
        }
        
        if(dp[i][st][minus] != -1)
            return dp[i][st][minus];
        
        int ret = 0;
        i = minus ? -i : i;
        int next = i + 1;
        int prev = i - 1;
        ret = solve(next < 0 ? -next : next, st + 1, next < 0 ? 1 : 0) + 
              solve(prev < 0 ? -prev : prev, st + 1, prev < 0 ? 1 : 0);

        return dp[minus ? -i : i][st][minus] = ret % mod;
    }
};