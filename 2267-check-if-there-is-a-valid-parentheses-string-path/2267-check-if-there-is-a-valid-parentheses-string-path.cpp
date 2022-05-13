class Solution 
{
public:
    int dp[100][100][200];
    bool hasValidPath(vector<vector<char>>& grid) 
    {
        memset(dp, -1, sizeof dp);
        return solve(0, 0, 0, 0, grid);
    }
    
    bool solve(int i, int j, int open, int closed, vector<vector<char>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int dif = open - closed;
        
        if(dif < 0)
            return false;
            
        if(i == n - 1 && j == m - 1)
        {
            dif = open + (grid[i][j] == '(') - closed - (grid[i][j] == ')');
            return (dif == 0);
        }
        
        if(i >= n || j >= m) 
            return false;

        if(dp[i][j][dif] != -1)
            return dp[i][j][dif];
        
        return dp[i][j][dif] = solve(i + 1, j, open + (grid[i][j] == '('), closed + (grid[i][j] == ')'), grid)
                            || solve(i, j + 1, open + (grid[i][j] == '('), closed + (grid[i][j] == ')'), grid);
    }
     
    
};