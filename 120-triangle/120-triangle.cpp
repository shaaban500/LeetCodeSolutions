class Solution {
public:
    int dp[202][202];
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        memset(dp, -1, sizeof dp);
        return solve(0, 0, triangle);        
    }

    int solve(int i, int j, vector<vector<int>>& triangle)
    {
        if(i == triangle.size())
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        return dp[i][j] = min(solve(i + 1, j, triangle) + triangle[i][j], solve(i + 1, j + 1, triangle) + triangle[i][j]);
    }
    
};