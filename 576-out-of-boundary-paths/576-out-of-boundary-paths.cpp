class Solution 
{
public:

    int maxRows;
    int maxCols;
    int maxMoves;
    int mod = 1e9 + 7;
    int dp[60][60][60];
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) 
    {
        maxRows = m;
        maxCols = n;
        maxMoves = maxMove;
        memset(dp, -1, sizeof dp);
        return solve(startRow, startColumn, 0);
    }
    
    
    int solve(int row, int col, int numOfMoves)
    {
        
        if(!valid(row, col))
            return 1;
        
        if(dp[row][col][numOfMoves] != -1)
            return dp[row][col][numOfMoves];
        
        int sum = 0;
        
        for(int i = 0 ; i < 4 ; i++)
        {
            int r = row + dx[i];
            int c = col + dy[i];
            if(numOfMoves < maxMoves)
            {
                sum += solve(r, c, numOfMoves + 1);
                sum %= mod;
            }
        }
        
        return dp[row][col][numOfMoves] = sum;
    }
    
    
    bool valid(int row, int col)
    {
        return row < maxRows && row >= 0 && col < maxCols && col >= 0;
    }
    
};





















