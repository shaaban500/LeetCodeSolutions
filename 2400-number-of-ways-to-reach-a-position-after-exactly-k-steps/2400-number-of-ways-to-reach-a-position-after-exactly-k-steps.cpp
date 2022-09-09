class Solution 
{
public:
    int dp[1001][1001][2], target, allSteps, mod = 1e9 + 7;
   
    int numberOfWays(int startPos, int endPos, int k) 
    {
        memset(dp, -1, sizeof dp);
        allSteps = k;
        target = abs(endPos - startPos);
        return solve(0, 0, 0);
    }
    
    int solve(int i, int steps, bool minus)
    {
        if(steps > allSteps)
            return 0;
        
        if(steps == allSteps)
        {
            return i == target && !minus;
        }
        
        if(dp[i][steps][minus] != -1)
            return dp[i][steps][minus];
        
        i = minus ? -i : i;
        int next = i + 1;
        int prev = i - 1;
        int ret = solve(next < 0 ? -next : next, steps + 1, next < 0 ? 1 : 0) + 
                  solve(prev < 0 ? -prev : prev, steps + 1, prev < 0 ? 1 : 0);

        return dp[minus ? -i : i][steps][minus] = ret % mod;
    }
};