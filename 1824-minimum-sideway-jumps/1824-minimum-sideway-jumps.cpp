class Solution {
public:
    
    int n;
    vector<vector<int>> dp;
    vector<int> obstacles;

    int solve(int pos, int lane)
    {
        if(pos == n - 1)
            return 0;
        
        if(dp[pos][lane] != -1)
            return dp[pos][lane];
        
        if(obstacles[pos + 1] != lane)
        {
            return dp[pos][lane] = solve(pos + 1, lane);
        }
        
        int l1 = 0, l2 = 0;

        if(lane == 1)
            l1 = 2, l2 = 3;
        else if(lane==2)
            l1 = 1, l2 = 3;            
        else
            l1 = 1, l2 = 2;

        if(obstacles[pos] == l1)
            return dp[pos][lane] = 1 + solve(pos+1, l2);

        else if(obstacles[pos] == l2)
            return dp[pos][lane] = 1 + solve(pos + 1, l1);

        else
            return dp[pos][lane] = 1 + min(solve(pos + 1, l1), solve(pos + 1, l2));

        return dp[pos][lane] = 0;
    
    }
    
    int minSideJumps(vector<int>& arr) 
    {
        n = arr.size();
        
        for(int i = 0 ; i < n ; i++)
            obstacles.push_back(arr[i]);
        
        dp.resize(obstacles.size() + 1, vector<int>(4, -1));
        
        return solve(0, 2);
    }
};