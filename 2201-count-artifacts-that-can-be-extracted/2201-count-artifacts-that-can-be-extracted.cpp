class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig)
    {
        int ans = 0;
        bool digged[n][n];
        memset(digged, 0 ,sizeof digged);
        
        for(int i = 0 ; i < dig.size() ; i++)
        {
            int x = dig[i][0];
            int y = dig[i][1];
            digged[x][y] = 1;
        }
        
        for(int i = 0 ; i < artifacts.size() ; i++)
        {
            int r1 = artifacts[i][0];
            int c1 = artifacts[i][1];
            int r2 = artifacts[i][2];
            int c2 = artifacts[i][3];
            
            bool full = 1;
            for(int r = r1 ; r <= r2 ; r++)
                for(int c = c1 ; c <= c2 ; c++)
                    full &= digged[r][c];
                
            ans += full;
        }
        
        return ans;
    }
};