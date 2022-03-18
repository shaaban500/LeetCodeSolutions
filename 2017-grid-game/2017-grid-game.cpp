class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) 
    {
        long long top = 0, down = 0;
        int n = grid[0].size();
        
        for(int i = 0 ; i < n ; i++)
            top += grid[0][i];
        
        long long ans = 1e16;
        for(int i = 0 ; i < n ; i++)
        {
            top -= grid[0][i];
            ans = min(ans, max(top, down));
            down += grid[1][i];
        }
        
        return ans;
    }
};