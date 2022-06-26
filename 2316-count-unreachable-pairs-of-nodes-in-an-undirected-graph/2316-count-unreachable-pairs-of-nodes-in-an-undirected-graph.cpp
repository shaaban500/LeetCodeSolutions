class Solution {
public:
    int sz = 0;
    bool vis[100002];
    vector<int>size;
    vector<vector<int>> v;
    
    long long countPairs(int n, vector<vector<int>>& edges) 
    {
        v.resize(n);
        for(int i = 0 ; i < edges.size() ; i++)
        {
            int x = edges[i][0];
            int y = edges[i][1];
            v[x].push_back(y);
            v[y].push_back(x);
        }
        
        for(int i = 0 ; i < n ; i++)
        {
            if(!vis[i])
            {
                sz = 0;
                DFS(i);
                size.push_back(sz);
            }
        }
    
        long long ans = 0, sum = 0;
        sort(size.begin(), size.end());
        for(int i = 0 ; i < size.size() ; i++)
        {
            sum += 1LL * size[i];
            ans += 1LL * (1LL * n - sum) * 1LL * size[i];
        }   

        return ans;
    }
    
    void DFS(int n)
    {
        sz++;
        vis[n] = 1;
        for(int i = 0 ; i < v[n].size() ; i++)
        {
            if(!vis[v[n][i]])
                DFS(v[n][i]);
        }
    }
    
};