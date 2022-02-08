class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime)
    {
        int n = plantTime.size();
        vector<pair<int,int>>v;
        
        for(int i = 0 ; i < n ; i++)
            v.push_back({growTime[i], plantTime[i]});
        
        sort(v.begin(), v.end());
        
        int mxTime = 0;
        int lstTime = 0;
        
        for(int i = n-1 ; i >= 0 ; i--)
        {
            int nextTime = v[i].first + v[i].second + lstTime;
            lstTime += v[i].second;
            mxTime = max(nextTime, mxTime);                
        }
        
        return mxTime;
        
    }
};