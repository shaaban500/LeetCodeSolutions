class Solution {
public:
    int maximumRows(vector<vector<int>>& mat, int cols) 
    {
        int n = mat.size();
        int m = mat[0].size();
        int mx = 0;
        
        for(int bits = 0 ; bits < (1 << m) ; bits++)
        {
            if(__builtin_popcount(bits) == cols)
            {
                int cnt = 0;
                for(int i = 0 ; i < n ; i++)
                {
                    bool ok = 1;
                    for(int j = 0 ; j < m ; j++)
                    {
                        if(mat[i][j])
                        {
                            if(!(bits & (1 << j)))
                                ok = 0; 
                        }
                    }
                    cnt += ok; 
                }
                mx = max(cnt, mx);
            }
        }
        return mx;
    }    

    
    
    
    
    
    
    
    
    
    
    
};