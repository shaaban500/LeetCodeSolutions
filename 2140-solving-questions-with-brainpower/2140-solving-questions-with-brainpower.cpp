class Solution {
public:
    
    int n;
    long long dp[100005];
    vector<pair<int,int>>a;
    
    long long solve(int i)
    {
        if(i >= n) 
            return 0;
    
        if(dp[i]!=-1) 
            return dp[i];
        
        int pts = a[i].first;
        int nxt = a[i].second;
        
        return dp[i] = max(solve(i+1), solve(i+nxt+1)+pts);
        
    }
    
    
    
    long long mostPoints(vector<vector<int>>& questions)
    {
        n = questions.size();
        for(int i= 0 ; i<n ; i++)
        {
            a.push_back({questions[i][0], questions[i][1]});
        }
        memset(dp, -1, sizeof dp);
        
        return solve(0);
    }
};




