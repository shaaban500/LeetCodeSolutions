class Solution {
public:
    int solve(int pos, int lane, vector<vector<int>>& dp, vector<int>& obstacles)
    {
        if(pos == obstacles.size() - 2)
            return dp[pos][lane] = 0;
        
        if(dp[pos][lane] != -1)
            return dp[pos][lane];
        
        if(obstacles[pos + 1] != lane)
        {
            return dp[pos][lane] = solve(pos + 1, lane, dp, obstacles);
        }
        else
        {
            int l1 = 0, l2 = 0;
            
            if(lane == 1)
                l1 = 2, l2 = 3;
            else if(lane==2)
                l1 = 1, l2 = 3;            
            else
                l1 = 1, l2 = 2;
            
            if(obstacles[pos] == l1)
                return dp[pos][lane] = 1 + solve(pos+1, l2, dp, obstacles);
            
            else if(obstacles[pos] == l2)
                return dp[pos][lane] = 1 + solve(pos + 1, l1, dp, obstacles);
            
            else
                return dp[pos][lane] = 1 + min(solve(pos + 1, l1, dp, obstacles), solve(pos + 1, l2, dp, obstacles));
        }
        
    
        return dp[pos][lane] = 0;
    
    }
    
    int minSideJumps(vector<int>& obstacles) 
    {
        vector<vector<int>> dp(obstacles.size() + 1, vector<int>(4, -1));
        return solve(0, 2, dp, obstacles);
    }
};