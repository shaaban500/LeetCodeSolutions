class Solution {
public:
    int minSideJumps(vector<int>& a) 
    {
        int n = a.size();
        vector<vector<int>> next(4, vector<int>(n, n - 1));
        
        for(int i = n - 2 ; i >= 0 ; i--)
        {
            for(int j = 1 ; j < 4 ; j++)
                next[j][i] = next[j][i + 1];
            
            if(a[i]) next[a[i]][i] = i;
        }  
        
        int cur = 2, ans = 0;
        for(int i = 0 ; i < n - 1 ; i++)
        {
            if(a[i + 1] == cur)
            {
                ans++;
                int dist1 = next[1][i];
                int dist2 = next[2][i];
                int dist3 = next[3][i];
                if(cur == 1) cur = dist2 > dist3 ? 2 : 3;
                else if(cur == 2) cur = dist1 > dist3 ? 1 : 3;
                else cur = dist1 > dist2 ? 1 : 2;
            }
        }
        
        return ans;
                
    }
};