class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) 
    {
        vector<pair<int,int>>v(values.size());
        
        for(int i = 0 ; i < values.size() ; i++)
        {
            v[i].first = values[i] + i;
            v[i].second = values[i] - i;
        }
        
        int mxVj = INT_MIN;
        int mxAns = INT_MIN;
        
        for(int i = v.size() - 1 ; i >= 0 ; i--)
        {
            if(i <= v.size()-2)
                mxAns = max(v[i].first + mxVj , mxAns);
               
            mxVj = max(v[i].second , mxVj);
        }
        
        return mxAns;
    }
};