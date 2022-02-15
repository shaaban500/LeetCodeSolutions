class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        
        int n = speed.size();
        
        vector<int>v;
        for(int i=0 ; i< n; i++)
        {
            int t = dist[i]/speed[i] + (dist[i]%speed[i]!=0);
            v.push_back(t);
        }
        
        sort(v.begin(),v.end());
        
        for(int i=0 ; i<n ; i++)
        {
            if(v[i]-i<=0) return i;
        }
        return n;
        
    }
};