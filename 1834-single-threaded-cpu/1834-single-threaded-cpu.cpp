class Solution 
{
public:
    vector<int> getOrder(vector<vector<int>>& tasks) 
    {
        vector<int>ans;
        int n = tasks.size();        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >pq;


        for(int i = 0 ; i < n ; i++)
            tasks[i].push_back(i);

        sort(tasks.begin(), tasks.end());
        
        int i = 0;
        long long curTime = 0;
        
        while(ans.size() < n)
        {
            while(i < n && tasks[i][0] <= curTime)
            {
                pq.push({tasks[i][1], tasks[i][2]});
                i++;
            }
            
            
            if(!pq.empty())
            {
                int mnTime = pq.top().first;
                int mnIdx = pq.top().second;
                pq.pop();
                ans.push_back(mnIdx);
                curTime += 1ll * mnTime; 
            }
            else
                curTime = 1ll * tasks[i][0];
        }
        
        return ans;
        
    }
};