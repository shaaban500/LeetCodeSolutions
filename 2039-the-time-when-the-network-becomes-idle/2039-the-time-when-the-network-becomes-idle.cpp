class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& e, vector<int>& patience) 
    {
            int n = patience.size();        
            vector<vector<int>>edges(n + 1);
            for(int i = 0 ; i < e.size() ; i++)
            {
                int x = e[i][0];
                int y = e[i][1];
                edges[x].push_back(y);
                edges[y].push_back(x);
            }
        
            queue<pair<int,int>>q;
            int vis[100001] = {};
            int dist[100001] = {};
            vis[0] = 1;
            q.push({0,0});

            while(!q.empty())
            {
                int node = q.front().first;
                int time = q.front().second;
                q.pop();

                for(int i = 0 ; i < edges[node].size() ; i++)
                {
                    int child = edges[node][i];
                    if(!vis[child])
                    {
                        vis[child] = 1;
                        dist[child] = time + 1;
                        q.push({child , time + 1});
                    }
                }
            }
        
        int mx = -1;
        for(int i=1 ; i<n ; i++)
        {
            cout << dist[i] << " ";
            int totDist = (dist[i]*2);
            
            int totGo = (totDist - 1) / patience[i];
            int remTotGo = totDist - totGo * patience[i];
            int tot = 2 * totDist - remTotGo;
            
            
            mx = max(tot , mx);
        }
        return mx+1;
    }
};