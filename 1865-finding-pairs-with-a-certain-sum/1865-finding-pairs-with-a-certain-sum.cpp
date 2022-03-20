class FindSumPairs {
public:
    
    map<int,int> mp;
    vector<int> a, b;
    
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) 
    {
        int n = nums1.size();
        int m = nums2.size();
        
        for(int i = 0 ; i < n ; i++)
            a.push_back(nums1[i]);
        
        for(int i = 0 ; i < m ; i++)
        {
            mp[nums2[i]]++;
            b.push_back(nums2[i]);
        }
    }
    
    void add(int index, int val) 
    {
        mp[b[index]]--;
        b[index] += val;
        mp[b[index]]++;
    }
    
    int count(int tot) 
    {
        int ans = 0;
        // a + b = tot
        // tot - a = b
        for(int i = 0 ; i < a.size() ; i++)
            ans += mp[tot - a[i]];
        
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */