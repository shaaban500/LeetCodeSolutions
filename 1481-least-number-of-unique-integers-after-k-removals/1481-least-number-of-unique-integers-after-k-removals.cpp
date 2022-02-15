class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) 
    {
        map<int,int>mp1,mp2;
        
        for(int i=0 ; i<arr.size() ; i++)
            mp1[arr[i]]++;
        
        
        vector<int>v;
        for(auto it : mp1)
            v.push_back(it.second);
        
        sort(v.begin() , v.end());
        
        int i = 0;
        while(i<v.size() && k>=v[i]) k -= v[i++];
        
        
        return v.size()-i;
    }
};