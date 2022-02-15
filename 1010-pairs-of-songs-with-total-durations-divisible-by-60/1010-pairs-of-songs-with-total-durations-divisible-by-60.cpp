class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) 
    {
        vector<int>mp(60,0);
        int n=time.size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(mp[((60-time[i]%60)%60)])
            {
                count+=mp[(60-time[i]%60)%60];
            }
            mp[time[i]%60]++;
        }
        return count;
    }
};